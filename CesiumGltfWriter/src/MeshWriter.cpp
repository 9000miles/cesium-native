#include "MeshWriter.h"

#include "ExtensionWriter.h"

#include <CesiumGltf/Mesh.h>
#include <CesiumGltf/MeshPrimitive.h>
#include <CesiumJsonWriter/JsonObjectWriter.h>
#include <CesiumJsonWriter/JsonWriter.h>

#include <vector>

void writePrimitive(
    const CesiumGltf::MeshPrimitive& primitive,
    CesiumJsonWriter::JsonWriter& jsonWriter) {
  auto& j = jsonWriter;
  j.StartObject();

  j.Key("attributes");
  assert(!primitive.attributes.empty());
  j.StartObject();
  for (const auto& [key, index] : primitive.attributes) {
    j.KeyPrimitive(key, index);
  }
  j.EndObject();

  if (primitive.indices >= 0) {
    j.Key("indices");
    j.Int(primitive.indices);
  }

  if (primitive.material >= 0) {
    j.Key("material");
    j.Int(primitive.material);
  }

  if (primitive.mode != CesiumGltf::MeshPrimitive::Mode::TRIANGLES) {
    j.Key("mode");
    j.Int(primitive.mode);
  }

  if (!primitive.targets.empty()) {
    j.Key("targets");
    j.StartArray();
    for (const auto& target : primitive.targets) {
      j.StartObject();
      for (const auto& [name, index] : target) {
        j.Key(name.c_str());
        j.Int(index);
      }
      j.EndObject();
    }
    j.EndArray();
  }

  if (!primitive.extensions.empty()) {
    j.Key("extensions");
    CesiumGltfWriter::writeExtensions(primitive.extensions, j);
  }

  if (!primitive.extras.empty()) {
    j.Key("extras");
    CesiumJsonWriter::writeJsonValue(primitive.extras, j);
  }
  j.EndObject();
}

void CesiumGltfWriter::writeMesh(
    const std::vector<CesiumGltf::Mesh>& meshes,
    CesiumJsonWriter::JsonWriter& jsonWriter) {

  if (meshes.empty()) {
    return;
  }

  auto& j = jsonWriter;
  j.Key("meshes");
  j.StartArray();
  for (const auto& mesh : meshes) {
    j.StartObject();

    assert(!mesh.primitives.empty());
    j.Key("primitives");
    j.StartArray();
    for (const auto& primitive : mesh.primitives) {
      writePrimitive(primitive, j);
    }
    j.EndArray();

    if (!mesh.weights.empty()) {
      j.Key("weights");
      j.StartArray();
      for (const auto& weight : mesh.weights) {
        j.Double(weight);
      }
      j.EndArray();
    }

    if (!mesh.name.empty()) {
      j.Key("name");
      j.String(mesh.name.c_str());
    }

    if (!mesh.extensions.empty()) {
      CesiumGltfWriter::writeExtensions(mesh.extensions, j);
    }

    if (!mesh.extras.empty()) {
      j.Key("extras");
      writeJsonValue(mesh.extras, j);
    }

    j.EndObject();
  }

  j.EndArray();
}
