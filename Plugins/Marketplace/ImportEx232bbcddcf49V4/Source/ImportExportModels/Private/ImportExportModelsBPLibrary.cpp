// Copyright 2023 Jack Chen. All Rights Reserved.

#include "ImportExportModelsBPLibrary.h"
#include "ImportExportModels.h"

#include "Materials/MaterialInstanceDynamic.h"
#include "Interfaces/IPluginManager.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/Texture2D.h"
#include "Engine/GameViewportClient.h"
#include "Widgets/SWindow.h"
#include "Materials/MaterialExpressionConstant.h"
#include "Materials/MaterialExpressionConstant3Vector.h"
#include "Materials/MaterialExpressionTextureSampleParameter2D.h"
#include "Materials/MaterialExpressionVectorParameter.h"
#include "Materials/MaterialExpressionScalarParameter.h"
#include "TextureResource.h"
#include "Engine/Engine.h"


#include "Runtime/ImageWrapper/Public/IImageWrapper.h"
#include "Runtime/ImageWrapper/Public/IImageWrapperModule.h"

#include "assimp/cimport.h"
#include <assimp/pbrmaterial.h>
#include <assimp/Exporter.hpp>
#include <assimp/Importer.hpp>  // C++ importer interface
//#include <assimp/scene.h>       // Output data structure
#include <assimp/SceneCombiner.h>
#include <assimp/postprocess.h> // Post processing flags
#include <assimp/version.h>

#include "assimp/ImportExportLib.h"
#include "assimp/UE_Type.h"

#include "Windows/AllowWindowsPlatformTypes.h"
#include "windows.h"
#include "Windows/HideWindowsPlatformTypes.h"
#include <commdlg.h>

#include <string>
#include <shlobj.h>
#include <tchar.h>


void FindMeshInfo(const aiScene* scene, aiNode* node, FModeldData& result)
{
	for (uint32 i = 0; i < node->mNumMeshes; i++)
	{
		std::string TestString = node->mName.C_Str();
		FString Fs = FString(TestString.c_str());
		UE_LOG(LogTemp, Warning, TEXT("FindMeshInfo. %s\n"), *Fs);

		//int meshidx = *node->mMeshes;
		int meshidx = node->mMeshes[i];//cwh add
		aiMesh* mesh = scene->mMeshes[meshidx];
		FMyMeshData& mi = result.meshInfo[meshidx];

		//transform.
		aiMatrix4x4 tempTrans = node->mTransformation;
		FMatrix tempMatrix;
		tempMatrix.M[0][0] = tempTrans.a1; tempMatrix.M[0][1] = tempTrans.b1; tempMatrix.M[0][2] = tempTrans.c1; tempMatrix.M[0][3] = tempTrans.d1;
		tempMatrix.M[1][0] = tempTrans.a2; tempMatrix.M[1][1] = tempTrans.b2; tempMatrix.M[1][2] = tempTrans.c2; tempMatrix.M[1][3] = tempTrans.d2;
		tempMatrix.M[2][0] = tempTrans.a3; tempMatrix.M[2][1] = tempTrans.b3; tempMatrix.M[2][2] = tempTrans.c3; tempMatrix.M[2][3] = tempTrans.d3;
		tempMatrix.M[3][0] = tempTrans.a4; tempMatrix.M[3][1] = tempTrans.b4; tempMatrix.M[3][2] = tempTrans.c4; tempMatrix.M[3][3] = tempTrans.d4;
		mi.RelativeTransform = FTransform(tempMatrix);

		//vet
		for (uint32 j = 0; j < mesh->mNumVertices; ++j)
		{
			FVector vertex = FVector(
				mesh->mVertices[j].x,
				mesh->mVertices[j].y,
				mesh->mVertices[j].z);

			vertex = mi.RelativeTransform.TransformFVector4(vertex);
			mi.Vertices.Push(vertex);

			//Normal
			if (mesh->HasNormals())
			{
				FVector normal = FVector(
					mesh->mNormals[j].x,
					mesh->mNormals[j].y,
					mesh->mNormals[j].z);

				//normal = mi.RelativeTransform.TransformFVector4(normal);
				mi.Normals.Push(normal);
			}
			else
			{
				mi.Normals.Push(FVector::ZeroVector);
			}

			// if the mesh contains tex coords
			if (mesh->mTextureCoords[0])
			{
				FVector2D uvs;
				uvs.X = mesh->mTextureCoords[0][j].x;
				uvs.Y = -mesh->mTextureCoords[0][j].y;
				mi.UV0.Add(uvs);
			}
			else
			{
				mi.UV0.Add(FVector2D(0.f, 0.f));
			}

			//UV Coordinates - inconsistent coordinates
			/*if (mesh->HasTextureCoords(j))
			{
				FVector2D uv = FVector2D(mesh->mTextureCoords[j]->x, -mesh->mTextureCoords[j]->y);
				mi.UV0.Add(uv);
			}*/

			//Tangent
			if (mesh->HasTangentsAndBitangents())
			{
				FProcMeshTangent meshTangent = FProcMeshTangent(
					mesh->mTangents[j].x,
					mesh->mTangents[j].y,
					mesh->mTangents[j].z
				);
				mi.Tangents.Push(meshTangent);
			}

			//Vertex color
			if (mesh->HasVertexColors(j))//cwh modify
			{
				FLinearColor color = FLinearColor(
					mesh->mColors[j]->r,
					mesh->mColors[j]->g,
					mesh->mColors[j]->b,
					mesh->mColors[j]->a
				);
				mi.VertexColors.Push(color);
			}
		}

		int MatIndex = mesh->mMaterialIndex;
		if (scene->HasMaterials())
		{

			aiMaterial* aiMat = scene->mMaterials[MatIndex];

			aiColor4D aiMatColor;
			aiMatColor.r = 0.5;
			aiMatColor.g = 0.5;
			aiMatColor.b = 0.5;
			aiMatColor.a = 1;

			aiReturn return1 = aiGetMaterialColor(aiMat, AI_MATKEY_COLOR_DIFFUSE, &aiMatColor);
			aiString name;
			aiReturn return2 = aiGetMaterialString(aiMat, AI_MATKEY_NAME, &name);


			FLinearColor LinearMatColor = FLinearColor(aiMatColor.r, aiMatColor.g, aiMatColor.b, aiMatColor.a);

			mi.MatColor = LinearMatColor;

		}
	}
}


