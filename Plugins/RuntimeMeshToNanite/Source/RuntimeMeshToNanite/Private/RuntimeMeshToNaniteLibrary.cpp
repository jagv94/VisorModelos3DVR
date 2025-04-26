// Copyright (c) Adrián Guerra 2025. All rights reserved.

#include "RuntimeMeshToNaniteLibrary.h"
#include "StaticMeshAttributes.h"
#include "StaticMeshOperations.h"
#include "Engine/StaticMesh.h"
#include "Materials/Material.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Engine/Texture2D.h"
#include "Components/StaticMeshComponent.h"
#include <Materials/MaterialExpressionConstant3Vector.h>

UStaticMesh* URuntimeMeshToNaniteLibrary::ConvertRuntimeMeshToNanite(
  const FModeldMaterialData& ModelData,
  const FString& MeshName,
  bool bEnableNanite,
  const FMeshNaniteSettings& NaniteSettings)
{
  if (!ModelData.bSuccess || ModelData.meshMatInfo.Num() == 0)
  {
    UE_LOG(LogTemp, Error, TEXT("Invalid model data provided for Nanite conversion"));
    return nullptr;
  }

  // Crear StaticMesh transitorio
  UStaticMesh* StaticMesh = NewObject<UStaticMesh>(
    GetTransientPackage(),
    FName(*MeshName),
    RF_Public | RF_Standalone | RF_Transient
  );

  // Crear descripción de malla
  FMeshDescription MeshDescription;
  FStaticMeshAttributes Attributes(MeshDescription);
  Attributes.Register();

  // Procesar cada sección
  for (const FMeshMaterialData& MeshData : ModelData.meshMatInfo)
  {
    UMaterialInterface* Material = CreateMaterialFromModelData(MeshData.fMaterialData);
    if (!Material)
    {
      Material = LoadObject<UMaterial>(nullptr, TEXT("/Engine/EngineMaterials/DefaultMaterial.DefaultMaterial"));
    }
    CreateMeshSection(StaticMesh, MeshData, 0, Material, MeshDescription);
  }

  // Aplicar y comprometer descripción
  StaticMesh->CreateMeshDescription(0, MeshDescription);
  StaticMesh->CommitMeshDescription(0);

  // Configurar Nanite
  StaticMesh->NaniteSettings = NaniteSettings;
  StaticMesh->NaniteSettings.bEnabled = bEnableNanite;

  // Construir y finalizar StaticMesh
  StaticMesh->Build();
  StaticMesh->PostEditChange();

#if WITH_EDITOR
  FAssetRegistryModule::AssetCreated(StaticMesh);
#endif

  return StaticMesh;
}

