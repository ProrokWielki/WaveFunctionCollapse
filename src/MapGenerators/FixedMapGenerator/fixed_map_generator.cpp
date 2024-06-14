#include "fixed_map_generator.hpp"
#include "MapGenerator/map_generator.hpp"

FixedMapGenerator::FixedMapGenerator(unsigned int width, unsigned int height)
    : MapGenerator(width, height) {}

std::vector<TileType> FixedMapGenerator::generate() {
  std::vector<TileType> output{};

  for (auto y = 0; y < height_; ++y) {
    for (auto x = 0; x < width_; ++x) {
      if (x == 0 and y == 0) {
        output.push_back(TileType::TopLeftWall);
      } else if (y == 0 and x == width_ - 1) {
        output.push_back(TileType::TopRightWall);
      } else if (y == height_ - 1 and x == 0) {
        output.push_back(TileType::BottomLeftWall);
      } else if (y == height_ - 1 and x == width_ - 1) {
        output.push_back(TileType::BottomRightWall);
      } else if (x == 0) {
        output.push_back(TileType::LeftWall);
      } else if (x == width_ - 1) {
        output.push_back(TileType::RightWall);
      } else if (y == 0) {
        output.push_back(TileType::TopWall);
      } else if (y == height_ - 1) {
        output.push_back(TileType::BottomWall);
      } else {
        output.push_back(TileType::Grass);
      }
    }
  }
  return output;
}