void FindMesh(const aiScene* scene, aiNode* node, FModeldData& retdata)
{
	FindMeshInfo(scene, node, retdata);

	for (uint32 m = 0; m < node->mNumChildren; ++m)
	{
		FindMesh(scene, node->mChildren[m], retdata);
	}
}


UTexture2D* AiTextureToUTexture2D(const aiTexture* a_t)
{
	UTexture2D* texture = NULL;

	if (a_t->mHeight == 0)
	{
		FString formatHint = FString(a_t->achFormatHint);
		EImageFormat imageFormat;
		if (formatHint.Equals(TEXT("jpg")))
		{
			imageFormat = EImageFormat::JPEG;
		}
		else if (formatHint.Equals(TEXT("png")))
		{
			imageFormat = EImageFormat::PNG;
		}
		else if (formatHint.Equals(TEXT("bmp")))
		{
			imageFormat = EImageFormat::BMP;
		}
		else if (formatHint.Equals(TEXT("ico")))
		{
			imageFormat = EImageFormat::ICO;
		}
		else if (formatHint.Equals(TEXT("exr")))
		{
			imageFormat = EImageFormat::EXR;
		}
		else
		{
			imageFormat = EImageFormat::Invalid;
		}

		IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));
		//IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName(*FilePath));
		// Note: PNG format.  Other formats are supported
		TSharedPtr<IImageWrapper> ImageWrapper = ImageWrapperModule.CreateImageWrapper(imageFormat);
		if (ImageWrapper.IsValid() && ImageWrapper->SetCompressed((uint8*)a_t->pcData, a_t->mWidth))
		{
			TArray<uint8> UncompressedBGRA;
			if (ImageWrapper->GetRaw(ERGBFormat::BGRA, 8, UncompressedBGRA))
			{
				// Create the UTexture for rendering
				texture = UTexture2D::CreateTransient(ImageWrapper->GetWidth(), ImageWrapper->GetHeight(), PF_B8G8R8A8);

				// Fill in the source data from the file
				void* TextureData = texture->GetPlatformData()->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
				FMemory::Memcpy(TextureData, UncompressedBGRA.GetData(), UncompressedBGRA.Num());
				texture->GetPlatformData()->Mips[0].BulkData.Unlock();

				// Update the rendering resource from data.
				texture->UpdateResource();
			}
		}
	}
	else
	{
		uint8* UncompressedBGRA = (uint8*)a_t->pcData;

		texture = UTexture2D::CreateTransient(a_t->mWidth, a_t->mHeight, PF_B8G8R8A8);
		texture->CompressionSettings = TC_Default;
		texture->LODGroup = TextureGroup::TEXTUREGROUP_World;
		//MyTexture->MipGenSettings = TMGS_NoMipmaps;
		texture->LODBias = 0;
		texture->Filter = TextureFilter::TF_Default;
		texture->SRGB = 1;
		texture->AddressX = TA_Clamp;
		texture->AddressY = TA_Clamp;

		// Fill in the source data from the file
		void* TextureData = texture->GetPlatformData()->Mips[0].BulkData.Lock(LOCK_READ_WRITE);

		FMemory::Memcpy(TextureData, UncompressedBGRA, a_t->mWidth * a_t->mHeight * sizeof(FColor));
		texture->GetPlatformData()->Mips[0].BulkData.Unlock();

		// Update the rendering resource from data.
		texture->UpdateResource();
	}
	return texture;
}

// checks all material textures of a given type and loads the textures if they're not loaded yet.
	// the required info is returned as a Texture struct.
