#pragma once

#include <memory>

#include "map_generator.hpp"

enum class MapGenerators { WaveFunctionCollapse, Fixed };

class MapGeneratorFactory {
public:
  static std::shared_ptr<MapGenerator>
  create(MapGenerators generator, unsigned int width, unsigned int height);

private:
  MapGeneratorFactory() = default;
};