#include "Cesium3DTilesSelection/TileContentLoadInput.h"

#include "Cesium3DTilesSelection/Tileset.h"

#include <CesiumAsync/IAssetResponse.h>

using namespace Cesium3DTilesSelection;
using namespace CesiumAsync;

TileContentLoadInput::TileContentLoadInput()
    : asyncSystem(nullptr),
      pLogger(nullptr),
      pAssetAccessor(nullptr),
      pRequest(nullptr),
      tileID(""),
      tileBoundingVolume(CesiumGeospatial::BoundingRegion(
          CesiumGeospatial::GlobeRectangle(0.0, 0.0, 0.0, 0.0),
          0.0,
          0.0)),
      tileContentBoundingVolume(CesiumGeospatial::BoundingRegion(
          CesiumGeospatial::GlobeRectangle(0.0, 0.0, 0.0, 0.0),
          0.0,
          0.0)),
      tileRefine(TileRefine::Replace),
      tileGeometricError(0.0),
      tileTransform(glm::dmat4(1.0)),
      contentOptions() {}

TileContentLoadInput::TileContentLoadInput(const Tile& tile)
    : asyncSystem(nullptr),
      pLogger(nullptr),
      pAssetAccessor(nullptr),
      pRequest(nullptr),
      tileID(tile.getTileID()),
      tileBoundingVolume(tile.getBoundingVolume()),
      tileContentBoundingVolume(tile.getContentBoundingVolume()),
      tileRefine(tile.getRefine()),
      tileGeometricError(tile.getGeometricError()),
      tileTransform(tile.getTransform()),
      contentOptions() {}

TileContentLoadInput::TileContentLoadInput(
    const AsyncSystem& asyncSystem_,
    const std::shared_ptr<spdlog::logger>& pLogger_,
    const std::shared_ptr<IAssetAccessor>& pAssetAccessor_,
    const std::shared_ptr<IAssetRequest>& pRequest_,
    const Tile& tile)
    : asyncSystem(asyncSystem_),
      pLogger(pLogger_),
      pAssetAccessor(pAssetAccessor_),
      pRequest(pRequest_),
      tileID(tile.getTileID()),
      tileBoundingVolume(tile.getBoundingVolume()),
      tileContentBoundingVolume(tile.getContentBoundingVolume()),
      tileRefine(tile.getRefine()),
      tileGeometricError(tile.getGeometricError()),
      tileTransform(tile.getTransform()),
      contentOptions() {}

TileContentLoadInput::TileContentLoadInput(
    const AsyncSystem& asyncSystem_,
    const std::shared_ptr<spdlog::logger>& pLogger_,
    const std::shared_ptr<IAssetAccessor>& pAssetAccessor_,
    const std::shared_ptr<IAssetRequest>& pRequest_,
    const TileID& tileID_,
    const BoundingVolume& tileBoundingVolume_,
    const std::optional<BoundingVolume>& tileContentBoundingVolume_,
    TileRefine tileRefine_,
    double tileGeometricError_,
    const glm::dmat4& tileTransform_,
    const TilesetContentOptions& contentOptions_)
    : asyncSystem(asyncSystem_),
      pLogger(pLogger_),
      pAssetAccessor(pAssetAccessor_),
      pRequest(pRequest_),
      tileID(tileID_),
      tileBoundingVolume(tileBoundingVolume_),
      tileContentBoundingVolume(tileContentBoundingVolume_),
      tileRefine(tileRefine_),
      tileGeometricError(tileGeometricError_),
      tileTransform(tileTransform_),
      contentOptions(contentOptions_) {}