TArray<UTexture2D*> LoadMaterialTextures(const aiScene* scene, aiMaterial* mat, aiTextureType type)
{
	TArray<UTexture2D*> textures;
	for (unsigned int i = 0; i < mat->GetTextureCount(type); i++)
	{
		//vector<Texture> textures_loaded;
		aiString str;
		aiReturn r = mat->GetTexture(type, i, &str);
		const char* shotName = aiScene::GetShortFilename(str.C_Str());
		FString uShotName(shotName);
		UE_LOG(LogTemp, Warning, TEXT("uShotName = %s\n"), *uShotName);

		if (r == aiReturn_SUCCESS)
		{
			const aiTexture* t = nullptr;
			if (scene->HasTextures())
			{
				UE_LOG(LogTemp, Warning, TEXT("Get Embedded Texture\n"));
				t = scene->GetEmbeddedTexture(str.C_Str());

				if (t)
				{
					textures.Add(AiTextureToUTexture2D(t));
				}
			}
			else
			{
				FString dirPath = FPaths::GetPath(UImportExportModelsBPLibrary::modelFilePath);
				FString full_img_path = FPaths::Combine(dirPath, uShotName);

				// Si no encuentra la textura en la carpeta ra韟 del FBX
				if (!FPaths::FileExists(full_img_path))
				{
					// Construye la ruta a la carpeta .fbm
					FString FBMFolder = FPaths::Combine(
						dirPath,
						FPaths::GetBaseFilename(UImportExportModelsBPLibrary::modelFilePath) + TEXT(".fbm")
					);

					// Comprueba si la carpeta .fbm existe
					if (FPaths::DirectoryExists(FBMFolder))
					{
						// Construye la ruta completa a la textura dentro de la carpeta .fbm
						full_img_path = FPaths::Combine(FBMFolder, uShotName);

						UE_LOG(LogTemp, Warning, TEXT("Buscando textura en carpeta .fbm: %s"), *full_img_path);
					}
					else
					{
						UE_LOG(LogTemp, Warning, TEXT("Carpeta .fbm no encontrada: %s"), *FBMFolder);
					}
				}

				UTexture2D* t_t = UImportExportModelsBPLibrary::ReadImgToTexture(full_img_path);
				UE_LOG(LogTemp, Warning, TEXT("Get external Texture, path = %s\n"), *full_img_path);

				textures.Add(t_t);
			}
		}
	}
	return textures;
}

