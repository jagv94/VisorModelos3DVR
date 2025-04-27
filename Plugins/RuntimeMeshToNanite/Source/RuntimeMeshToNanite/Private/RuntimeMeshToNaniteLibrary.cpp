// Copyright (c) Adrián Guerra 2025. All rights reserved.

#include "RuntimeMeshToNaniteLibrary.h"
#include "StaticMeshAttributes.h"
#include "StaticMeshOperations.h"
#include "Engine/StaticMesh.h"
#include "Materials/Material.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Materials/MaterialInstanceConstant.h" // Añadido para UMaterialInstanceConstant
#include "AssetRegistry/AssetRegistryModule.h"
#include "Engine/Texture2D.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialExpressionConstant3Vector.h"
#include "Async/ParallelFor.h"
#include "PhysicsEngine/BodySetup.h"
#include "HAL/ThreadSafeBool.h" // Para CriticalSection

static FCriticalSection CriticalSection; // Definición de CriticalSection

#define NANITE_MIN_TRIANGLES 1000 // Umbral mínimo para activar Nanite

UStaticMesh* URuntimeMeshToNaniteLibrary::ConvertRuntimeMeshToNanite(
  const FModeldMaterialData& ModelData,
  const FString& MeshName,
  bool bEnableNanite,
  const FMeshNaniteSettings& NaniteSettings)
{
  if (!ModelData.bSuccess)
  {
    UE_LOG(LogTemp, Error, TEXT("Model data is not valid"));
    return nullptr;
  }

  if (ModelData.meshMatInfo.Num() == 0)
  {
    UE_LOG(LogTemp, Warning, TEXT("No mesh data found in model"));
    return nullptr;
  }

  // Crear el StaticMesh
  UStaticMesh* StaticMesh = NewObject<UStaticMesh>(
    GetTransientPackage(),
    FName(*MeshName),
    RF_Public | RF_Standalone | RF_Transient);

  if (!StaticMesh)
  {
    UE_LOG(LogTemp, Error, TEXT("Failed to create StaticMesh."));
    return nullptr;
  }

  // Configurar Nanite
  StaticMesh->NaniteSettings = NaniteSettings;
  StaticMesh->NaniteSettings.bEnabled = bEnableNanite && (GetTriangleCount(ModelData) >= NANITE_MIN_TRIANGLES);

  // Crear descripción de malla
  FMeshDescription MeshDescription;
  FStaticMeshAttributes Attributes(MeshDescription);
  Attributes.Register();

  // Procesar cada sub-malla
  for (const FMeshMaterialData& MeshData : ModelData.meshMatInfo)
  {
    if (MeshData.Vertices.Num() == 0 || MeshData.Triangles.Num() == 0)
    {
      UE_LOG(LogTemp, Warning, TEXT("Skipping empty mesh section: %s"), *MeshData.tMeshName);
      continue;
    }

    // Crear material (o usar uno por defecto si falla)
    UMaterialInterface* Material = CreateMaterialFromModelData(MeshData.fMaterialData);
    if (!Material)
    {
      Material = LoadObject<UMaterial>(nullptr, TEXT("/Engine/EngineMaterials/DefaultMaterial.DefaultMaterial"));
    }

    // Añadir sección de malla
    CreateMeshSection(StaticMesh, MeshData, 0, Material, MeshDescription);
  }

  // Finalizar malla
  StaticMesh->CreateMeshDescription(0, MoveTemp(MeshDescription));
  StaticMesh->CommitMeshDescription(0);

  // Configuración física
  StaticMesh->CreateBodySetup();
  StaticMesh->GetBodySetup()->CollisionTraceFlag = CTF_UseComplexAsSimple;

  // Construir y notificar
  StaticMesh->Build();
  StaticMesh->PostEditChange();

#if WITH_EDITOR
  FAssetRegistryModule::AssetCreated(StaticMesh);
#endif

  return StaticMesh;
}

