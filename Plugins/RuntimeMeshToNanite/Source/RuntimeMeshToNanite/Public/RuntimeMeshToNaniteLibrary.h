// Copyright (c) Adrián Guerra 2025. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ImportExportModelsBPLibrary.h" // Para las estructuras del plugin
#include "Engine/StaticMesh.h"
#include "Materials/MaterialInterface.h"
#include "NaniteDefinitions.h"
#include "RuntimeMeshToNaniteLibrary.generated.h"

class UStaticMesh;
class UMaterialInterface;

UCLASS()
class RUNTIMEMESHTONANITE_API URuntimeMeshToNaniteLibrary : public UBlueprintFunctionLibrary
{
  GENERATED_BODY()

public:
  /**
   * Convierte un modelo importado en tiempo de ejecución a Static Mesh con Nanite
   */
  UFUNCTION(BlueprintCallable, Category = "RuntimeMeshToNanite", meta = (DisplayName = "Convert Runtime Mesh to Nanite"))
  static UStaticMesh* ConvertRuntimeMeshToNanite(
    const FModeldMaterialData& ModelData,
    const FString& MeshName,
    bool bEnableNanite = true,
    const FMeshNaniteSettings& NaniteSettings = FMeshNaniteSettings()
  );

  /**
   * Crea un material dinámico basado en los datos del modelo
   */
  UFUNCTION(BlueprintCallable, Category = "RuntimeMeshToNanite", meta = (DisplayName = "Create Material From Model Data"))
  static UMaterialInterface* CreateMaterialFromModelData(const FMaterialData& MaterialData);

private:
  // Función auxiliar para crear secciones de malla
  static void CreateMeshSection(
    UStaticMesh* StaticMesh,
    const FMeshMaterialData& MeshData,
    int32 LODIndex,
    UMaterialInterface* Material,
    FMeshDescription& MeshDescription);
};
