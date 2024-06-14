#pragma once

#include <vector>

#include "MapGenerator/map_generator.hpp"

struct Tile {
  bool collapsed{false};
  std::vector<TileType> possible_tiles{
      TileType::TopLeftWall,     TileType::TopWall,
      TileType::TopRightWall,    TileType::LeftWall,
      TileType::TopLeftRoad,     TileType::TDown,
      TileType::TopRightRoad,    TileType::TRight,
      TileType::CrossRoads,      TileType::TLeft,
      TileType::BottomLeftRoad,  TileType::TUp,
      TileType::RightWall,       TileType::BottomRightRoad,
      TileType::BottomLeftWall,  TileType::BottomWall,
      TileType::BottomRightWall, TileType::Grass,
      TileType::HorizontalRoad,  TileType::VerticalRoad,
  };
};

enum class Direction { Up, Down, Left, Right };

class WaveFunctionCollapseMapGenerator : public MapGenerator {

public:
  WaveFunctionCollapseMapGenerator(unsigned int width, unsigned int height);

  std::vector<TileType> generate() override;

private:
  void update_intersection(int x, int y, Direction dir);
  void update_tiles();
  bool collapse_most_probable();
  std::vector<TileType> get_result_vector();

  std::vector<Tile> tiles_{};
};