TArray<UStaticMesh*> URuntimeMeshToNaniteLibrary::ConvertRuntimeMeshSectionsToNanite(
  const FModeldMaterialData& ModelData,
  const FString& BaseMeshName,
  bool bEnableNanite,
  const FMeshNaniteSettings& NaniteSettings)
{
  TArray<UMaterialInterface*> DummyMaterials;
  return ConvertRuntimeMeshSectionsToNaniteWithMaterials(ModelData, BaseMeshName, DummyMaterials, bEnableNanite, NaniteSettings);
}

TArray<UStaticMesh*> URuntimeMeshToNaniteLibrary::ConvertRuntimeMeshSectionsToNaniteWithMaterials(
  const FModeldMaterialData& ModelData,
  const FString& BaseMeshName,
  TArray<UMaterialInterface*>& OutMaterials,
  bool bEnableNanite,
  const FMeshNaniteSettings& NaniteSettings)
{
  OutMaterials.Empty();
  TArray<UStaticMesh*> GeneratedMeshes;

  if (!ModelData.bSuccess)
  {
    UE_LOG(LogTemp, Error, TEXT("Model data conversion was not successful"));
    return GeneratedMeshes;
  }

  if (ModelData.meshMatInfo.Num() == 0)
  {
    UE_LOG(LogTemp, Warning, TEXT("No mesh data found in model"));
    return GeneratedMeshes;
  }

  // Estructura para almacenar datos preparados en paralelo
  struct FPreparedMeshSection
  {
    FMeshDescription MeshDescription;
    FString MeshName;
    FMeshMaterialData MeshData;
    bool bSectionEnableNanite;
  };

  TArray<FPreparedMeshSection> PreparedSections;
  PreparedSections.SetNum(ModelData.meshMatInfo.Num());

  // 1. Preparación de datos en paralelo (operaciones thread-safe)
  ParallelFor(ModelData.meshMatInfo.Num(), [&](int32 Index)
    {
      const FMeshMaterialData& MeshData = ModelData.meshMatInfo[Index];
      FPreparedMeshSection& PreparedSection = PreparedSections[Index];

      if (MeshData.Vertices.Num() == 0 || MeshData.Triangles.Num() == 0)
      {
        UE_LOG(LogTemp, Warning, TEXT("Skipping empty mesh section: %s"), *MeshData.tMeshName);
        return;
      }

      // Preparar datos de la sección
      PreparedSection.MeshName = FString::Printf(TEXT("%s_Section_%d"), *BaseMeshName, Index);
      PreparedSection.MeshData = MeshData;
      PreparedSection.bSectionEnableNanite = bEnableNanite && (MeshData.Triangles.Num() >= NANITE_MIN_TRIANGLES);

      // Crear descripción de malla (thread-safe)
      FStaticMeshAttributes Attributes(PreparedSection.MeshDescription);
      Attributes.Register();

      // Obtener referencias a los atributos
      TVertexAttributesRef<FVector3f> VertexPositions = Attributes.GetVertexPositions();
      TVertexInstanceAttributesRef<FVector3f> VertexInstanceNormals = Attributes.GetVertexInstanceNormals();
      TVertexInstanceAttributesRef<FVector3f> VertexInstanceTangents = Attributes.GetVertexInstanceTangents();
      TVertexInstanceAttributesRef<float> VertexInstanceBinormalSigns = Attributes.GetVertexInstanceBinormalSigns();
      TVertexInstanceAttributesRef<FVector2f> VertexInstanceUVs = Attributes.GetVertexInstanceUVs();
      TVertexInstanceAttributesRef<FVector4f> VertexInstanceColors = Attributes.GetVertexInstanceColors();
      TPolygonGroupAttributesRef<FName> PolygonGroupNames = Attributes.GetPolygonGroupMaterialSlotNames();

      // Crear vértices
      TArray<FVertexID> VertexIDs;
      VertexIDs.Reserve(MeshData.Vertices.Num());
      for (const FVector& Vertex : MeshData.Vertices)
      {
        FVector TransformedVertex = MeshData.RelativeTransform.TransformPosition(Vertex);
        FVertexID VertexID = PreparedSection.MeshDescription.CreateVertex();
        VertexPositions[VertexID] = FVector3f(TransformedVertex);
        VertexIDs.Add(VertexID);
      }

      // Crear instancias de vértices
      TArray<FVertexInstanceID> VertexInstanceIDs;
      VertexInstanceIDs.Reserve(MeshData.Vertices.Num());
      for (int32 i = 0; i < MeshData.Vertices.Num(); i++)
      {
        FVertexInstanceID VertexInstanceID = PreparedSection.MeshDescription.CreateVertexInstance(VertexIDs[i]);

        if (MeshData.Normals.IsValidIndex(i))
        {
          FVector TransformedNormal = MeshData.RelativeTransform.TransformVector(MeshData.Normals[i]);
          VertexInstanceNormals[VertexInstanceID] = FVector3f(TransformedNormal.GetSafeNormal());
        }

        if (MeshData.Tangents.IsValidIndex(i))
        {
          FVector TransformedTangent = MeshData.RelativeTransform.TransformVector(MeshData.Tangents[i].TangentX);
          VertexInstanceTangents[VertexInstanceID] = FVector3f(TransformedTangent.GetSafeNormal());
          VertexInstanceBinormalSigns[VertexInstanceID] = MeshData.Tangents[i].bFlipTangentY ? -1.0f : 1.0f;
        }

        if (MeshData.UV0.IsValidIndex(i))
        {
          VertexInstanceUVs.Set(VertexInstanceID, 0, FVector2f(MeshData.UV0[i]));
        }

        if (MeshData.VertexColors.IsValidIndex(i))
        {
          VertexInstanceColors[VertexInstanceID] = FVector4f(MeshData.VertexColors[i]);
        }

        VertexInstanceIDs.Add(VertexInstanceID);
      }

      // Crear triángulos
      if (MeshData.Triangles.Num() % 3 == 0)
      {
        FPolygonGroupID PolygonGroupID = PreparedSection.MeshDescription.CreatePolygonGroup();
        PolygonGroupNames[PolygonGroupID] = FName(*MeshData.tMeshName);

        for (int32 i = 0; i < MeshData.Triangles.Num(); i += 3)
        {
          if (MeshData.Triangles.IsValidIndex(i + 2))
          {
            TArray<FVertexInstanceID> TriangleVertexInstances;
            TriangleVertexInstances.Add(VertexInstanceIDs[MeshData.Triangles[i]]);
            TriangleVertexInstances.Add(VertexInstanceIDs[MeshData.Triangles[i + 1]]);
            TriangleVertexInstances.Add(VertexInstanceIDs[MeshData.Triangles[i + 2]]);

            PreparedSection.MeshDescription.CreateTriangle(PolygonGroupID, TriangleVertexInstances);
          }
        }
      }
    });

  // 2. Creación de recursos en el Game Thread
  for (FPreparedMeshSection& PreparedSection : PreparedSections)
  {
    if (PreparedSection.MeshDescription.Vertices().Num() == 0)
    {
      continue; // Saltar secciones vacías
    }

    // Crear material (debe ser en Game Thread)
    UMaterialInterface* Material = CreateMaterialFromModelData(PreparedSection.MeshData.fMaterialData);
    if (!Material)
    {
      Material = LoadObject<UMaterial>(nullptr, TEXT("/Engine/EngineMaterials/DefaultMaterial.DefaultMaterial"));
      UE_LOG(LogTemp, Warning, TEXT("Using default material for section: %s"), *PreparedSection.MeshData.tMeshName);
    }
    OutMaterials.Add(Material);

    // Crear StaticMesh
    UStaticMesh* StaticMesh = NewObject<UStaticMesh>(
      GetTransientPackage(),
      FName(*PreparedSection.MeshName),
      RF_Public | RF_Standalone | RF_Transient);

    if (!StaticMesh)
    {
      UE_LOG(LogTemp, Error, TEXT("Failed to create StaticMesh for section: %s"), *PreparedSection.MeshName);
      continue;
    }

    // Configurar Nanite
    StaticMesh->NaniteSettings = NaniteSettings;
    StaticMesh->NaniteSettings.bEnabled = PreparedSection.bSectionEnableNanite;

    // Asegurarse de que el LOD 0 existe antes de trabajar con él
    if (StaticMesh->GetNumSourceModels() == 0)
    {
      StaticMesh->AddSourceModel();
    }

    // Configurar la descripción de la malla para el LOD 0
    FStaticMeshSourceModel& SourceModel = StaticMesh->GetSourceModel(0);
    SourceModel.BuildSettings.bRecomputeNormals = false;
    SourceModel.BuildSettings.bRecomputeTangents = false;
    SourceModel.BuildSettings.bGenerateLightmapUVs = false;
    SourceModel.BuildSettings.bBuildReversedIndexBuffer = false;

    // Asignar descripción de malla
    StaticMesh->CreateMeshDescription(0, MoveTemp(PreparedSection.MeshDescription));
    StaticMesh->CommitMeshDescription(0);

    // Configurar material
    FStaticMaterial StaticMaterial(Material, FName(*PreparedSection.MeshData.tMeshName), FName(*PreparedSection.MeshData.tMeshName));
    StaticMesh->GetStaticMaterials().Add(StaticMaterial);

    // Configuración física
    StaticMesh->CreateBodySetup();
    StaticMesh->GetBodySetup()->CollisionTraceFlag = CTF_UseComplexAsSimple;

    // Construir malla
    StaticMesh->Build();
    StaticMesh->PostEditChange();

#if WITH_EDITOR
    FAssetRegistryModule::AssetCreated(StaticMesh);
#endif

    GeneratedMeshes.Add(StaticMesh);
  }

  return GeneratedMeshes;
}

