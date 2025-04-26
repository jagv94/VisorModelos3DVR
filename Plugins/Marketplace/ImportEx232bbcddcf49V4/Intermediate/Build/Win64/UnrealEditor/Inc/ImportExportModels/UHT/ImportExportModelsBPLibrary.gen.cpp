// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ImportExportModels/Public/ImportExportModelsBPLibrary.h"
#include "ProceduralMeshComponent/Public/ProceduralMeshComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeImportExportModelsBPLibrary() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
IMPORTEXPORTMODELS_API UClass* Z_Construct_UClass_ALoadModelActor_NoRegister();
IMPORTEXPORTMODELS_API UClass* Z_Construct_UClass_UImportExportModelsBPLibrary();
IMPORTEXPORTMODELS_API UClass* Z_Construct_UClass_UImportExportModelsBPLibrary_NoRegister();
IMPORTEXPORTMODELS_API UScriptStruct* Z_Construct_UScriptStruct_FMaterialData();
IMPORTEXPORTMODELS_API UScriptStruct* Z_Construct_UScriptStruct_FMeshMaterialData();
IMPORTEXPORTMODELS_API UScriptStruct* Z_Construct_UScriptStruct_FModeldData();
IMPORTEXPORTMODELS_API UScriptStruct* Z_Construct_UScriptStruct_FModeldMaterialData();
IMPORTEXPORTMODELS_API UScriptStruct* Z_Construct_UScriptStruct_FMyMeshData();
PROCEDURALMESHCOMPONENT_API UScriptStruct* Z_Construct_UScriptStruct_FProcMeshTangent();
UPackage* Z_Construct_UPackage__Script_ImportExportModels();
// End Cross Module References

// Begin ScriptStruct FMyMeshData
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_MyMeshData;
class UScriptStruct* FMyMeshData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_MyMeshData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_MyMeshData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMyMeshData, (UObject*)Z_Construct_UPackage__Script_ImportExportModels(), TEXT("MyMeshData"));
	}
	return Z_Registration_Info_UScriptStruct_MyMeshData.OuterSingleton;
}
template<> IMPORTEXPORTMODELS_API UScriptStruct* StaticStruct<FMyMeshData>()
{
	return FMyMeshData::StaticStruct();
}
struct Z_Construct_UScriptStruct_FMyMeshData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Vertices_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Triangles_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Normals_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UV0_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VertexColors_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Tangents_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RelativeTransform_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MatColor_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Vertices_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Vertices;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Triangles_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Triangles;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Normals_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Normals;
	static const UECodeGen_Private::FStructPropertyParams NewProp_UV0_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_UV0;
	static const UECodeGen_Private::FStructPropertyParams NewProp_VertexColors_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_VertexColors;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Tangents_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Tangents;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RelativeTransform;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MatColor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMyMeshData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMyMeshData_Statics::NewProp_Vertices_Inner = { "Vertices", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FMyMeshData_Statics::NewProp_Vertices = { "Vertices", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMyMeshData, Vertices), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Vertices_MetaData), NewProp_Vertices_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FMyMeshData_Statics::NewProp_Triangles_Inner = { "Triangles", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FMyMeshData_Statics::NewProp_Triangles = { "Triangles", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMyMeshData, Triangles), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Triangles_MetaData), NewProp_Triangles_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMyMeshData_Statics::NewProp_Normals_Inner = { "Normals", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FMyMeshData_Statics::NewProp_Normals = { "Normals", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMyMeshData, Normals), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Normals_MetaData), NewProp_Normals_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMyMeshData_Statics::NewProp_UV0_Inner = { "UV0", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FMyMeshData_Statics::NewProp_UV0 = { "UV0", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMyMeshData, UV0), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UV0_MetaData), NewProp_UV0_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMyMeshData_Statics::NewProp_VertexColors_Inner = { "VertexColors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FMyMeshData_Statics::NewProp_VertexColors = { "VertexColors", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMyMeshData, VertexColors), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VertexColors_MetaData), NewProp_VertexColors_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMyMeshData_Statics::NewProp_Tangents_Inner = { "Tangents", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FProcMeshTangent, METADATA_PARAMS(0, nullptr) }; // 4106609450
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FMyMeshData_Statics::NewProp_Tangents = { "Tangents", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMyMeshData, Tangents), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Tangents_MetaData), NewProp_Tangents_MetaData) }; // 4106609450
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMyMeshData_Statics::NewProp_RelativeTransform = { "RelativeTransform", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMyMeshData, RelativeTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RelativeTransform_MetaData), NewProp_RelativeTransform_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMyMeshData_Statics::NewProp_MatColor = { "MatColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMyMeshData, MatColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MatColor_MetaData), NewProp_MatColor_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMyMeshData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyMeshData_Statics::NewProp_Vertices_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyMeshData_Statics::NewProp_Vertices,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyMeshData_Statics::NewProp_Triangles_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyMeshData_Statics::NewProp_Triangles,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyMeshData_Statics::NewProp_Normals_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyMeshData_Statics::NewProp_Normals,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyMeshData_Statics::NewProp_UV0_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyMeshData_Statics::NewProp_UV0,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyMeshData_Statics::NewProp_VertexColors_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyMeshData_Statics::NewProp_VertexColors,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyMeshData_Statics::NewProp_Tangents_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyMeshData_Statics::NewProp_Tangents,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyMeshData_Statics::NewProp_RelativeTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyMeshData_Statics::NewProp_MatColor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMyMeshData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMyMeshData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ImportExportModels,
	nullptr,
	&NewStructOps,
	"MyMeshData",
	Z_Construct_UScriptStruct_FMyMeshData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMyMeshData_Statics::PropPointers),
	sizeof(FMyMeshData),
	alignof(FMyMeshData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMyMeshData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FMyMeshData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FMyMeshData()
{
	if (!Z_Registration_Info_UScriptStruct_MyMeshData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_MyMeshData.InnerSingleton, Z_Construct_UScriptStruct_FMyMeshData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_MyMeshData.InnerSingleton;
}
// End ScriptStruct FMyMeshData

// Begin ScriptStruct FModeldData
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ModeldData;
class UScriptStruct* FModeldData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ModeldData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ModeldData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FModeldData, (UObject*)Z_Construct_UPackage__Script_ImportExportModels(), TEXT("ModeldData"));
	}
	return Z_Registration_Info_UScriptStruct_ModeldData.OuterSingleton;
}
template<> IMPORTEXPORTMODELS_API UScriptStruct* StaticStruct<FModeldData>()
{
	return FModeldData::StaticStruct();
}
struct Z_Construct_UScriptStruct_FModeldData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSuccess_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NumMeshes_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_meshInfo_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bSuccess_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FIntPropertyParams NewProp_NumMeshes;
	static const UECodeGen_Private::FStructPropertyParams NewProp_meshInfo_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_meshInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FModeldData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
