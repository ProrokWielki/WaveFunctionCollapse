#pragma once

#include <vector>

enum class TileType {
  TopLeftWall,
  TopWall,
  TopRightWall,
  LeftWall,
  TopLeftRoad,
  TDown,
  TopRightRoad,
  TRight,
  CrossRoads,
  TLeft,
  BottomLeftRoad,
  TUp,
  RightWall,
  BottomRightRoad,
  BottomLeftWall,
  BottomWall,
  BottomRightWall,
  HorizontalRoad,
  VerticalRoad,
  Grass,
  Invalid,
};

class MapGenerator {
public:
  MapGenerator(unsigned int width, unsigned int height)
      : width_{width}, height_{height} {};
  virtual std::vector<TileType> generate() = 0;

protected:
  unsigned int width_{};
  unsigned int height_{};
};