UMaterialInterface* URuntimeMeshToNaniteLibrary::CreateMaterialFromModelData(const FMaterialData& MaterialData, bool bCreateDynamicInstance)
{
  // Cargar material maestro
  static UMaterial* MasterMaterial = LoadObject<UMaterial>(nullptr,
    TEXT("/Engine/EngineMaterials/DefaultLitMaterial.DefaultLitMaterial"));

  if (!MasterMaterial)
  {
    UE_LOG(LogTemp, Warning, TEXT("Master material not found, using fallback"));
    MasterMaterial = LoadObject<UMaterial>(nullptr, TEXT("/Engine/EngineMaterials/DefaultMaterial.DefaultMaterial"));
  }

  // Crear instancia de material
  UMaterialInterface* Material = nullptr;
  if (bCreateDynamicInstance)
  {
    Material = UMaterialInstanceDynamic::Create(MasterMaterial, nullptr);
  }
  else
  {
    UMaterialInstanceConstant* MIC = NewObject<UMaterialInstanceConstant>(GetTransientPackage());
    if (MIC)
    {
      MIC->SetParentEditorOnly(MasterMaterial);
      Material = MIC;
    }
  }

  if (!Material)
  {
    UE_LOG(LogTemp, Warning, TEXT("Failed to create material instance"));
    return nullptr;
  }

  if (UMaterialInstanceDynamic* DynamicMat = Cast<UMaterialInstanceDynamic>(Material))
  {
    // Versión simplificada sin FMaterialParameterInfo
    DynamicMat->SetVectorParameterValue(TEXT("BaseColor"), MaterialData.baseColor);
    DynamicMat->SetScalarParameterValue(TEXT("Metallic"), MaterialData.metallic);
    DynamicMat->SetScalarParameterValue(TEXT("Specular"), MaterialData.specular);
    DynamicMat->SetScalarParameterValue(TEXT("Roughness"), MaterialData.roughness);
    DynamicMat->SetVectorParameterValue(TEXT("EmissiveColor"), MaterialData.emissiveColor);
  }
  else if (UMaterialInstanceConstant* MIC = Cast<UMaterialInstanceConstant>(Material))
  {
#if WITH_EDITOR
    // Versión para editor
    MIC->SetVectorParameterValueEditorOnly(FMaterialParameterInfo(TEXT("BaseColor")), MaterialData.baseColor);
    MIC->SetScalarParameterValueEditorOnly(FMaterialParameterInfo(TEXT("Metallic")), MaterialData.metallic);
    MIC->SetScalarParameterValueEditorOnly(FMaterialParameterInfo(TEXT("Specular")), MaterialData.specular);
    MIC->SetScalarParameterValueEditorOnly(FMaterialParameterInfo(TEXT("Roughness")), MaterialData.roughness);
    MIC->SetVectorParameterValueEditorOnly(FMaterialParameterInfo(TEXT("EmissiveColor")), MaterialData.emissiveColor);
#endif
  }

  // Configurar texturas
  SetMaterialTextureParameter(Material, TEXT("BaseColorTexture"), MaterialData.baseColorTextures);
  SetMaterialTextureParameter(Material, TEXT("NormalTexture"), MaterialData.normalTextures);
  SetMaterialTextureParameter(Material, TEXT("MetallicTexture"), MaterialData.metalTextures);
  SetMaterialTextureParameter(Material, TEXT("RoughnessTexture"), MaterialData.roughnessTextures);
  SetMaterialTextureParameter(Material, TEXT("EmissiveTexture"), MaterialData.emissiveTextures);
  SetMaterialTextureParameter(Material, TEXT("AOTexture"), MaterialData.ambient_occlusionTextures);

  return Material;
}