void Z_Construct_UScriptStruct_FModeldData_Statics::NewProp_bSuccess_SetBit(void* Obj)
{
	((FModeldData*)Obj)->bSuccess = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FModeldData_Statics::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FModeldData), &Z_Construct_UScriptStruct_FModeldData_Statics::NewProp_bSuccess_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSuccess_MetaData), NewProp_bSuccess_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FModeldData_Statics::NewProp_NumMeshes = { "NumMeshes", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModeldData, NumMeshes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NumMeshes_MetaData), NewProp_NumMeshes_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FModeldData_Statics::NewProp_meshInfo_Inner = { "meshInfo", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FMyMeshData, METADATA_PARAMS(0, nullptr) }; // 2265679633
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FModeldData_Statics::NewProp_meshInfo = { "meshInfo", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModeldData, meshInfo), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_meshInfo_MetaData), NewProp_meshInfo_MetaData) }; // 2265679633
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FModeldData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModeldData_Statics::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModeldData_Statics::NewProp_NumMeshes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModeldData_Statics::NewProp_meshInfo_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModeldData_Statics::NewProp_meshInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModeldData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FModeldData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ImportExportModels,
	nullptr,
	&NewStructOps,
	"ModeldData",
	Z_Construct_UScriptStruct_FModeldData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModeldData_Statics::PropPointers),
	sizeof(FModeldData),
	alignof(FModeldData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModeldData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FModeldData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FModeldData()
{
	if (!Z_Registration_Info_UScriptStruct_ModeldData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ModeldData.InnerSingleton, Z_Construct_UScriptStruct_FModeldData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_ModeldData.InnerSingleton;
}
// End ScriptStruct FModeldData

// Begin ScriptStruct FMaterialData
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_MaterialData;
class UScriptStruct* FMaterialData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_MaterialData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_MaterialData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMaterialData, (UObject*)Z_Construct_UPackage__Script_ImportExportModels(), TEXT("MaterialData"));
	}
	return Z_Registration_Info_UScriptStruct_MaterialData.OuterSingleton;
}
template<> IMPORTEXPORTMODELS_API UScriptStruct* StaticStruct<FMaterialData>()
{
	return FMaterialData::StaticStruct();
}
struct Z_Construct_UScriptStruct_FMaterialData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// add material\n" },
#endif
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "add material" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_materialName_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_baseColor_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_metallic_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_specular_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_roughness_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_emissiveColor_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_baseColor2Textures_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_specularTextures_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_emissiveTextures_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_normalTextures_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_opacityTextures_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_reflectionTextures_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_baseColorTextures_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_metalTextures_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_roughness2Textures_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ambientTextures_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_heightTextures_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_roughnessTextures_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_displacementTextures_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_lightmapTextures_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_normal_cameraTextures_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_emission_colorTextures_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ambient_occlusionTextures_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_unknownTextures_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_materialName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_baseColor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_metallic;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_specular;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_roughness;
	static const UECodeGen_Private::FStructPropertyParams NewProp_emissiveColor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_baseColor2Textures;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_specularTextures;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_emissiveTextures;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_normalTextures;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_opacityTextures;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_reflectionTextures;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_baseColorTextures;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_metalTextures;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_roughness2Textures;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ambientTextures;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_heightTextures;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_roughnessTextures;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_displacementTextures;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_lightmapTextures;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_normal_cameraTextures;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_emission_colorTextures;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ambient_occlusionTextures;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_unknownTextures_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_unknownTextures;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMaterialData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_materialName = { "materialName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMaterialData, materialName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_materialName_MetaData), NewProp_materialName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_baseColor = { "baseColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMaterialData, baseColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_baseColor_MetaData), NewProp_baseColor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_metallic = { "metallic", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMaterialData, metallic), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_metallic_MetaData), NewProp_metallic_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_specular = { "specular", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMaterialData, specular), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_specular_MetaData), NewProp_specular_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_roughness = { "roughness", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMaterialData, roughness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_roughness_MetaData), NewProp_roughness_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_emissiveColor = { "emissiveColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMaterialData, emissiveColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_emissiveColor_MetaData), NewProp_emissiveColor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_baseColor2Textures = { "baseColor2Textures", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMaterialData, baseColor2Textures), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_baseColor2Textures_MetaData), NewProp_baseColor2Textures_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_specularTextures = { "specularTextures", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMaterialData, specularTextures), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_specularTextures_MetaData), NewProp_specularTextures_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_emissiveTextures = { "emissiveTextures", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMaterialData, emissiveTextures), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_emissiveTextures_MetaData), NewProp_emissiveTextures_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_normalTextures = { "normalTextures", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMaterialData, normalTextures), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_normalTextures_MetaData), NewProp_normalTextures_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_opacityTextures = { "opacityTextures", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMaterialData, opacityTextures), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_opacityTextures_MetaData), NewProp_opacityTextures_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_reflectionTextures = { "reflectionTextures", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMaterialData, reflectionTextures), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_reflectionTextures_MetaData), NewProp_reflectionTextures_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_baseColorTextures = { "baseColorTextures", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMaterialData, baseColorTextures), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_baseColorTextures_MetaData), NewProp_baseColorTextures_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_metalTextures = { "metalTextures", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMaterialData, metalTextures), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_metalTextures_MetaData), NewProp_metalTextures_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_roughness2Textures = { "roughness2Textures", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMaterialData, roughness2Textures), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_roughness2Textures_MetaData), NewProp_roughness2Textures_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_ambientTextures = { "ambientTextures", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMaterialData, ambientTextures), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ambientTextures_MetaData), NewProp_ambientTextures_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_heightTextures = { "heightTextures", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMaterialData, heightTextures), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_heightTextures_MetaData), NewProp_heightTextures_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_roughnessTextures = { "roughnessTextures", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMaterialData, roughnessTextures), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_roughnessTextures_MetaData), NewProp_roughnessTextures_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_displacementTextures = { "displacementTextures", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMaterialData, displacementTextures), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_displacementTextures_MetaData), NewProp_displacementTextures_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_lightmapTextures = { "lightmapTextures", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMaterialData, lightmapTextures), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_lightmapTextures_MetaData), NewProp_lightmapTextures_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_normal_cameraTextures = { "normal_cameraTextures", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMaterialData, normal_cameraTextures), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_normal_cameraTextures_MetaData), NewProp_normal_cameraTextures_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_emission_colorTextures = { "emission_colorTextures", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMaterialData, emission_colorTextures), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_emission_colorTextures_MetaData), NewProp_emission_colorTextures_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_ambient_occlusionTextures = { "ambient_occlusionTextures", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMaterialData, ambient_occlusionTextures), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ambient_occlusionTextures_MetaData), NewProp_ambient_occlusionTextures_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_unknownTextures_Inner = { "unknownTextures", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_unknownTextures = { "unknownTextures", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMaterialData, unknownTextures), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_unknownTextures_MetaData), NewProp_unknownTextures_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMaterialData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_materialName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_baseColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_metallic,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_specular,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_roughness,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_emissiveColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_baseColor2Textures,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_specularTextures,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_emissiveTextures,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_normalTextures,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_opacityTextures,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_reflectionTextures,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_baseColorTextures,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_metalTextures,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_roughness2Textures,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_ambientTextures,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_heightTextures,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_roughnessTextures,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_displacementTextures,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_lightmapTextures,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_normal_cameraTextures,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_emission_colorTextures,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_ambient_occlusionTextures,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_unknownTextures_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMaterialData_Statics::NewProp_unknownTextures,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMaterialData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMaterialData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ImportExportModels,
	nullptr,
	&NewStructOps,
	"MaterialData",
	Z_Construct_UScriptStruct_FMaterialData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMaterialData_Statics::PropPointers),
	sizeof(FMaterialData),
	alignof(FMaterialData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMaterialData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FMaterialData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FMaterialData()
{
	if (!Z_Registration_Info_UScriptStruct_MaterialData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_MaterialData.InnerSingleton, Z_Construct_UScriptStruct_FMaterialData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_MaterialData.InnerSingleton;
}
// End ScriptStruct FMaterialData

// Begin ScriptStruct FMeshMaterialData
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_MeshMaterialData;
class UScriptStruct* FMeshMaterialData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_MeshMaterialData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_MeshMaterialData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMeshMaterialData, (UObject*)Z_Construct_UPackage__Script_ImportExportModels(), TEXT("MeshMaterialData"));
	}
	return Z_Registration_Info_UScriptStruct_MeshMaterialData.OuterSingleton;
}
template<> IMPORTEXPORTMODELS_API UScriptStruct* StaticStruct<FMeshMaterialData>()
{
	return FMeshMaterialData::StaticStruct();
}
struct Z_Construct_UScriptStruct_FMeshMaterialData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// add material\n" },
#endif
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "add material" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_tMeshName_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Vertices_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Triangles_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Normals_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UV0_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VertexColors_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Tangents_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RelativeTransform_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_fMaterialData_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_tMeshName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Vertices_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Vertices;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Triangles_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Triangles;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Normals_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Normals;
	static const UECodeGen_Private::FStructPropertyParams NewProp_UV0_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_UV0;
	static const UECodeGen_Private::FStructPropertyParams NewProp_VertexColors_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_VertexColors;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Tangents_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Tangents;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RelativeTransform;
	static const UECodeGen_Private::FStructPropertyParams NewProp_fMaterialData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMeshMaterialData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_tMeshName = { "tMeshName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMeshMaterialData, tMeshName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_tMeshName_MetaData), NewProp_tMeshName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_Vertices_Inner = { "Vertices", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_Vertices = { "Vertices", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMeshMaterialData, Vertices), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Vertices_MetaData), NewProp_Vertices_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_Triangles_Inner = { "Triangles", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_Triangles = { "Triangles", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMeshMaterialData, Triangles), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Triangles_MetaData), NewProp_Triangles_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_Normals_Inner = { "Normals", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_Normals = { "Normals", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMeshMaterialData, Normals), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Normals_MetaData), NewProp_Normals_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_UV0_Inner = { "UV0", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_UV0 = { "UV0", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMeshMaterialData, UV0), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UV0_MetaData), NewProp_UV0_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_VertexColors_Inner = { "VertexColors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_VertexColors = { "VertexColors", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMeshMaterialData, VertexColors), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VertexColors_MetaData), NewProp_VertexColors_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_Tangents_Inner = { "Tangents", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FProcMeshTangent, METADATA_PARAMS(0, nullptr) }; // 4106609450
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_Tangents = { "Tangents", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMeshMaterialData, Tangents), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Tangents_MetaData), NewProp_Tangents_MetaData) }; // 4106609450
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_RelativeTransform = { "RelativeTransform", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMeshMaterialData, RelativeTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RelativeTransform_MetaData), NewProp_RelativeTransform_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_fMaterialData = { "fMaterialData", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMeshMaterialData, fMaterialData), Z_Construct_UScriptStruct_FMaterialData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_fMaterialData_MetaData), NewProp_fMaterialData_MetaData) }; // 1084220933
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMeshMaterialData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_tMeshName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_Vertices_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_Vertices,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_Triangles_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_Triangles,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_Normals_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_Normals,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_UV0_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_UV0,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_VertexColors_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_VertexColors,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_Tangents_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_Tangents,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_RelativeTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_fMaterialData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshMaterialData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMeshMaterialData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ImportExportModels,
	nullptr,
	&NewStructOps,
	"MeshMaterialData",
	Z_Construct_UScriptStruct_FMeshMaterialData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshMaterialData_Statics::PropPointers),
	sizeof(FMeshMaterialData),
	alignof(FMeshMaterialData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshMaterialData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FMeshMaterialData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FMeshMaterialData()
{
	if (!Z_Registration_Info_UScriptStruct_MeshMaterialData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_MeshMaterialData.InnerSingleton, Z_Construct_UScriptStruct_FMeshMaterialData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_MeshMaterialData.InnerSingleton;
}
// End ScriptStruct FMeshMaterialData

// Begin ScriptStruct FModeldMaterialData
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ModeldMaterialData;
class UScriptStruct* FModeldMaterialData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ModeldMaterialData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ModeldMaterialData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FModeldMaterialData, (UObject*)Z_Construct_UPackage__Script_ImportExportModels(), TEXT("ModeldMaterialData"));
	}
	return Z_Registration_Info_UScriptStruct_ModeldMaterialData.OuterSingleton;
}
template<> IMPORTEXPORTMODELS_API UScriptStruct* StaticStruct<FModeldMaterialData>()
{
	return FModeldMaterialData::StaticStruct();
}
struct Z_Construct_UScriptStruct_FModeldMaterialData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSuccess_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_numMeshes_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_meshMatInfo_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_modelFullPath_MetaData[] = {
		{ "Category", "ReturnedData" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bSuccess_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FIntPropertyParams NewProp_numMeshes;
	static const UECodeGen_Private::FStructPropertyParams NewProp_meshMatInfo_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_meshMatInfo;
	static const UECodeGen_Private::FStrPropertyParams NewProp_modelFullPath;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FModeldMaterialData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
void Z_Construct_UScriptStruct_FModeldMaterialData_Statics::NewProp_bSuccess_SetBit(void* Obj)
{
	((FModeldMaterialData*)Obj)->bSuccess = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FModeldMaterialData_Statics::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FModeldMaterialData), &Z_Construct_UScriptStruct_FModeldMaterialData_Statics::NewProp_bSuccess_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSuccess_MetaData), NewProp_bSuccess_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FModeldMaterialData_Statics::NewProp_numMeshes = { "numMeshes", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModeldMaterialData, numMeshes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_numMeshes_MetaData), NewProp_numMeshes_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FModeldMaterialData_Statics::NewProp_meshMatInfo_Inner = { "meshMatInfo", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FMeshMaterialData, METADATA_PARAMS(0, nullptr) }; // 2592531516
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FModeldMaterialData_Statics::NewProp_meshMatInfo = { "meshMatInfo", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModeldMaterialData, meshMatInfo), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_meshMatInfo_MetaData), NewProp_meshMatInfo_MetaData) }; // 2592531516
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FModeldMaterialData_Statics::NewProp_modelFullPath = { "modelFullPath", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModeldMaterialData, modelFullPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_modelFullPath_MetaData), NewProp_modelFullPath_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FModeldMaterialData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModeldMaterialData_Statics::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModeldMaterialData_Statics::NewProp_numMeshes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModeldMaterialData_Statics::NewProp_meshMatInfo_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModeldMaterialData_Statics::NewProp_meshMatInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModeldMaterialData_Statics::NewProp_modelFullPath,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModeldMaterialData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FModeldMaterialData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ImportExportModels,
	nullptr,
	&NewStructOps,
	"ModeldMaterialData",
	Z_Construct_UScriptStruct_FModeldMaterialData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModeldMaterialData_Statics::PropPointers),
	sizeof(FModeldMaterialData),
	alignof(FModeldMaterialData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModeldMaterialData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FModeldMaterialData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FModeldMaterialData()
{
	if (!Z_Registration_Info_UScriptStruct_ModeldMaterialData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ModeldMaterialData.InnerSingleton, Z_Construct_UScriptStruct_FModeldMaterialData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_ModeldMaterialData.InnerSingleton;
}
// End ScriptStruct FModeldMaterialData

// Begin Class UImportExportModelsBPLibrary Function BPExportFBXModel
struct Z_Construct_UFunction_UImportExportModelsBPLibrary_BPExportFBXModel_Statics
{
	struct ImportExportModelsBPLibrary_eventBPExportFBXModel_Parms
	{
		TArray<ALoadModelActor*> actors;
		FString outputPath;
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ImportExportModelsBPLibrary" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_actors_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_actors;
	static const UECodeGen_Private::FStrPropertyParams NewProp_outputPath;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UImportExportModelsBPLibrary_BPExportFBXModel_Statics::NewProp_actors_Inner = { "actors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_ALoadModelActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UImportExportModelsBPLibrary_BPExportFBXModel_Statics::NewProp_actors = { "actors", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ImportExportModelsBPLibrary_eventBPExportFBXModel_Parms, actors), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UImportExportModelsBPLibrary_BPExportFBXModel_Statics::NewProp_outputPath = { "outputPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ImportExportModelsBPLibrary_eventBPExportFBXModel_Parms, outputPath), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UImportExportModelsBPLibrary_BPExportFBXModel_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ImportExportModelsBPLibrary_eventBPExportFBXModel_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UImportExportModelsBPLibrary_BPExportFBXModel_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UImportExportModelsBPLibrary_BPExportFBXModel_Statics::NewProp_actors_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UImportExportModelsBPLibrary_BPExportFBXModel_Statics::NewProp_actors,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UImportExportModelsBPLibrary_BPExportFBXModel_Statics::NewProp_outputPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UImportExportModelsBPLibrary_BPExportFBXModel_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UImportExportModelsBPLibrary_BPExportFBXModel_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UImportExportModelsBPLibrary_BPExportFBXModel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UImportExportModelsBPLibrary, nullptr, "BPExportFBXModel", nullptr, nullptr, Z_Construct_UFunction_UImportExportModelsBPLibrary_BPExportFBXModel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UImportExportModelsBPLibrary_BPExportFBXModel_Statics::PropPointers), sizeof(Z_Construct_UFunction_UImportExportModelsBPLibrary_BPExportFBXModel_Statics::ImportExportModelsBPLibrary_eventBPExportFBXModel_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UImportExportModelsBPLibrary_BPExportFBXModel_Statics::Function_MetaDataParams), Z_Construct_UFunction_UImportExportModelsBPLibrary_BPExportFBXModel_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UImportExportModelsBPLibrary_BPExportFBXModel_Statics::ImportExportModelsBPLibrary_eventBPExportFBXModel_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UImportExportModelsBPLibrary_BPExportFBXModel()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UImportExportModelsBPLibrary_BPExportFBXModel_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UImportExportModelsBPLibrary::execBPExportFBXModel)
{
	P_GET_TARRAY(ALoadModelActor*,Z_Param_actors);
	P_GET_PROPERTY(FStrProperty,Z_Param_outputPath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=UImportExportModelsBPLibrary::BPExportFBXModel(Z_Param_actors,Z_Param_outputPath);
	P_NATIVE_END;
}
// End Class UImportExportModelsBPLibrary Function BPExportFBXModel

// Begin Class UImportExportModelsBPLibrary Function BPImportModel
struct Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModel_Statics
{
	struct ImportExportModelsBPLibrary_eventBPImportModel_Parms
	{
		FString filepath;
		FTransform outRootTransform;
		FModeldMaterialData ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ImportExportModelsBPLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xda\xb5\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xca\xb1\xca\xb9\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xda\xb5\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xca\xb1\xca\xb9\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_filepath;
	static const UECodeGen_Private::FStructPropertyParams NewProp_outRootTransform;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModel_Statics::NewProp_filepath = { "filepath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ImportExportModelsBPLibrary_eventBPImportModel_Parms, filepath), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModel_Statics::NewProp_outRootTransform = { "outRootTransform", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ImportExportModelsBPLibrary_eventBPImportModel_Parms, outRootTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModel_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ImportExportModelsBPLibrary_eventBPImportModel_Parms, ReturnValue), Z_Construct_UScriptStruct_FModeldMaterialData, METADATA_PARAMS(0, nullptr) }; // 2953274819
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModel_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModel_Statics::NewProp_filepath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModel_Statics::NewProp_outRootTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModel_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModel_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UImportExportModelsBPLibrary, nullptr, "BPImportModel", nullptr, nullptr, Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModel_Statics::PropPointers), sizeof(Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModel_Statics::ImportExportModelsBPLibrary_eventBPImportModel_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModel_Statics::Function_MetaDataParams), Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModel_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModel_Statics::ImportExportModelsBPLibrary_eventBPImportModel_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModel()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModel_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UImportExportModelsBPLibrary::execBPImportModel)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_filepath);
	P_GET_STRUCT_REF(FTransform,Z_Param_Out_outRootTransform);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FModeldMaterialData*)Z_Param__Result=UImportExportModelsBPLibrary::BPImportModel(Z_Param_filepath,Z_Param_Out_outRootTransform);
	P_NATIVE_END;
}
// End Class UImportExportModelsBPLibrary Function BPImportModel

// Begin Class UImportExportModelsBPLibrary Function BPImportModelNormal
struct Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModelNormal_Statics
{
	struct ImportExportModelsBPLibrary_eventBPImportModelNormal_Parms
	{
		FString filepath;
		FTransform outRootTransform;
		FModeldMaterialData ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ImportExportModelsBPLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\xcd\xa8\xef\xbf\xbd\xc3\xb5\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xcd\xa8\xef\xbf\xbd\xc3\xb5\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_filepath;
	static const UECodeGen_Private::FStructPropertyParams NewProp_outRootTransform;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModelNormal_Statics::NewProp_filepath = { "filepath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ImportExportModelsBPLibrary_eventBPImportModelNormal_Parms, filepath), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModelNormal_Statics::NewProp_outRootTransform = { "outRootTransform", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ImportExportModelsBPLibrary_eventBPImportModelNormal_Parms, outRootTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModelNormal_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ImportExportModelsBPLibrary_eventBPImportModelNormal_Parms, ReturnValue), Z_Construct_UScriptStruct_FModeldMaterialData, METADATA_PARAMS(0, nullptr) }; // 2953274819
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModelNormal_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModelNormal_Statics::NewProp_filepath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModelNormal_Statics::NewProp_outRootTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModelNormal_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModelNormal_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModelNormal_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UImportExportModelsBPLibrary, nullptr, "BPImportModelNormal", nullptr, nullptr, Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModelNormal_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModelNormal_Statics::PropPointers), sizeof(Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModelNormal_Statics::ImportExportModelsBPLibrary_eventBPImportModelNormal_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModelNormal_Statics::Function_MetaDataParams), Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModelNormal_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModelNormal_Statics::ImportExportModelsBPLibrary_eventBPImportModelNormal_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModelNormal()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModelNormal_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UImportExportModelsBPLibrary::execBPImportModelNormal)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_filepath);
	P_GET_STRUCT_REF(FTransform,Z_Param_Out_outRootTransform);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FModeldMaterialData*)Z_Param__Result=UImportExportModelsBPLibrary::BPImportModelNormal(Z_Param_filepath,Z_Param_Out_outRootTransform);
	P_NATIVE_END;
}
// End Class UImportExportModelsBPLibrary Function BPImportModelNormal

