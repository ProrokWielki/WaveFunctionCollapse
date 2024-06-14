
#include <memory>

#include "map_generator_factory.hpp"

#include "FixedMapGenerator/fixed_map_generator.hpp"
#include "WaveFunctionColapseMapGenerator/wave_function_colapse_generator.hpp"

std::shared_ptr<MapGenerator>
MapGeneratorFactory::create(MapGenerators generator, unsigned int width,
                            unsigned int height) {
  switch (generator) {
  case MapGenerators::Fixed:
    return std::make_shared<FixedMapGenerator>(width, height);
  case MapGenerators::WaveFunctionCollapse:
    return std::make_shared<WaveFunctionCollapseMapGenerator>(width, height);
  };
  return nullptr;
}
