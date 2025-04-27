// Copyright (c) Adrián Guerra 2025. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ImportExportModelsBPLibrary.h" // Para las estructuras del plugin
#include "Engine/StaticMesh.h"
#include "Materials/MaterialInterface.h"
#include "Materials/MaterialInstance.h"
#include "Materials/MaterialInstanceConstant.h"
#include "NaniteDefinitions.h"
#include "RuntimeMeshToNaniteLibrary.generated.h"

class UStaticMesh;
class UMaterialInterface;
class UTexture2D;

/**
 * Biblioteca de funciones para convertir Procedural Meshes importadas en tiempo de ejecución a Static Meshes compatibles con Nanite.
 * Soporta tanto la conversión automática de materiales como la recuperación de estos para su modificación manual.
 */
UCLASS()
class RUNTIMEMESHTONANITE_API URuntimeMeshToNaniteLibrary : public UBlueprintFunctionLibrary
{
  GENERATED_BODY()

public:

  /**
   * Convierte un modelo completo (FModeldMaterialData) en un único StaticMesh usando Nanite.
   * @param ModelData - Datos del modelo a convertir
   * @param MeshName - Nombre para el StaticMesh resultante
   * @param bEnableNanite - Si se habilita el soporte Nanite
   * @param NaniteSettings - Configuración específica para Nanite
   * @return StaticMesh creado, o nullptr si falla
   */
  UFUNCTION(BlueprintCallable, Category = "RuntimeMeshToNanite", meta = (DisplayName = "Convert Runtime Mesh to Single Nanite StaticMesh"))
  static UStaticMesh* ConvertRuntimeMeshToNanite(
    const FModeldMaterialData& ModelData,
    const FString& MeshName,
    bool bEnableNanite = true,
    const FMeshNaniteSettings& NaniteSettings = FMeshNaniteSettings()
  );

  /**
   * Convierte cada submesh de un modelo (FModeldMaterialData) en StaticMeshes separados usando Nanite.
   * @param ModelData - Datos del modelo a convertir
   * @param BaseMeshName - Nombre base para los StaticMeshes resultantes (se añade "_Section_N")
   * @param bEnableNanite - Si se habilita el soporte Nanite
   * @param NaniteSettings - Configuración específica para Nanite
   * @param OutMaterials - Array de salida con los materiales creados para cada sección
   * @return Array de StaticMeshes creados
   */
   // Versión principal sin parámetro de salida (para cuando no necesitas los materiales)
  UFUNCTION(BlueprintCallable, Category = "RuntimeMeshToNanite",
    meta = (DisplayName = "Convert Runtime Mesh Sections to Separate Nanite StaticMeshes"))
  static TArray<UStaticMesh*> ConvertRuntimeMeshSectionsToNanite(
    const FModeldMaterialData& ModelData,
    const FString& BaseMeshName,
    bool bEnableNanite = true,
    const FMeshNaniteSettings& NaniteSettings = FMeshNaniteSettings()
  );

  /**
   * Convierte un modelo en múltiples StaticMeshes y devuelve los materiales creados
   * @param OutMaterials - (Salida) Array que se llenará con los materiales creados
   * @see ConvertRuntimeMeshSectionsToNanite() para los demás parámetros
   */
  // Versión con parámetro de salida para materiales
  UFUNCTION(BlueprintCallable, Category = "RuntimeMeshToNanite",
    meta = (DisplayName = "Convert Runtime Mesh Sections to Separate Nanite StaticMeshes (With Materials)"))
  static TArray<UStaticMesh*> ConvertRuntimeMeshSectionsToNaniteWithMaterials(
    const FModeldMaterialData& ModelData,
    const FString& BaseMeshName,
    TArray<UMaterialInterface*>& OutMaterials,
    bool bEnableNanite = true,
    const FMeshNaniteSettings& NaniteSettings = FMeshNaniteSettings()
  );

  /**
   * Crea un material basado en los datos del modelo.
   * @param MaterialData - Datos del material a crear
   * @param bCreateDynamicInstance - Si se crea una instancia dinámica (modificable en runtime)
   * @return Material creado, o nullptr si falla
   */
  UFUNCTION(BlueprintCallable, Category = "RuntimeMeshToNanite",
    meta = (DisplayName = "Create Material From Model Data"))
  static UMaterialInterface* CreateMaterialFromModelData(
    const FMaterialData& MaterialData,
    bool bCreateDynamicInstance = true
  );

private:

  /**
   * Crea una sección de malla en el StaticMesh utilizando un FMeshMaterialData.
   * @param StaticMesh - Mesh destino
   * @param MeshData - Datos de la malla a añadir
   * @param LODIndex - Nivel de detalle
   * @param Material - Material a aplicar
   * @param MeshDescription - Descripción de malla a modificar
   */
  static void CreateMeshSection(
    UStaticMesh* StaticMesh,
    const FMeshMaterialData& MeshData,
    int32 LODIndex,
    UMaterialInterface* Material,
    FMeshDescription& MeshDescription
  );

  /**
   * Establece un parámetro de textura en un material, soportando tanto instancias dinámicas como constantes.
   * @param Material - Material a modificar
   * @param ParameterName - Nombre del parámetro
   * @param Texture - Textura a asignar
   */
  static void SetMaterialTextureParameter(
    UMaterialInterface* Material,
    const FName& ParameterName,
    UTexture2D* Texture
  );

  /**
   * Calcula el número total de triángulos en un modelo.
   * @param ModelData - Datos del modelo
   * @return Número total de triángulos
   */
  static int32 GetTriangleCount(const FModeldMaterialData& ModelData);
};
