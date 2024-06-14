#pragma once

#include "MapGenerator/map_generator.hpp"

class FixedMapGenerator : public MapGenerator {
public:
  FixedMapGenerator(unsigned int width, unsigned int height);

  std::vector<TileType> generate() override;
};