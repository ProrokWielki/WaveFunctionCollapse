#pragma once

#include "chunk.hpp"

enum class ChunkType {
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
};

class ChunkFactory {
public:
  static std::shared_ptr<Chunk> create(ChunkType tile);

private:
  ChunkFactory() = default;
};
