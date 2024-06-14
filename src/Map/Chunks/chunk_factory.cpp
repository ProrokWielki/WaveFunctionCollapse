#include "chunk_factory.hpp"

#include "impl/bottom_left_road.hpp"
#include "impl/bottom_right_road.hpp"
#include "impl/cross_roads.hpp"
#include "impl/grass_chunk.hpp"
#include "impl/horizontal_road.hpp"
#include "impl/t_down.hpp"
#include "impl/t_left.hpp"
#include "impl/t_right.hpp"
#include "impl/t_up.hpp"
#include "impl/top_left_road.hpp"
#include "impl/top_right_road.hpp"
#include "impl/vertical_road.hpp"
#include "impl/wall_on_the_bottom.hpp"
#include "impl/wall_on_the_bottom_left.hpp"
#include "impl/wall_on_the_bottom_right.hpp"
#include "impl/wall_on_the_left.hpp"
#include "impl/wall_on_the_right.hpp"
#include "impl/wall_on_the_top.hpp"
#include "impl/wall_on_the_top_left.hpp"
#include "impl/wall_on_the_top_right.hpp"

std::shared_ptr<Chunk> ChunkFactory::create(ChunkType tile) {
  switch (tile) {
  case ChunkType::TopLeftWall:
    return std::make_shared<WallOnTheTopLeft>();
    break;
  case ChunkType::TopWall:
    return std::make_shared<WallOnTheTop>();
    break;
  case ChunkType::TopRightWall:
    return std::make_shared<WallOnTheTopRight>();
    break;
  case ChunkType::LeftWall:
    return std::make_shared<WallOnTheLeft>();
    break;
  case ChunkType::TopLeftRoad:
    return std::make_shared<TopLeftRoad>();
    break;
  case ChunkType::TDown:
    return std::make_shared<TDown>();
    break;
  case ChunkType::TopRightRoad:
    return std::make_shared<TopRightRoad>();
    break;
  case ChunkType::TRight:
    return std::make_shared<TRight>();
    break;
  case ChunkType::CrossRoads:
    return std::make_shared<CrossRoads>();
    break;
  case ChunkType::TLeft:
    return std::make_shared<TLeft>();
    break;
  case ChunkType::BottomLeftRoad:
    return std::make_shared<BottomLeftRoad>();
    break;
  case ChunkType::TUp:
    return std::make_shared<TUp>();
    break;
  case ChunkType::RightWall:
    return std::make_shared<WallOnTheRight>();
    break;
  case ChunkType::BottomRightRoad:
    return std::make_shared<BottomRightRoad>();
    break;
  case ChunkType::BottomLeftWall:
    return std::make_shared<WallOnTheBottomLeft>();
    break;
  case ChunkType::BottomWall:
    return std::make_shared<WallOnTheBottom>();
    break;
  case ChunkType::BottomRightWall:
    return std::make_shared<WallOnTheBottomRight>();
    break;
  case ChunkType::Grass:
    return std::make_shared<GrassChunk>();
    break;
  case ChunkType::HorizontalRoad:
    return std::make_shared<HorizontalRoad>();
    break;
  case ChunkType::VerticalRoad:
    return std::make_shared<VerticalRoad>();
    break;
  };
  return std::make_shared<GrassChunk>();
}