void FindMeshWithMat(const aiScene* scene, aiNode* node, FModeldMaterialData& result)
{
	for (uint32 i = 0; i < node->mNumMeshes; i++)
	{
		std::string nodeName = node->mName.C_Str();
		FString fNodeName = FString(nodeName.c_str());
		UE_LOG(LogTemp, Warning, TEXT("FindMeshWithMat. %s\n"), *fNodeName);

		//int meshidx = *node->mMeshes;
		int meshidx = node->mMeshes[i];//cwh add
		aiMesh* mesh = scene->mMeshes[meshidx];
		FMeshMaterialData& mi = result.meshMatInfo[meshidx];
		mi.tMeshName = fNodeName;

		//transform.
		aiMatrix4x4 tempTrans = node->mTransformation;
		FMatrix tempMatrix;
		tempMatrix.M[0][0] = tempTrans.a1; tempMatrix.M[0][1] = tempTrans.b1; tempMatrix.M[0][2] = tempTrans.c1; tempMatrix.M[0][3] = tempTrans.d1;
		tempMatrix.M[1][0] = tempTrans.a2; tempMatrix.M[1][1] = tempTrans.b2; tempMatrix.M[1][2] = tempTrans.c2; tempMatrix.M[1][3] = tempTrans.d2;
		tempMatrix.M[2][0] = tempTrans.a3; tempMatrix.M[2][1] = tempTrans.b3; tempMatrix.M[2][2] = tempTrans.c3; tempMatrix.M[2][3] = tempTrans.d3;
		tempMatrix.M[3][0] = tempTrans.a4; tempMatrix.M[3][1] = tempTrans.b4; tempMatrix.M[3][2] = tempTrans.c4; tempMatrix.M[3][3] = tempTrans.d4;

		/*tempMatrix.M[0][0] = tempTrans[0][0]; tempMatrix.M[0][1] = tempTrans[0][1]; tempMatrix.M[0][2] = tempTrans[0][2]; tempMatrix.M[0][3] = tempTrans[0][3];
		tempMatrix.M[1][0] = tempTrans[1][0]; tempMatrix.M[1][1] = tempTrans[1][1]; tempMatrix.M[1][2] = tempTrans[1][2]; tempMatrix.M[1][3] = tempTrans[1][3];
		tempMatrix.M[2][0] = tempTrans[2][0]; tempMatrix.M[2][1] = tempTrans[2][1]; tempMatrix.M[2][2] = tempTrans[2][2]; tempMatrix.M[2][3] = tempTrans[2][3];
		tempMatrix.M[3][0] = tempTrans[3][0]; tempMatrix.M[3][1] = tempTrans[3][1]; tempMatrix.M[3][2] = tempTrans[3][2]; tempMatrix.M[3][3] = tempTrans[3][3];*/

		//导入导出时，LoadModelWithMaterial8使用这个,
		mi.RelativeTransform = FTransform(tempMatrix);

		//导入导出时，LoadModelWithMaterial2使用这个
		//mi.RelativeTransform = FTransform();//不使用获取的mTransformation，这样可以让模型横着,

		//vet
		for (uint32 j = 0; j < mesh->mNumVertices; ++j)
		{
			FVector vertex = FVector(
				mesh->mVertices[j].x,
				mesh->mVertices[j].y,
				mesh->mVertices[j].z);

			vertex = mi.RelativeTransform.TransformFVector4(vertex);
			mi.Vertices.Push(vertex);

			//Normal
			if (mesh->HasNormals())
			{
				FVector normal = FVector(
					mesh->mNormals[j].x,
					mesh->mNormals[j].y,
					mesh->mNormals[j].z);

				//normal = mi.RelativeTransform.TransformFVector4(normal);
				mi.Normals.Push(normal);
			}
			else
			{
				mi.Normals.Push(FVector::ZeroVector);
			}

			// if the mesh contains tex coords
			if (mesh->mTextureCoords[0])
			{
				FVector2D uvs;
				uvs.X = mesh->mTextureCoords[0][j].x;
				uvs.Y = -mesh->mTextureCoords[0][j].y;
				mi.UV0.Add(uvs);
			}
			else
			{
				mi.UV0.Add(FVector2D(0.f, 0.f));
			}

			//UV Coordinates - inconsistent coordinates
			/*if (mesh->HasTextureCoords(j))
			{
				FVector2D uv = FVector2D(mesh->mTextureCoords[j]->x, mesh->mTextureCoords[j]->y);
				mi.UV0.Add(uv);
			}*/

			//Tangent
			if (mesh->HasTangentsAndBitangents())
			{
				FProcMeshTangent meshTangent = FProcMeshTangent(
					mesh->mTangents[j].x,
					mesh->mTangents[j].y,
					mesh->mTangents[j].z
				);
				mi.Tangents.Push(meshTangent);
			}

			//Vertex color
			if (mesh->HasVertexColors(j))//cwh modify
			{
				FLinearColor color = FLinearColor(
					mesh->mColors[j]->r,
					mesh->mColors[j]->g,
					mesh->mColors[j]->b,
					mesh->mColors[j]->a
				);
				mi.VertexColors.Push(color);
			}
		}

		int MatIndex = mesh->mMaterialIndex;
		if (scene->HasMaterials())
		{
			//pbrmat
			aiMaterial* aiMat = scene->mMaterials[MatIndex];

			aiString defaultName = aiString("DefaultMaterial");
			aiString matName = aiMat->GetName();
			if (matName == defaultName)
			{
				aiReturn return2 = aiGetMaterialString(aiMat, AI_MATKEY_NAME, &matName);
			}

			std::string ss = matName.C_Str();
			FString fS = FString(ss.c_str());
			UE_LOG(LogTemp, Warning, TEXT("mateirla name = %s  \n"), *fS);

			//FMaterialData fMatData;

			mi.fMaterialData.materialName = fS;

			TArray<UTexture2D*> textures2D12 = LoadMaterialTextures(scene, aiMat, aiTextureType_AMBIENT);
			if (textures2D12.Num() > 0)
			{
				UE_LOG(LogTemp, Warning, TEXT("Read to ambientTextures \n"));
				mi.fMaterialData.ambientTextures = textures2D12[0];
			}
			TArray<UTexture2D*> textures2D13 = LoadMaterialTextures(scene, aiMat, aiTextureType_HEIGHT);
			if (textures2D13.Num() > 0)
			{
				UE_LOG(LogTemp, Warning, TEXT("Read to heightTextures \n"));
				mi.fMaterialData.heightTextures = textures2D13[0];
			}
			TArray<UTexture2D*> textures2D14 = LoadMaterialTextures(scene, aiMat, aiTextureType_SHININESS);
			if (textures2D14.Num() > 0)
			{
				UE_LOG(LogTemp, Warning, TEXT("Read to specularTextures \n"));
				mi.fMaterialData.specularTextures = textures2D14[0];
			}
			TArray<UTexture2D*> textures2D15 = LoadMaterialTextures(scene, aiMat, aiTextureType_DISPLACEMENT);
			if (textures2D15.Num() > 0)
			{
				UE_LOG(LogTemp, Warning, TEXT("Read to displacementTextures \n"));
				mi.fMaterialData.displacementTextures = textures2D15[0];
			}
			TArray<UTexture2D*> textures2D16 = LoadMaterialTextures(scene, aiMat, aiTextureType_LIGHTMAP);
			if (textures2D16.Num() > 0)
			{
				UE_LOG(LogTemp, Warning, TEXT("Read to lightmapTextures \n"));
				mi.fMaterialData.lightmapTextures = textures2D16[0];
			}
			TArray<UTexture2D*> textures2D18 = LoadMaterialTextures(scene, aiMat, aiTextureType_NORMAL_CAMERA);
			if (textures2D18.Num() > 0)
			{
				UE_LOG(LogTemp, Warning, TEXT("Read to normal_cameraTextures \n"));
				mi.fMaterialData.normal_cameraTextures = textures2D18[0];
			}
			TArray<UTexture2D*> textures2D19 = LoadMaterialTextures(scene, aiMat, aiTextureType_EMISSION_COLOR);
			if (textures2D19.Num() > 0)
			{
				UE_LOG(LogTemp, Warning, TEXT("Read to emission_colorTextures \n"));
				mi.fMaterialData.emission_colorTextures = textures2D19[0];
			}
			TArray<UTexture2D*> textures2D20 = LoadMaterialTextures(scene, aiMat, aiTextureType_AMBIENT_OCCLUSION);
			if (textures2D20.Num() > 0)
			{
				UE_LOG(LogTemp, Warning, TEXT("Read to ambient_occlusionTextures \n"));
				mi.fMaterialData.ambient_occlusionTextures = textures2D20[0];
			}

			//BaseColor
			TArray<UTexture2D*> textures2D1 = LoadMaterialTextures(scene, aiMat, aiTextureType_DIFFUSE);
			if (textures2D1.Num() > 0)
			{
				UE_LOG(LogTemp, Warning, TEXT("Read to baseColorTextures \n"));
				mi.fMaterialData.baseColorTextures = textures2D1[0];
			}
			aiColor4D baseColor(0.8f, 0.8f, 0.8f, 1.0f);
			aiReturn returnB = aiMat->Get(AI_MATKEY_COLOR_DIFFUSE, baseColor);
			if (returnB == aiReturn::aiReturn_FAILURE)
			{
				baseColor = aiColor4D(0.8f, 0.8f, 0.8f, 1.0f);
			}

			mi.fMaterialData.baseColor = FLinearColor(baseColor.r, baseColor.g, baseColor.b, baseColor.a);

			//Metallic
			TArray<UTexture2D*> textures2D9 = LoadMaterialTextures(scene, aiMat, aiTextureType_METALNESS);
			if (textures2D9.Num() > 0)
			{
				UE_LOG(LogTemp, Warning, TEXT("Read to metalTextures \n"));
				mi.fMaterialData.metalTextures = textures2D9[0];
			}
			float metallic = 0;
			aiReturn returnM = aiMat->Get(AI_MATKEY_GLTF_PBRMETALLICROUGHNESS_METALLIC_FACTOR, metallic);
			if (returnM == aiReturn::aiReturn_FAILURE)
			{
				metallic = 0;
			}
			mi.fMaterialData.metallic = metallic;

			//Specular
			TArray<UTexture2D*> textures2D2 = LoadMaterialTextures(scene, aiMat, aiTextureType_SPECULAR);
			if (textures2D2.Num() > 0)
			{
				UE_LOG(LogTemp, Warning, TEXT("Read to roughnessTextures \n"));
				mi.fMaterialData.roughnessTextures = textures2D2[0];
			}
			float specular = 0.5f;
			aiReturn returnS = aiMat->Get(AI_MATKEY_COLOR_SPECULAR, specular);
			if (returnS == aiReturn::aiReturn_FAILURE)
			{
				specular = 0.5f;
			}
			mi.fMaterialData.specular = specular;

			//Roughness
			TArray<UTexture2D*> textures2D3 = LoadMaterialTextures(scene, aiMat, aiTextureType_DIFFUSE_ROUGHNESS);
			if (textures2D3.Num() > 0)
			{
				UE_LOG(LogTemp, Warning, TEXT("Read to roughness2Textures(assimp roughness). \n"));
				mi.fMaterialData.roughness2Textures = textures2D3[0];
			}
			float roughness = 1;
			aiReturn returnRo = aiMat->Get(AI_MATKEY_GLTF_PBRMETALLICROUGHNESS_ROUGHNESS_FACTOR, roughness);
			if (returnRo == aiReturn::aiReturn_FAILURE)
			{
				roughness = 1;
			}
			mi.fMaterialData.roughness = roughness;

			//EmissiveColor
			TArray<UTexture2D*> textures2D4 = LoadMaterialTextures(scene, aiMat, aiTextureType_EMISSIVE);
			if (textures2D4.Num() > 0)
			{
				UE_LOG(LogTemp, Warning, TEXT("Read to emissiveTextures \n"));
				mi.fMaterialData.emissiveTextures = textures2D4[0];
			}

			aiColor4D emissiveColor(0.f, 0.f, 0.f, 0.f);
			aiReturn returnE = aiMat->Get(AI_MATKEY_COLOR_EMISSIVE, emissiveColor);
			if (returnE == aiReturn::aiReturn_FAILURE)
			{
				emissiveColor = aiColor4D(0.f, 0.f, 0.f, 0.f);
			}
			mi.fMaterialData.emissiveColor = FLinearColor(emissiveColor.r, emissiveColor.g, emissiveColor.b, emissiveColor.a);

			//Normal
			TArray<UTexture2D*> textures2D5 = LoadMaterialTextures(scene, aiMat, aiTextureType_NORMALS);
			if (textures2D5.Num() > 0)
			{
				UE_LOG(LogTemp, Warning, TEXT("Read to normalTextures \n"));
				mi.fMaterialData.normalTextures = textures2D5[0];
			}

			TArray<UTexture2D*> textures2D6 = LoadMaterialTextures(scene, aiMat, aiTextureType_OPACITY);
			if (textures2D6.Num() > 0)
			{
				UE_LOG(LogTemp, Warning, TEXT("Read to opacityTextures \n"));
				mi.fMaterialData.opacityTextures = textures2D6[0];
			}
			TArray<UTexture2D*> textures2D7 = LoadMaterialTextures(scene, aiMat, aiTextureType_REFLECTION);
			if (textures2D7.Num() > 0)
			{
				UE_LOG(LogTemp, Warning, TEXT("Read to reflectionTextures \n"));
				mi.fMaterialData.reflectionTextures = textures2D7[0];
			}
			TArray<UTexture2D*> textures2D8 = LoadMaterialTextures(scene, aiMat, aiTextureType_BASE_COLOR);
			if (textures2D8.Num() > 0)
			{
				UE_LOG(LogTemp, Warning, TEXT("Read to baseColor2Textures(assimp basecolor) \n"));
				mi.fMaterialData.baseColor2Textures = textures2D8[0];
			}

			//加载有的fbx时会由于这行而闪退，debug模式下不闪退，develop模式下闪退，屏蔽就行了。
			//mi.fMaterialData.unknownTextures = LoadMaterialTextures(scene, aiMat, aiTextureType_UNKNOWN);

			//mi.fMaterialData = fMatData;
		}
	}
}



