#pragma once

#include "Cesium3DTilesSelection/BoundingVolume.h"
#include "Cesium3DTilesSelection/Library.h"
#include "Cesium3DTilesSelection/TileContentLoadResult.h"
#include "Cesium3DTilesSelection/TileContentLoader.h"

#include <rapidjson/document.h>

#include <cstddef>

namespace Cesium3DTilesSelection {

/**
 * @brief Creates a {@link TileContentLoadResult} from `quantized-mesh-1.0`
 * data.
 */
class CESIUM3DTILESSELECTION_API QuantizedMeshContent final
    : public TileContentLoader {
public:
  static std::string CONTENT_TYPE;

  /**
   * @copydoc TileContentLoader::load
   *
   * The result will only contain the `model`, `availableTileRectangles`
   * and `updatedBoundingVolume`. Other fields will be empty or have
   * default values.
   */
  CesiumAsync::Future<std::unique_ptr<TileContentLoadResult>>
  load(const TileContentLoadInput& input) override;

  /**
   * @brief Create a {@link TileContentLoadResult} from the given data.
   *
   * (Only public for tests)
   *
   * @param pLogger Only used for logging
   * @param tileID The tile ID
   * @param tileBoundingVoume The tile bounding volume
   * @param url The URL
   * @param data The actual input data
   * @return The {@link TileContentLoadResult}
   */
  static std::unique_ptr<TileContentLoadResult> load(
      const std::shared_ptr<spdlog::logger>& pLogger,
      const TileID& tileID,
      const BoundingVolume& tileBoundingVolume,
      const std::string& url,
      const gsl::span<const std::byte>& data,
      bool enableWaterMask);

  static std::optional<gsl::span<const char>>
  loadMetadata(const gsl::span<const std::byte>& data);

  static void processAvailability(
      const rapidjson::Document& metadata,
      uint32_t startingLevel,
      std::vector<CesiumGeometry::QuadtreeTileRectangularRange>&
          availableTileRectangles);
};

} // namespace Cesium3DTilesSelection