// Begin Class UImportExportModelsBPLibrary Function MOpenFileDialog
struct Z_Construct_UFunction_UImportExportModelsBPLibrary_MOpenFileDialog_Statics
{
	struct ImportExportModelsBPLibrary_eventMOpenFileDialog_Parms
	{
		FString DialogTitle;
		FString DefaultPath;
		TMap<FString,FString> FileTypeNames_FileTypes;
		FString OutFileName;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ImportExportModelsBPLibrary" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DialogTitle_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_DialogTitle;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DefaultPath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileTypeNames_FileTypes_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileTypeNames_FileTypes_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_FileTypeNames_FileTypes;
	static const UECodeGen_Private::FStrPropertyParams NewProp_OutFileName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UImportExportModelsBPLibrary_MOpenFileDialog_Statics::NewProp_DialogTitle = { "DialogTitle", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ImportExportModelsBPLibrary_eventMOpenFileDialog_Parms, DialogTitle), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DialogTitle_MetaData), NewProp_DialogTitle_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UImportExportModelsBPLibrary_MOpenFileDialog_Statics::NewProp_DefaultPath = { "DefaultPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ImportExportModelsBPLibrary_eventMOpenFileDialog_Parms, DefaultPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultPath_MetaData), NewProp_DefaultPath_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UImportExportModelsBPLibrary_MOpenFileDialog_Statics::NewProp_FileTypeNames_FileTypes_ValueProp = { "FileTypeNames_FileTypes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UImportExportModelsBPLibrary_MOpenFileDialog_Statics::NewProp_FileTypeNames_FileTypes_Key_KeyProp = { "FileTypeNames_FileTypes_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UImportExportModelsBPLibrary_MOpenFileDialog_Statics::NewProp_FileTypeNames_FileTypes = { "FileTypeNames_FileTypes", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ImportExportModelsBPLibrary_eventMOpenFileDialog_Parms, FileTypeNames_FileTypes), EMapPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UImportExportModelsBPLibrary_MOpenFileDialog_Statics::NewProp_OutFileName = { "OutFileName", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ImportExportModelsBPLibrary_eventMOpenFileDialog_Parms, OutFileName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UImportExportModelsBPLibrary_MOpenFileDialog_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UImportExportModelsBPLibrary_MOpenFileDialog_Statics::NewProp_DialogTitle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UImportExportModelsBPLibrary_MOpenFileDialog_Statics::NewProp_DefaultPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UImportExportModelsBPLibrary_MOpenFileDialog_Statics::NewProp_FileTypeNames_FileTypes_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UImportExportModelsBPLibrary_MOpenFileDialog_Statics::NewProp_FileTypeNames_FileTypes_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UImportExportModelsBPLibrary_MOpenFileDialog_Statics::NewProp_FileTypeNames_FileTypes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UImportExportModelsBPLibrary_MOpenFileDialog_Statics::NewProp_OutFileName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UImportExportModelsBPLibrary_MOpenFileDialog_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UImportExportModelsBPLibrary_MOpenFileDialog_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UImportExportModelsBPLibrary, nullptr, "MOpenFileDialog", nullptr, nullptr, Z_Construct_UFunction_UImportExportModelsBPLibrary_MOpenFileDialog_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UImportExportModelsBPLibrary_MOpenFileDialog_Statics::PropPointers), sizeof(Z_Construct_UFunction_UImportExportModelsBPLibrary_MOpenFileDialog_Statics::ImportExportModelsBPLibrary_eventMOpenFileDialog_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UImportExportModelsBPLibrary_MOpenFileDialog_Statics::Function_MetaDataParams), Z_Construct_UFunction_UImportExportModelsBPLibrary_MOpenFileDialog_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UImportExportModelsBPLibrary_MOpenFileDialog_Statics::ImportExportModelsBPLibrary_eventMOpenFileDialog_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UImportExportModelsBPLibrary_MOpenFileDialog()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UImportExportModelsBPLibrary_MOpenFileDialog_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UImportExportModelsBPLibrary::execMOpenFileDialog)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_DialogTitle);
	P_GET_PROPERTY(FStrProperty,Z_Param_DefaultPath);
	P_GET_TMAP(FString,FString,Z_Param_FileTypeNames_FileTypes);
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_OutFileName);
	P_FINISH;
	P_NATIVE_BEGIN;
	UImportExportModelsBPLibrary::MOpenFileDialog(Z_Param_DialogTitle,Z_Param_DefaultPath,Z_Param_FileTypeNames_FileTypes,Z_Param_Out_OutFileName);
	P_NATIVE_END;
}
// End Class UImportExportModelsBPLibrary Function MOpenFileDialog

// Begin Class UImportExportModelsBPLibrary Function MSaveFileDialog
struct Z_Construct_UFunction_UImportExportModelsBPLibrary_MSaveFileDialog_Statics
{
	struct ImportExportModelsBPLibrary_eventMSaveFileDialog_Parms
	{
		FString DialogTitle;
		FString DefaultPath;
		FString OutFileName;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OpenFileBrowser" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DialogTitle_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_DialogTitle;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DefaultPath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_OutFileName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UImportExportModelsBPLibrary_MSaveFileDialog_Statics::NewProp_DialogTitle = { "DialogTitle", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ImportExportModelsBPLibrary_eventMSaveFileDialog_Parms, DialogTitle), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DialogTitle_MetaData), NewProp_DialogTitle_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UImportExportModelsBPLibrary_MSaveFileDialog_Statics::NewProp_DefaultPath = { "DefaultPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ImportExportModelsBPLibrary_eventMSaveFileDialog_Parms, DefaultPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultPath_MetaData), NewProp_DefaultPath_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UImportExportModelsBPLibrary_MSaveFileDialog_Statics::NewProp_OutFileName = { "OutFileName", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ImportExportModelsBPLibrary_eventMSaveFileDialog_Parms, OutFileName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UImportExportModelsBPLibrary_MSaveFileDialog_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UImportExportModelsBPLibrary_MSaveFileDialog_Statics::NewProp_DialogTitle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UImportExportModelsBPLibrary_MSaveFileDialog_Statics::NewProp_DefaultPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UImportExportModelsBPLibrary_MSaveFileDialog_Statics::NewProp_OutFileName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UImportExportModelsBPLibrary_MSaveFileDialog_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UImportExportModelsBPLibrary_MSaveFileDialog_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UImportExportModelsBPLibrary, nullptr, "MSaveFileDialog", nullptr, nullptr, Z_Construct_UFunction_UImportExportModelsBPLibrary_MSaveFileDialog_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UImportExportModelsBPLibrary_MSaveFileDialog_Statics::PropPointers), sizeof(Z_Construct_UFunction_UImportExportModelsBPLibrary_MSaveFileDialog_Statics::ImportExportModelsBPLibrary_eventMSaveFileDialog_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UImportExportModelsBPLibrary_MSaveFileDialog_Statics::Function_MetaDataParams), Z_Construct_UFunction_UImportExportModelsBPLibrary_MSaveFileDialog_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UImportExportModelsBPLibrary_MSaveFileDialog_Statics::ImportExportModelsBPLibrary_eventMSaveFileDialog_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UImportExportModelsBPLibrary_MSaveFileDialog()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UImportExportModelsBPLibrary_MSaveFileDialog_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UImportExportModelsBPLibrary::execMSaveFileDialog)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_DialogTitle);
	P_GET_PROPERTY(FStrProperty,Z_Param_DefaultPath);
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_OutFileName);
	P_FINISH;
	P_NATIVE_BEGIN;
	UImportExportModelsBPLibrary::MSaveFileDialog(Z_Param_DialogTitle,Z_Param_DefaultPath,Z_Param_Out_OutFileName);
	P_NATIVE_END;
}
// End Class UImportExportModelsBPLibrary Function MSaveFileDialog