void FindNode(const aiScene* scene, aiNode* node, FModeldMaterialData& retdata)
{

	FindMeshWithMat(scene, node, retdata);

	for (uint32 m = 0; m < node->mNumChildren; ++m)
	{
		FindNode(scene, node->mChildren[m], retdata);
	}
}

FTransform UImportExportModelsBPLibrary::aiMatToTransform(aiMatrix4x4 NodeTransform)
{
	FMatrix mtx;
	FTransform Transform;

	// Note that assimp matrix is transpose of Unreal matrix.
	// (The compiler will efficiently unroll these loops.)
	for (int j = 0; j < 4; ++j) {
		for (int i = 0; i < 4; ++i) {
			mtx.M[i][j] = NodeTransform[j][i];
		}
	}
	Transform = FTransform(mtx);

	return Transform;
}

aiMatrix4x4 UImportExportModelsBPLibrary::TransformToAiMat(FTransform transform)
{
	aiMatrix4x4 NodeTransform;
	//FMatrix mtx = transform.ToMatrixWithScale();
	FMatrix mtx = transform.ToMatrixNoScale();

	// Note that assimp matrix is transpose of Unreal matrix.
	// (The compiler will efficiently unroll these loops.)
	for (int j = 0; j < 4; ++j)
	{
		for (int i = 0; i < 4; ++i)
		{
			NodeTransform[j][i] = mtx.M[i][j];
		}
	}

	return NodeTransform;
}

