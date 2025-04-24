// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ImportExportModelsBPLibrary.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
 
class ALoadModelActor;
class UTexture2D;
struct FModeldMaterialData;
#ifdef IMPORTEXPORTMODELS_ImportExportModelsBPLibrary_generated_h
#error "ImportExportModelsBPLibrary.generated.h already included, missing '#pragma once' in ImportExportModelsBPLibrary.h"
#endif
#define IMPORTEXPORTMODELS_ImportExportModelsBPLibrary_generated_h

#define FID_TestProject_Plugins_Marketplace_ImportEx232bbcddcf49V4_Source_ImportExportModels_Public_ImportExportModelsBPLibrary_h_19_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMyMeshData_Statics; \
	IMPORTEXPORTMODELS_API static class UScriptStruct* StaticStruct();


template<> IMPORTEXPORTMODELS_API UScriptStruct* StaticStruct<struct FMyMeshData>();

#define FID_TestProject_Plugins_Marketplace_ImportEx232bbcddcf49V4_Source_ImportExportModels_Public_ImportExportModelsBPLibrary_h_49_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FModeldData_Statics; \
	IMPORTEXPORTMODELS_API static class UScriptStruct* StaticStruct();


template<> IMPORTEXPORTMODELS_API UScriptStruct* StaticStruct<struct FModeldData>();

#define FID_TestProject_Plugins_Marketplace_ImportEx232bbcddcf49V4_Source_ImportExportModels_Public_ImportExportModelsBPLibrary_h_66_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMaterialData_Statics; \
	IMPORTEXPORTMODELS_API static class UScriptStruct* StaticStruct();


template<> IMPORTEXPORTMODELS_API UScriptStruct* StaticStruct<struct FMaterialData>();

#define FID_TestProject_Plugins_Marketplace_ImportEx232bbcddcf49V4_Source_ImportExportModels_Public_ImportExportModelsBPLibrary_h_146_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMeshMaterialData_Statics; \
	IMPORTEXPORTMODELS_API static class UScriptStruct* StaticStruct();


template<> IMPORTEXPORTMODELS_API UScriptStruct* StaticStruct<struct FMeshMaterialData>();

#define FID_TestProject_Plugins_Marketplace_ImportEx232bbcddcf49V4_Source_ImportExportModels_Public_ImportExportModelsBPLibrary_h_179_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FModeldMaterialData_Statics; \
	IMPORTEXPORTMODELS_API static class UScriptStruct* StaticStruct();


template<> IMPORTEXPORTMODELS_API UScriptStruct* StaticStruct<struct FModeldMaterialData>();

#define FID_TestProject_Plugins_Marketplace_ImportEx232bbcddcf49V4_Source_ImportExportModels_Public_ImportExportModelsBPLibrary_h_198_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execReadImgToTexture); \
	DECLARE_FUNCTION(execBPExportFBXModel); \
	DECLARE_FUNCTION(execBPImportModelNormal); \
	DECLARE_FUNCTION(execBPImportModel); \
	DECLARE_FUNCTION(execMSaveFileDialog); \
	DECLARE_FUNCTION(execMOpenFileDialog);


#define FID_TestProject_Plugins_Marketplace_ImportEx232bbcddcf49V4_Source_ImportExportModels_Public_ImportExportModelsBPLibrary_h_198_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUImportExportModelsBPLibrary(); \
	friend struct Z_Construct_UClass_UImportExportModelsBPLibrary_Statics; \
public: \
	DECLARE_CLASS(UImportExportModelsBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ImportExportModels"), NO_API) \
	DECLARE_SERIALIZER(UImportExportModelsBPLibrary)


#define FID_TestProject_Plugins_Marketplace_ImportEx232bbcddcf49V4_Source_ImportExportModels_Public_ImportExportModelsBPLibrary_h_198_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UImportExportModelsBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UImportExportModelsBPLibrary(UImportExportModelsBPLibrary&&); \
	UImportExportModelsBPLibrary(const UImportExportModelsBPLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UImportExportModelsBPLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UImportExportModelsBPLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UImportExportModelsBPLibrary) \
	NO_API virtual ~UImportExportModelsBPLibrary();


#define FID_TestProject_Plugins_Marketplace_ImportEx232bbcddcf49V4_Source_ImportExportModels_Public_ImportExportModelsBPLibrary_h_194_PROLOG
#define FID_TestProject_Plugins_Marketplace_ImportEx232bbcddcf49V4_Source_ImportExportModels_Public_ImportExportModelsBPLibrary_h_198_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_TestProject_Plugins_Marketplace_ImportEx232bbcddcf49V4_Source_ImportExportModels_Public_ImportExportModelsBPLibrary_h_198_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_TestProject_Plugins_Marketplace_ImportEx232bbcddcf49V4_Source_ImportExportModels_Public_ImportExportModelsBPLibrary_h_198_INCLASS_NO_PURE_DECLS \
	FID_TestProject_Plugins_Marketplace_ImportEx232bbcddcf49V4_Source_ImportExportModels_Public_ImportExportModelsBPLibrary_h_198_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> IMPORTEXPORTMODELS_API UClass* StaticClass<class UImportExportModelsBPLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_TestProject_Plugins_Marketplace_ImportEx232bbcddcf49V4_Source_ImportExportModels_Public_ImportExportModelsBPLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
