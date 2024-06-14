#include <memory>
#include <vector>

#include "MapGenerator/map_generator.hpp"
#include <GUI/grid.hpp>

#include "Chunks/chunk_factory.hpp"

ChunkType to_chunk_type(TileType type) {
  switch (type) {
  case TileType::TopLeftWall:
    return ChunkType::TopLeftWall;
  case TileType::TopWall:
    return ChunkType::TopWall;
  case TileType::TopRightWall:
    return ChunkType::TopRightWall;
  case TileType::LeftWall:
    return ChunkType::LeftWall;
  case TileType::TopLeftRoad:
    return ChunkType::TopLeftRoad;
  case TileType::TDown:
    return ChunkType::TDown;
  case TileType::TopRightRoad:
    return ChunkType::TopRightRoad;
  case TileType::TRight:
    return ChunkType::TRight;
  case TileType::CrossRoads:
    return ChunkType::CrossRoads;
  case TileType::TLeft:
    return ChunkType::TLeft;
  case TileType::BottomLeftRoad:
    return ChunkType::BottomLeftRoad;
  case TileType::TUp:
    return ChunkType::TUp;
  case TileType::RightWall:
    return ChunkType::RightWall;
  case TileType::BottomRightRoad:
    return ChunkType::BottomRightRoad;
  case TileType::BottomLeftWall:
    return ChunkType::BottomLeftWall;
  case TileType::BottomWall:
    return ChunkType::BottomWall;
  case TileType::BottomRightWall:
    return ChunkType::BottomRightWall;
  case TileType::HorizontalRoad:
    return ChunkType::HorizontalRoad;
  case TileType::VerticalRoad:
    return ChunkType::VerticalRoad;
  case TileType::Grass:
    return ChunkType::Grass;
  };
  return ChunkType::Grass;
}

class Map : public Grid<Chunk> {
public:
  Map(unsigned int width, unsigned int height)
      : width_(width), height_(height) {}

  void generate(const std::vector<TileType> &tiles) {
    for (auto y = 0; y < height_; ++y) {
      for (auto x = 0; x < width_; ++x) {
        if (tiles[x + y * width_] != TileType::Invalid) {
          add_element({x, y}, ChunkFactory::create(
                                  to_chunk_type(tiles[x + y * width_])));
        }
      }
    }
  }

private:
  unsigned int width_{};
  unsigned int height_{};
};