FString UImportExportModelsBPLibrary::modelFilePath = FString("");

void UImportExportModelsBPLibrary::MOpenFileDialog(const FString& DialogTitle, const FString& DefaultPath, TMap<FString, FString> FileTypeNames_FileTypes, FString& OutFileName)
{
	if (GEngine)
	{
		if (GEngine->GameViewport)
		{
			void* ParentWindowHandle = GEngine->GameViewport->GetWindow()->GetNativeWindow()->GetOSWindowHandle();

			WCHAR szFile[256];
			OPENFILENAME ofn;
			ZeroMemory(&ofn, sizeof(ofn));
			ofn.lStructSize = sizeof(ofn);
			//ofn.hwndOwner = NULL;
			ofn.hwndOwner = (HWND)ParentWindowHandle;
			ofn.lpstrFile = szFile;
			ofn.lpstrFile[0] = '\0';
			ofn.nMaxFile = sizeof(szFile);
			//ofn.lpstrFilter = TEXT("All\0*.*\0Text\0*.TXT\0");
			//ofn.lpstrFilter = TEXT("Image File(*.png)\0*.png\0");

			/*TCHAR* c_p = (TCHAR *)(*FileTypes);
			for (int i = 0; i < FileTypes.Len(); i++)
			{
				if (c_p[i] == '|')
				{
					c_p[i] = '\0';
				}
			}*/

			TArray<FString> keys;
			TArray<FString> values;
			FileTypeNames_FileTypes.GenerateKeyArray(keys);
			FileTypeNames_FileTypes.GenerateValueArray(values);

			FString temp_str = "";

			for (int i = 0; i < keys.Num(); i++)
			{
				temp_str.Append(keys[i]).Append("|").Append(values[i]).Append("|");
			}

			TCHAR* c_p = (TCHAR*)(*temp_str);
			for (int i = 0; i < temp_str.Len(); i++)
			{
				if (c_p[i] == '|')
				{
					c_p[i] = '\0';
				}
			}

			ofn.lpstrFilter = (LPCWSTR)(c_p);
			//ofn.lpstrFilter = szFilter;
			ofn.nFilterIndex = 1;
			//ofn.lpstrFileTitle = **DialogTitle;
			//ofn.lpstrFileTitle = (LPWSTR)(**DialogTitle);

			//ofn.lpstrTitle = TEXT("Open File");
			ofn.lpstrTitle = (LPCWSTR)(*DialogTitle);
			ofn.lpstrFileTitle = NULL;
			ofn.nMaxFileTitle = 0;
			if (DefaultPath.Equals(""))
			{
				ofn.lpstrInitialDir = NULL;
			}
			else
			{
				ofn.lpstrInitialDir = (LPCWSTR)(*DefaultPath);
			}

			ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
			GetOpenFileName(&ofn);

			OutFileName = FString(ofn.lpstrFile);
		}
	}
}