UMaterialInterface* URuntimeMeshToNaniteLibrary::CreateMaterialFromModelData(const FMaterialData& MaterialData)
{
  UMaterial* ParentMaterial = LoadObject<UMaterial>(nullptr, TEXT("/Engine/EngineMaterials/DefaultMaterial.DefaultMaterial"));
  if (!ParentMaterial)
  {
    return nullptr;
  }

  UMaterialInstanceDynamic* DynamicMaterial = UMaterialInstanceDynamic::Create(ParentMaterial, nullptr);

  DynamicMaterial->SetVectorParameterValue(FName("BaseColor"), MaterialData.baseColor);
  DynamicMaterial->SetScalarParameterValue(FName("Metallic"), MaterialData.metallic);
  DynamicMaterial->SetScalarParameterValue(FName("Specular"), MaterialData.specular);
  DynamicMaterial->SetScalarParameterValue(FName("Roughness"), MaterialData.roughness);
  DynamicMaterial->SetVectorParameterValue(FName("EmissiveColor"), MaterialData.emissiveColor);

  if (MaterialData.baseColorTextures)
  {
    DynamicMaterial->SetTextureParameterValue(FName("BaseColorTexture"), MaterialData.baseColorTextures);
  }
  if (MaterialData.normalTextures)
  {
    DynamicMaterial->SetTextureParameterValue(FName("NormalTexture"), MaterialData.normalTextures);
  }

  return DynamicMaterial;
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

  FPolygonGroupID PolygonGroupID = MeshDescription.CreatePolygonGroup();
  PolygonGroupNames[PolygonGroupID] = FName(*MeshData.tMeshName);

  TArray<FVertexID> VertexIDs;
  VertexIDs.Reserve(MeshData.Vertices.Num());

  for (const FVector& Vertex : MeshData.Vertices)
  {
    FVertexID VertexID = MeshDescription.CreateVertex();
    VertexPositions[VertexID] = FVector3f(Vertex);
    VertexIDs.Add(VertexID);
  }

  TArray<FVertexInstanceID> VertexInstanceIDs;
  VertexInstanceIDs.Reserve(MeshData.Vertices.Num());

  for (int32 i = 0; i < MeshData.Vertices.Num(); i++)
  {
    FVertexInstanceID VertexInstanceID = MeshDescription.CreateVertexInstance(VertexIDs[i]);

    if (MeshData.Normals.IsValidIndex(i))
    {
      VertexInstanceNormals[VertexInstanceID] = FVector3f(MeshData.Normals[i]);
    }
    if (MeshData.Tangents.IsValidIndex(i))
    {
      VertexInstanceTangents[VertexInstanceID] = FVector3f(MeshData.Tangents[i].TangentX);
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

  // Verificar que el número de triángulos es correcto
  if (MeshData.Triangles.Num() % 3 != 0)
  {
    UE_LOG(LogTemp, Warning, TEXT("MeshData.Triangles count is not divisible by 3. Marking section with error material: %s"), *MeshData.tMeshName);

    // Crear PolygonGroup de error
    FPolygonGroupID ErrorPolygonGroupID = MeshDescription.CreatePolygonGroup();
    PolygonGroupNames[ErrorPolygonGroupID] = FName(*(MeshData.tMeshName + TEXT("_Error")));

    // Crear un único vértice dummy
    FVertexID V0 = MeshDescription.CreateVertex();
    FVertexID V1 = MeshDescription.CreateVertex();
    FVertexID V2 = MeshDescription.CreateVertex();

    VertexPositions[V0] = FVector3f(0.0f, 0.0f, 0.0f);
    VertexPositions[V1] = FVector3f(0.0f, 100.0f, 0.0f);
    VertexPositions[V2] = FVector3f(100.0f, 0.0f, 0.0f);

    // Crear instancias de vértices
    FVertexInstanceID VI0 = MeshDescription.CreateVertexInstance(V0);
    FVertexInstanceID VI1 = MeshDescription.CreateVertexInstance(V1);
    FVertexInstanceID VI2 = MeshDescription.CreateVertexInstance(V2);

    // Crear triángulo dummy
    TArray<FVertexInstanceID> TriangleVertexInstances = { VI0, VI1, VI2 };
    MeshDescription.CreateTriangle(ErrorPolygonGroupID, TriangleVertexInstances);

    // Crear material rojo dinámico
    UMaterial* ParentMaterial = LoadObject<UMaterial>(nullptr, TEXT("/Engine/EngineMaterials/DefaultMaterial.DefaultMaterial"));
    UMaterialInstanceDynamic* ErrorMaterial = nullptr;

    if (ParentMaterial)
    {
      ErrorMaterial = UMaterialInstanceDynamic::Create(ParentMaterial, nullptr);
      if (ErrorMaterial)
      {
        // Poner el BaseColor en rojo brillante
        ErrorMaterial->SetVectorParameterValue(FName("BaseColor"), FLinearColor(10.0f, 0.0f, 0.0f, 1.0f)); // Rojo muy potente
      }
    }

    int32 ErrorMaterialIndex = StaticMesh->GetStaticMaterials().Num();
    FStaticMaterial StaticErrorMaterial(ErrorMaterial, FName(*(MeshData.tMeshName + TEXT("_Error"))));
    StaticMesh->GetStaticMaterials().Add(StaticErrorMaterial);

    return;
  }

  // Crear triángulos
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

  int32 MaterialIndex = StaticMesh->GetStaticMaterials().Num();
  FStaticMaterial StaticMaterial(Material, FName(*MeshData.tMeshName));
  StaticMesh->GetStaticMaterials().Add(StaticMaterial);
}
