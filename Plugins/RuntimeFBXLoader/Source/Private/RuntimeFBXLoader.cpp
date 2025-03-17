#include "RuntimeFBXLoader.h"
#include "FBXLoader.h"
#include "Engine/StaticMesh.h"
#include "Rendering/NaniteResources.h"

UStaticMesh* UFBXLoader::LoadFBX(const FString& FilePath)
{
    // Usar FBXLoader para obtener la escena Assimp
    const aiScene* Scene = FBXLoader::LoadFBX(FilePath);
    if (!Scene || !Scene->HasMeshes())
    {
        return nullptr;
    }

    // Convertir la primera malla de Assimp en un UStaticMesh
    return CreateStaticMeshFromAssimp(Scene->mMeshes[0]);
}

UStaticMesh* UFBXLoader::CreateStaticMeshFromAssimp(aiMesh* Mesh)
{
    if (!Mesh)
    {
        UE_LOG(LogTemp, Warning, TEXT("Mesh inválida."));
        return nullptr;
    }

    // Crear un nuevo Static Mesh en memoria
    UStaticMesh* NewMesh = NewObject<UStaticMesh>();
    if (!NewMesh)
    {
        UE_LOG(LogTemp, Error, TEXT("No se pudo crear el StaticMesh."));
        return nullptr;
    }

    FStaticMeshRenderData* RenderData = new FStaticMeshRenderData();
    FStaticMeshLODResources& LOD = RenderData->LODResources[0];

    // Reservar memoria para vértices e índices
    LOD.VertexBuffers.PositionVertexBuffer.Init(Mesh->mNumVertices);
    LOD.IndexBuffer.Reserve(Mesh->mNumFaces * 3);

    // Copiar vértices
    for (unsigned int i = 0; i < Mesh->mNumVertices; i++)
    {
        FVector Position = FVector(Mesh->mVertices[i].x, Mesh->mVertices[i].y, Mesh->mVertices[i].z);
        LOD.VertexBuffers.PositionVertexBuffer.VertexPosition(i) = Position;
    }

    // Copiar índices
    for (unsigned int i = 0; i < Mesh->mNumFaces; i++)
    {
        aiFace& Face = Mesh->mFaces[i];
        if (Face.mNumIndices != 3) continue; // Solo triángulos

        for (unsigned int j = 0; j < 3; j++)
        {
            LOD.IndexBuffer.Add(Face.mIndices[j]);
        }
    }

    // Habilitar Nanite
    NewMesh->NaniteSettings.bEnabled = true;
    NewMesh->NaniteSettings.Threshold = 1;

    // Asignar el RenderData
    NewMesh->SetRenderData(RenderData);
    return NewMesh;
}

UTexture2D* UFBXLoader::LoadTextureFromPath(const FString& Path)
{
    return Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), nullptr, *Path));
}

UMaterialInstanceDynamic* UFBXLoader::CreateMaterial(UTexture2D* Texture)
{
    if (!Texture)
    {
        UE_LOG(LogTemp, Warning, TEXT("No se encontró la textura."));
        return nullptr;
    }

    // Crear un material dinámico a partir de un material base en Unreal
    UMaterialInterface* BaseMaterial = LoadObject<UMaterialInterface>(nullptr, TEXT("/Game/Materials/BaseMaterial"));
    if (!BaseMaterial)
    {
        UE_LOG(LogTemp, Error, TEXT("No se encontró el material base."));
        return nullptr;
    }

    UMaterialInstanceDynamic* MatInstance = UMaterialInstanceDynamic::Create(BaseMaterial, nullptr);
    MatInstance->SetTextureParameterValue("BaseColor", Texture);
    return MatInstance;
}