void UImportExportModelsBPLibrary::MSaveFileDialog(const FString& DialogTitle, const FString& DefaultPath, FString& OutFileName)
{
	if (GEngine)
	{
		if (GEngine->GameViewport)
		{
			void* ParentWindowHandle = GEngine->GameViewport->GetWindow()->GetNativeWindow()->GetOSWindowHandle();

			WCHAR szFile[256];
			OPENFILENAME ofn;
			ZeroMemory(&ofn, sizeof(ofn));
			ofn.lStructSize = sizeof(ofn);
			//ofn.hwndOwner = NULL;
			ofn.hwndOwner = (HWND)ParentWindowHandle;
			ofn.lpstrFile = szFile;
			ofn.lpstrFile[0] = '\0';
			ofn.nMaxFile = sizeof(szFile);
			//ofn.lpstrFilter = (LPCWSTR)(c_p);
			//ofn.lpstrFilter = NULL;
			//ofn.lpstrFilter = szFilter;

			TCHAR* MyFilter = (TCHAR*)TEXT("AllFile(*.fbx)\0*.*\0");
			ofn.lpstrFilter = MyFilter;
			ofn.nFilterIndex = 1;
			//ofn.lpstrFileTitle = **DialogTitle;
			//ofn.lpstrFileTitle = (LPWSTR)(**DialogTitle);

			//ofn.lpstrTitle = TEXT("Open File");
			ofn.lpstrTitle = (LPCWSTR)(*DialogTitle);
			/*ofn.lpstrFileTitle = (LPWSTR)(*FileName);
			if (!FileName.Equals(""))
			{
				ofn.lpstrFileTitle[0] = '\0';
			}*/
			//ofn.nMaxFileTitle = 256;
			ofn.lpstrFileTitle = NULL;
			ofn.nMaxFileTitle = 0;
			if (DefaultPath.Equals(""))
			{
				ofn.lpstrInitialDir = NULL;
			}
			else
			{
				ofn.lpstrInitialDir = (LPCWSTR)(*DefaultPath);
			}

			ofn.Flags = OFN_OVERWRITEPROMPT;
			//GetOpenFileName(&ofn);
			GetSaveFileName(&ofn);

			OutFileName = FString(ofn.lpstrFile);
		}
	}
}


FModeldMaterialData UImportExportModelsBPLibrary::BPImportModel(FString filepath, FTransform& outRootTransform)
{

	modelFilePath = filepath;

	FModeldMaterialData resultData;
	resultData.bSuccess = false;
	resultData.meshMatInfo.Empty();
	resultData.numMeshes = 0;

	if (filepath.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("Import Model Runtime: filepath is empty.\n"));
		return resultData;
	}

	UE_Type::UETransform transform;

	std::string file;
	file = TCHAR_TO_UTF8(*filepath);

	ImportExportLib importExporter;
	Assimp::Importer* mImporter = new Assimp::Importer();
	//const aiScene* mScenePtr = importExporter.ImportScene(mImporter, file, transform);
	const aiScene* mScenePtr = importExporter.ImportSceneExport(mImporter, file, transform);

	outRootTransform.SetScale3D(FVector(transform.scale.x, transform.scale.y, transform.scale.z));
	FRotator rot = FRotator(transform.roator.pitch, transform.roator.yaw, transform.roator.roll);
	outRootTransform.SetRotation(FQuat(rot));
	outRootTransform.SetLocation(FVector(transform.location.x, transform.location.y, transform.location.z));

	if (!mScenePtr)
	{
		/*FString ErrorCode = mImporter.GetErrorString();
		UE_LOG(LogTemp, Warning, TEXT("Import Model Runtime: Read mesh file failure.The Error Code = %s\n"), *ErrorCode);*/

		UE_LOG(LogTemp, Warning, TEXT("Import Model Runtime: Read mesh file failure. \n"));

		delete mImporter;
		return resultData;
	}

	if (mScenePtr->HasMeshes())
	{
		//UMaterial* parentMaterial = LoadObject<UMaterial>(NULL, TEXT("Material'/ImportModelRuntime/myMaterialTemplate.MyMaterialTemplate'"));

		resultData.numMeshes = mScenePtr->mNumMeshes;

		resultData.meshMatInfo.SetNum(mScenePtr->mNumMeshes, false);

		FindNode(mScenePtr, mScenePtr->mRootNode, resultData);

		for (uint32 i = 0; i < mScenePtr->mNumMeshes; ++i)
		{
			//Triangle number
			for (uint32 l = 0; l < mScenePtr->mMeshes[i]->mNumFaces; ++l)
			{
				for (uint32 m = 0; m < mScenePtr->mMeshes[i]->mFaces[l].mNumIndices; ++m)
				{
					resultData.meshMatInfo[i].Triangles.Push(mScenePtr->mMeshes[i]->mFaces[l].mIndices[m]);
				}
			}
		}

		resultData.modelFullPath = filepath;

		resultData.bSuccess = true;
	}

	delete mImporter;
	return resultData;
}

