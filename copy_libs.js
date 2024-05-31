"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var fs = require("fs");
var process = require("process");
var path = require("path");
var libs = [
    "Build/Cesium3DTiles/libCesium3DTiles.a",
    "Build/Cesium3DTilesReader/libCesium3DTilesReader.a",
    "Build/Cesium3DTilesSelection/libCesium3DTilesSelection.a",
    "Build/Cesium3DTilesWriter/libCesium3DTilesWriter.a",
    "Build/CesiumAsync/libCesiumAsync.a",
    "Build/CesiumGeometry/libCesiumGeometry.a",
    "Build/CesiumGeospatial/libCesiumGeospatial.a",
    "Build/CesiumGltf/libCesiumGltf.a",
    "Build/CesiumGltfReader/libCesiumGltfReader.a",
    "Build/CesiumGltfWriter/libCesiumGltfWriter.a",
    "Build/CesiumIonClient/libCesiumIonClient.a",
    "Build/CesiumJsonReader/libCesiumJsonReader.a",
    "Build/CesiumJsonWriter/libCesiumJsonWriter.a",
    "Build/CesiumUtility/libCesiumUtility.a",
    "Build/extern/asyncplusplus/libasync++.a",
    "Build/extern/libcsprng.a",
    "Build/extern/draco/libdraco.a",
    "Build/extern/KTX-Software/libktx_read.a",
    "extern/mikktspace/build/libMikkTSpace.a",
    "Build/extern/modp_b64/libmodp_b64.a",
    "Build/extern/libs2geometry.a",
    "Build/extern/spdlog/libspdlog.a",
    "Build/extern/sqlite3/libsqlite3.a",
    "extern/tidy/tidy-html5-5.9.14-next/build/libtidy.a",
    "Build/extern/libtinyxml2.a",
    "Build/extern/libjpeg-turbo/libturbojpeg.a",
    "Build/extern/uriparser/liburiparser.a",
    "Build/extern/libwebp/libwebpdecoder.a",
];
// libs = [
//   "aaf.a",
//   "agrr.a",
// ]
var script = process.argv[1];
var destDir = "E:\\UE\\4.27\\Html5Project_New\\Plugins\\CesiumForUnreal\\Source\\ThirdParty\\lib\\HTML5";
var dir = path.dirname(script);
for (var _i = 0, libs_1 = libs; _i < libs_1.length; _i++) {
    var lib = libs_1[_i];
    var src = path.join(dir, lib);
    if (!fs.existsSync(src)) {
        console.error("".concat(src, " is not exists"));
        continue;
    }
    var dest = path.join(destDir, path.basename(lib));
    console.log(src, " >>  ", dest);
    fs.copyFileSync(src, dest);
}