// Begin Class UImportExportModelsBPLibrary Function ReadImgToTexture
struct Z_Construct_UFunction_UImportExportModelsBPLibrary_ReadImgToTexture_Statics
{
	struct ImportExportModelsBPLibrary_eventReadImgToTexture_Parms
	{
		FString FilePath;
		UTexture2D* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ImportExportModelsBPLibrary" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FilePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_FilePath;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UImportExportModelsBPLibrary_ReadImgToTexture_Statics::NewProp_FilePath = { "FilePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ImportExportModelsBPLibrary_eventReadImgToTexture_Parms, FilePath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FilePath_MetaData), NewProp_FilePath_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UImportExportModelsBPLibrary_ReadImgToTexture_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ImportExportModelsBPLibrary_eventReadImgToTexture_Parms, ReturnValue), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UImportExportModelsBPLibrary_ReadImgToTexture_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UImportExportModelsBPLibrary_ReadImgToTexture_Statics::NewProp_FilePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UImportExportModelsBPLibrary_ReadImgToTexture_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UImportExportModelsBPLibrary_ReadImgToTexture_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UImportExportModelsBPLibrary_ReadImgToTexture_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UImportExportModelsBPLibrary, nullptr, "ReadImgToTexture", nullptr, nullptr, Z_Construct_UFunction_UImportExportModelsBPLibrary_ReadImgToTexture_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UImportExportModelsBPLibrary_ReadImgToTexture_Statics::PropPointers), sizeof(Z_Construct_UFunction_UImportExportModelsBPLibrary_ReadImgToTexture_Statics::ImportExportModelsBPLibrary_eventReadImgToTexture_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UImportExportModelsBPLibrary_ReadImgToTexture_Statics::Function_MetaDataParams), Z_Construct_UFunction_UImportExportModelsBPLibrary_ReadImgToTexture_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UImportExportModelsBPLibrary_ReadImgToTexture_Statics::ImportExportModelsBPLibrary_eventReadImgToTexture_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UImportExportModelsBPLibrary_ReadImgToTexture()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UImportExportModelsBPLibrary_ReadImgToTexture_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UImportExportModelsBPLibrary::execReadImgToTexture)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FilePath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UTexture2D**)Z_Param__Result=UImportExportModelsBPLibrary::ReadImgToTexture(Z_Param_FilePath);
	P_NATIVE_END;
}
// End Class UImportExportModelsBPLibrary Function ReadImgToTexture