FModeldMaterialData UImportExportModelsBPLibrary::BPImportModelNormal(FString filepath, FTransform& outRootTransform)
{

	modelFilePath = filepath;

	FModeldMaterialData resultData;
	resultData.bSuccess = false;
	resultData.meshMatInfo.Empty();
	resultData.numMeshes = 0;

	if (filepath.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("Import Model Runtime: filepath is empty.\n"));
		return resultData;
	}

	UE_Type::UETransform transform;

	std::string file;
	file = TCHAR_TO_UTF8(*filepath);

	ImportExportLib importExporter;
	Assimp::Importer* mImporter = new Assimp::Importer();
	const aiScene* mScenePtr = importExporter.ImportScene(mImporter, file, transform);

	outRootTransform.SetScale3D(FVector(transform.scale.x, transform.scale.y, transform.scale.z));
	FRotator rot = FRotator(transform.roator.pitch, transform.roator.yaw, transform.roator.roll);
	outRootTransform.SetRotation(FQuat(rot));
	outRootTransform.SetLocation(FVector(transform.location.x, transform.location.y, transform.location.z));

	if (!mScenePtr)
	{
		/*FString ErrorCode = mImporter.GetErrorString();
		UE_LOG(LogTemp, Warning, TEXT("Import Model Runtime: Read mesh file failure.The Error Code = %s\n"), *ErrorCode);*/

		UE_LOG(LogTemp, Warning, TEXT("Import Model Runtime: Read mesh file failure. \n"));

		delete mImporter;
		return resultData;
	}

	if (mScenePtr->HasMeshes())
	{
		//UMaterial* parentMaterial = LoadObject<UMaterial>(NULL, TEXT("Material'/ImportModelRuntime/myMaterialTemplate.MyMaterialTemplate'"));

		resultData.numMeshes = mScenePtr->mNumMeshes;

		resultData.meshMatInfo.SetNum(mScenePtr->mNumMeshes, false);

		FindNode(mScenePtr, mScenePtr->mRootNode, resultData);

		for (uint32 i = 0; i < mScenePtr->mNumMeshes; ++i)
		{
			//Triangle number
			for (uint32 l = 0; l < mScenePtr->mMeshes[i]->mNumFaces; ++l)
			{
				for (uint32 m = 0; m < mScenePtr->mMeshes[i]->mFaces[l].mNumIndices; ++m)
				{
					resultData.meshMatInfo[i].Triangles.Push(mScenePtr->mMeshes[i]->mFaces[l].mIndices[m]);
				}
			}
		}

		resultData.modelFullPath = filepath;

		resultData.bSuccess = true;
	}

	delete mImporter;
	return resultData;
}


int UImportExportModelsBPLibrary::BPExportFBXModel(TArray<ALoadModelActor*> actors, FString outputPath)
{
	std::vector<std::string> paths;
	std::vector<UE_Type::UETransform> transforms;

	for (size_t i = 0; i < actors.Num(); i++)
	{
		std::string t_p = std::string(TCHAR_TO_UTF8(*actors[i]->modelPath));
		paths.push_back(t_p);

		FTransform trans = actors[i]->GetTransform();

		UE_Type::UETransform u_transform;
		UE_Type::UEVector u_scale = UE_Type::UEVector(trans.GetScale3D().X, trans.GetScale3D().Y, trans.GetScale3D().Z);
		UE_Type::UERotator u_rot = UE_Type::UERotator(trans.Rotator().Pitch, trans.Rotator().Yaw, trans.Rotator().Roll);
		UE_Type::UEVector u_loc = UE_Type::UEVector(trans.GetLocation().X, trans.GetLocation().Y, trans.GetLocation().Z);

		u_transform.scale = u_scale;
		u_transform.roator = u_rot;
		u_transform.location = u_loc;

		transforms.push_back(u_transform);
	}

	ImportExportLib importExporter;
	int r = importExporter.ExportFBXModel(paths, transforms, std::string(TCHAR_TO_UTF8(*outputPath)));

	return r;
}

UTexture2D* UImportExportModelsBPLibrary::ReadImgToTexture(const FString& FilePath)
{
	IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));

	TArray<uint8> RawFileData;
	UTexture2D* MyTexture = NULL;
	if (FFileHelper::LoadFileToArray(RawFileData, *FilePath /*"<path to file>"*/))
	{
		//IImageWrapperPtr ImageWrapper;
		TSharedPtr<IImageWrapper> ImageWrapper;
		FString p = TEXT(".");
		FString l_s = TEXT("");
		FString nameSuffix = FilePath;
		while (nameSuffix.Contains(p))
		{
			nameSuffix.Split(".", &l_s, &nameSuffix);
		}

		if (nameSuffix.Equals(TEXT("jpg")) || nameSuffix.Equals(TEXT("JPG")))
		{
			ImageWrapper = ImageWrapperModule.CreateImageWrapper(EImageFormat::JPEG);
		}
		else if (nameSuffix.Equals(TEXT("png")) || nameSuffix.Equals(TEXT("PNG")))
		{
			ImageWrapper = ImageWrapperModule.CreateImageWrapper(EImageFormat::PNG);
		}
		else if (nameSuffix.Equals(TEXT("bmp")) || nameSuffix.Equals(TEXT("BMP")))
		{
			ImageWrapper = ImageWrapperModule.CreateImageWrapper(EImageFormat::BMP);
		}

		if (ImageWrapper.IsValid() && ImageWrapper->SetCompressed(RawFileData.GetData(), RawFileData.Num()))
		{
			TArray<uint8> UncompressedBGRA;
			if (ImageWrapper->GetRaw(ERGBFormat::BGRA, 8, UncompressedBGRA))
			{
				// Create the UTexture for rendering
				MyTexture = UTexture2D::CreateTransient(ImageWrapper->GetWidth(), ImageWrapper->GetHeight(), PF_B8G8R8A8);

				// Fill in the source data from the file
				void* TextureData = MyTexture->GetPlatformData()->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
				FMemory::Memcpy(TextureData, UncompressedBGRA.GetData(), UncompressedBGRA.Num());
				MyTexture->GetPlatformData()->Mips[0].BulkData.Unlock();

				//MyTexture->CompressionSettings = TC_EditorIcon;
				/*MyTexture->AddressX = TA_Clamp;
				MyTexture->AddressY = TA_Clamp;*/
				MyTexture->SRGB = true;

				// Update the rendering resource from data.
				MyTexture->UpdateResource();
			}
		}
	}
	return MyTexture;
}