void URuntimeMeshToNaniteLibrary::SetMaterialTextureParameter(UMaterialInterface* Material, const FName& ParameterName, UTexture2D* Texture)
{
  if (!Material || !Texture) return;

  if (UMaterialInstanceDynamic* DynamicMaterial = Cast<UMaterialInstanceDynamic>(Material))
  {
    DynamicMaterial->SetTextureParameterValue(ParameterName, Texture);
  }
#if WITH_EDITOR
  else if (UMaterialInstanceConstant* MIC = Cast<UMaterialInstanceConstant>(Material))
  {
    MIC->SetTextureParameterValueEditorOnly(FMaterialParameterInfo(ParameterName), Texture);
  }
#endif
}

void URuntimeMeshToNaniteLibrary::CreateMeshSection(
  UStaticMesh* StaticMesh,
  const FMeshMaterialData& MeshData,
  int32 LODIndex,
  UMaterialInterface* Material,
  FMeshDescription& MeshDescription)
{
  if (!StaticMesh || MeshData.Vertices.Num() == 0 || MeshData.Triangles.Num() == 0)
  {
    return;
  }

  FStaticMeshAttributes Attributes(MeshDescription);
  TPolygonGroupAttributesRef<FName> PolygonGroupNames = Attributes.GetPolygonGroupMaterialSlotNames();
  TVertexAttributesRef<FVector3f> VertexPositions = Attributes.GetVertexPositions();
  TVertexInstanceAttributesRef<FVector3f> VertexInstanceNormals = Attributes.GetVertexInstanceNormals();
  TVertexInstanceAttributesRef<FVector3f> VertexInstanceTangents = Attributes.GetVertexInstanceTangents();
  TVertexInstanceAttributesRef<float> VertexInstanceBinormalSigns = Attributes.GetVertexInstanceBinormalSigns();
  TVertexInstanceAttributesRef<FVector2f> VertexInstanceUVs = Attributes.GetVertexInstanceUVs();
  TVertexInstanceAttributesRef<FVector4f> VertexInstanceColors = Attributes.GetVertexInstanceColors();

  // Crear grupo de polígonos para esta sección
  FPolygonGroupID PolygonGroupID = MeshDescription.CreatePolygonGroup();
  PolygonGroupNames[PolygonGroupID] = FName(*MeshData.tMeshName);

  // Crear vértices aplicando transformación
  TArray<FVertexID> VertexIDs;
  VertexIDs.Reserve(MeshData.Vertices.Num());

  for (const FVector& Vertex : MeshData.Vertices)
  {
    FVector TransformedVertex = MeshData.RelativeTransform.TransformPosition(Vertex);
    FVertexID VertexID = MeshDescription.CreateVertex();
    VertexPositions[VertexID] = FVector3f(TransformedVertex);
    VertexIDs.Add(VertexID);
  }

  // Crear instancias de vértices (normales, UVs, etc.)
  TArray<FVertexInstanceID> VertexInstanceIDs;
  VertexInstanceIDs.Reserve(MeshData.Vertices.Num());

  for (int32 i = 0; i < MeshData.Vertices.Num(); i++)
  {
    FVertexInstanceID VertexInstanceID = MeshDescription.CreateVertexInstance(VertexIDs[i]);

    // Aplicar transformación a normales y tangentes
    if (MeshData.Normals.IsValidIndex(i))
    {
      FVector TransformedNormal = MeshData.RelativeTransform.TransformVector(MeshData.Normals[i]);
      VertexInstanceNormals[VertexInstanceID] = FVector3f(TransformedNormal.GetSafeNormal());
    }

    if (MeshData.Tangents.IsValidIndex(i))
    {
      FVector TransformedTangent = MeshData.RelativeTransform.TransformVector(MeshData.Tangents[i].TangentX);
      VertexInstanceTangents[VertexInstanceID] = FVector3f(TransformedTangent.GetSafeNormal());
      VertexInstanceBinormalSigns[VertexInstanceID] = MeshData.Tangents[i].bFlipTangentY ? -1.0f : 1.0f;
    }

    if (MeshData.UV0.IsValidIndex(i))
    {
      VertexInstanceUVs.Set(VertexInstanceID, 0, FVector2f(MeshData.UV0[i]));
    }

    if (MeshData.VertexColors.IsValidIndex(i))
    {
      VertexInstanceColors[VertexInstanceID] = FVector4f(MeshData.VertexColors[i]);
    }

    VertexInstanceIDs.Add(VertexInstanceID);
  }

  // Crear triángulos
  if (MeshData.Triangles.Num() % 3 != 0)
  {
    UE_LOG(LogTemp, Warning, TEXT("Invalid triangle count in mesh section %s (not divisible by 3)"), *MeshData.tMeshName);
  }
  else
  {
    for (int32 i = 0; i < MeshData.Triangles.Num(); i += 3)
    {
      if (MeshData.Triangles.IsValidIndex(i + 2))
      {
        TArray<FVertexInstanceID> TriangleVertexInstances;
        TriangleVertexInstances.Add(VertexInstanceIDs[MeshData.Triangles[i]]);
        TriangleVertexInstances.Add(VertexInstanceIDs[MeshData.Triangles[i + 1]]);
        TriangleVertexInstances.Add(VertexInstanceIDs[MeshData.Triangles[i + 2]]);

        MeshDescription.CreateTriangle(PolygonGroupID, TriangleVertexInstances);
      }
    }
  }

  // Añadir material al StaticMesh
  FStaticMaterial StaticMaterial(Material, FName(*MeshData.tMeshName), FName(*MeshData.tMeshName));
  StaticMesh->GetStaticMaterials().Add(StaticMaterial);
}

int32 URuntimeMeshToNaniteLibrary::GetTriangleCount(const FModeldMaterialData& ModelData)
{
  int32 TotalTriangles = 0;
  for (const FMeshMaterialData& MeshData : ModelData.meshMatInfo)
  {
    TotalTriangles += MeshData.Triangles.Num() / 3;
  }
  return TotalTriangles;
}
