// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ImportExportModels/Public/LoadModelActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLoadModelActor() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
IMPORTEXPORTMODELS_API UClass* Z_Construct_UClass_ALoadModelActor();
IMPORTEXPORTMODELS_API UClass* Z_Construct_UClass_ALoadModelActor_NoRegister();
UPackage* Z_Construct_UPackage__Script_ImportExportModels();
// End Cross Module References

// Begin Class ALoadModelActor
void ALoadModelActor::StaticRegisterNativesALoadModelActor()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ALoadModelActor);
UClass* Z_Construct_UClass_ALoadModelActor_NoRegister()
{
	return ALoadModelActor::StaticClass();
}
struct Z_Construct_UClass_ALoadModelActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "LoadModelActor.h" },
		{ "ModuleRelativePath", "Public/LoadModelActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_modelPath_MetaData[] = {
		{ "Category", "ImportExportModelsBPLibrary" },
		{ "ModuleRelativePath", "Public/LoadModelActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_modelPath;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALoadModelActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_ALoadModelActor_Statics::NewProp_modelPath = { "modelPath", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ALoadModelActor, modelPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_modelPath_MetaData), NewProp_modelPath_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ALoadModelActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALoadModelActor_Statics::NewProp_modelPath,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ALoadModelActor_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ALoadModelActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_ImportExportModels,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ALoadModelActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ALoadModelActor_Statics::ClassParams = {
	&ALoadModelActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ALoadModelActor_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ALoadModelActor_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ALoadModelActor_Statics::Class_MetaDataParams), Z_Construct_UClass_ALoadModelActor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ALoadModelActor()
{
	if (!Z_Registration_Info_UClass_ALoadModelActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ALoadModelActor.OuterSingleton, Z_Construct_UClass_ALoadModelActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ALoadModelActor.OuterSingleton;
}
template<> IMPORTEXPORTMODELS_API UClass* StaticClass<ALoadModelActor>()
{
	return ALoadModelActor::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ALoadModelActor);
ALoadModelActor::~ALoadModelActor() {}
// End Class ALoadModelActor

// Begin Registration
struct Z_CompiledInDeferFile_FID_VisorModelos3DVR_Plugins_Marketplace_ImportEx232bbcddcf49V4_Source_ImportExportModels_Public_LoadModelActor_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ALoadModelActor, ALoadModelActor::StaticClass, TEXT("ALoadModelActor"), &Z_Registration_Info_UClass_ALoadModelActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ALoadModelActor), 3750875361U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_VisorModelos3DVR_Plugins_Marketplace_ImportEx232bbcddcf49V4_Source_ImportExportModels_Public_LoadModelActor_h_2475635901(TEXT("/Script/ImportExportModels"),
	Z_CompiledInDeferFile_FID_VisorModelos3DVR_Plugins_Marketplace_ImportEx232bbcddcf49V4_Source_ImportExportModels_Public_LoadModelActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_VisorModelos3DVR_Plugins_Marketplace_ImportEx232bbcddcf49V4_Source_ImportExportModels_Public_LoadModelActor_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
