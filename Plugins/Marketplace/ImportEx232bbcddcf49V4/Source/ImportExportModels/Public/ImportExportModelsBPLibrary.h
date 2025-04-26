// Copyright 2023 Jack Chen. All Rights Reserved.

#pragma once

#include "LoadModelActor.h"

#include <assimp/scene.h>       // Output data structure
#include "ProceduralMeshComponent.h"

#include "GameFramework/Actor.h"

#include "Kismet/BlueprintFunctionLibrary.h"
#include "ImportExportModelsBPLibrary.generated.h"


USTRUCT(BlueprintType)
struct FMyMeshData
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		TArray<FVector> Vertices;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		TArray<int32> Triangles;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		TArray<FVector> Normals;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		TArray<FVector2D> UV0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		TArray<FLinearColor> VertexColors;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		TArray<FProcMeshTangent> Tangents;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		FTransform RelativeTransform;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		FLinearColor MatColor;
};

USTRUCT(BlueprintType)
struct FModeldData
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		bool bSuccess;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		int32 NumMeshes;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		TArray<FMyMeshData> meshInfo;
};


// add material
USTRUCT(BlueprintType)
struct FMaterialData
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		FString materialName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		FLinearColor baseColor;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		float metallic;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		float specular;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		float roughness;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		FLinearColor emissiveColor;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		UTexture2D* baseColor2Textures = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		UTexture2D* specularTextures = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		UTexture2D* emissiveTextures = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		UTexture2D* normalTextures = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		UTexture2D* opacityTextures = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		UTexture2D* reflectionTextures = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		UTexture2D* baseColorTextures = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		UTexture2D* metalTextures = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		UTexture2D* roughness2Textures = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		UTexture2D* ambientTextures = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		UTexture2D* heightTextures = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		UTexture2D* roughnessTextures = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		UTexture2D* displacementTextures = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		UTexture2D* lightmapTextures = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		UTexture2D* normal_cameraTextures = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		UTexture2D* emission_colorTextures = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		UTexture2D* ambient_occlusionTextures = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		TArray<UTexture2D*> unknownTextures;
};


// add material
USTRUCT(BlueprintType)
struct FMeshMaterialData
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		FString tMeshName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		TArray<FVector> Vertices;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		TArray<int32> Triangles;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		TArray<FVector> Normals;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		TArray<FVector2D> UV0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		TArray<FLinearColor> VertexColors;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		TArray<FProcMeshTangent> Tangents;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		FTransform RelativeTransform;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		FMaterialData fMaterialData;
};

USTRUCT(BlueprintType)
struct FModeldMaterialData
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		bool bSuccess;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		int32 numMeshes;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		TArray<FMeshMaterialData> meshMatInfo;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ReturnedData")
		FString modelFullPath;
};

UCLASS()
class UImportExportModelsBPLibrary : public UBlueprintFunctionLibrary
{
	//GENERATED_UCLASS_BODY()
	GENERATED_BODY()

public:

	static FTransform aiMatToTransform(aiMatrix4x4 NodeTransform);

	static aiMatrix4x4 TransformToAiMat(FTransform transform);

	static FString modelFilePath;

	UFUNCTION(BlueprintCallable, Category = "ImportExportModelsBPLibrary")
		static void MOpenFileDialog(const FString& DialogTitle, const FString& DefaultPath, TMap<FString, FString> FileTypeNames_FileTypes, FString& OutFileName);

	UFUNCTION(BlueprintCallable, Category = "OpenFileBrowser")
		static void MSaveFileDialog(const FString& DialogTitle, const FString& DefaultPath, FString& OutFileName);

		//用于导出时使用
	UFUNCTION(BlueprintCallable, Category = "ImportExportModelsBPLibrary")
		static FModeldMaterialData BPImportModel(FString filepath, FTransform& outRootTransform);

		//通用导入
	UFUNCTION(BlueprintCallable, Category = "ImportExportModelsBPLibrary")
		static FModeldMaterialData BPImportModelNormal(FString filepath, FTransform& outRootTransform);

	UFUNCTION(BlueprintCallable, Category = "ImportExportModelsBPLibrary")
		static int BPExportFBXModel(TArray<ALoadModelActor*> actors, FString outputPath);

	UFUNCTION(BlueprintCallable, Category = "ImportExportModelsBPLibrary")
		static UTexture2D* ReadImgToTexture(const FString& FilePath);

};