// Begin Class UImportExportModelsBPLibrary
void UImportExportModelsBPLibrary::StaticRegisterNativesUImportExportModelsBPLibrary()
{
	UClass* Class = UImportExportModelsBPLibrary::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "BPExportFBXModel", &UImportExportModelsBPLibrary::execBPExportFBXModel },
		{ "BPImportModel", &UImportExportModelsBPLibrary::execBPImportModel },
		{ "BPImportModelNormal", &UImportExportModelsBPLibrary::execBPImportModelNormal },
		{ "MOpenFileDialog", &UImportExportModelsBPLibrary::execMOpenFileDialog },
		{ "MSaveFileDialog", &UImportExportModelsBPLibrary::execMSaveFileDialog },
		{ "ReadImgToTexture", &UImportExportModelsBPLibrary::execReadImgToTexture },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UImportExportModelsBPLibrary);
UClass* Z_Construct_UClass_UImportExportModelsBPLibrary_NoRegister()
{
	return UImportExportModelsBPLibrary::StaticClass();
}
struct Z_Construct_UClass_UImportExportModelsBPLibrary_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "ImportExportModelsBPLibrary.h" },
		{ "ModuleRelativePath", "Public/ImportExportModelsBPLibrary.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UImportExportModelsBPLibrary_BPExportFBXModel, "BPExportFBXModel" }, // 3143151417
		{ &Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModel, "BPImportModel" }, // 1922907664
		{ &Z_Construct_UFunction_UImportExportModelsBPLibrary_BPImportModelNormal, "BPImportModelNormal" }, // 3815882902
		{ &Z_Construct_UFunction_UImportExportModelsBPLibrary_MOpenFileDialog, "MOpenFileDialog" }, // 1818377977
		{ &Z_Construct_UFunction_UImportExportModelsBPLibrary_MSaveFileDialog, "MSaveFileDialog" }, // 2400800467
		{ &Z_Construct_UFunction_UImportExportModelsBPLibrary_ReadImgToTexture, "ReadImgToTexture" }, // 10951553
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UImportExportModelsBPLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UImportExportModelsBPLibrary_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_ImportExportModels,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UImportExportModelsBPLibrary_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UImportExportModelsBPLibrary_Statics::ClassParams = {
	&UImportExportModelsBPLibrary::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UImportExportModelsBPLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UImportExportModelsBPLibrary_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UImportExportModelsBPLibrary()
{
	if (!Z_Registration_Info_UClass_UImportExportModelsBPLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UImportExportModelsBPLibrary.OuterSingleton, Z_Construct_UClass_UImportExportModelsBPLibrary_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UImportExportModelsBPLibrary.OuterSingleton;
}
template<> IMPORTEXPORTMODELS_API UClass* StaticClass<UImportExportModelsBPLibrary>()
{
	return UImportExportModelsBPLibrary::StaticClass();
}
UImportExportModelsBPLibrary::UImportExportModelsBPLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UImportExportModelsBPLibrary);
UImportExportModelsBPLibrary::~UImportExportModelsBPLibrary() {}
// End Class UImportExportModelsBPLibrary

// Begin Registration
struct Z_CompiledInDeferFile_FID_VisorModelos3DVR_Plugins_Marketplace_ImportEx232bbcddcf49V4_Source_ImportExportModels_Public_ImportExportModelsBPLibrary_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FMyMeshData::StaticStruct, Z_Construct_UScriptStruct_FMyMeshData_Statics::NewStructOps, TEXT("MyMeshData"), &Z_Registration_Info_UScriptStruct_MyMeshData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMyMeshData), 2265679633U) },
		{ FModeldData::StaticStruct, Z_Construct_UScriptStruct_FModeldData_Statics::NewStructOps, TEXT("ModeldData"), &Z_Registration_Info_UScriptStruct_ModeldData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FModeldData), 1583714388U) },
		{ FMaterialData::StaticStruct, Z_Construct_UScriptStruct_FMaterialData_Statics::NewStructOps, TEXT("MaterialData"), &Z_Registration_Info_UScriptStruct_MaterialData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMaterialData), 1084220933U) },
		{ FMeshMaterialData::StaticStruct, Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewStructOps, TEXT("MeshMaterialData"), &Z_Registration_Info_UScriptStruct_MeshMaterialData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMeshMaterialData), 2592531516U) },
		{ FModeldMaterialData::StaticStruct, Z_Construct_UScriptStruct_FModeldMaterialData_Statics::NewStructOps, TEXT("ModeldMaterialData"), &Z_Registration_Info_UScriptStruct_ModeldMaterialData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FModeldMaterialData), 2953274819U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UImportExportModelsBPLibrary, UImportExportModelsBPLibrary::StaticClass, TEXT("UImportExportModelsBPLibrary"), &Z_Registration_Info_UClass_UImportExportModelsBPLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UImportExportModelsBPLibrary), 3829329853U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_VisorModelos3DVR_Plugins_Marketplace_ImportEx232bbcddcf49V4_Source_ImportExportModels_Public_ImportExportModelsBPLibrary_h_2082081816(TEXT("/Script/ImportExportModels"),
	Z_CompiledInDeferFile_FID_VisorModelos3DVR_Plugins_Marketplace_ImportEx232bbcddcf49V4_Source_ImportExportModels_Public_ImportExportModelsBPLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_VisorModelos3DVR_Plugins_Marketplace_ImportEx232bbcddcf49V4_Source_ImportExportModels_Public_ImportExportModelsBPLibrary_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_VisorModelos3DVR_Plugins_Marketplace_ImportEx232bbcddcf49V4_Source_ImportExportModels_Public_ImportExportModelsBPLibrary_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_VisorModelos3DVR_Plugins_Marketplace_ImportEx232bbcddcf49V4_Source_ImportExportModels_Public_ImportExportModelsBPLibrary_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
