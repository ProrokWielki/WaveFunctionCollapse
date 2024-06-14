#include <algorithm>
#include <ctime>
#include <set>

#include "possibility_matrix.hpp"
#include "wave_function_colapse_generator.hpp"

WaveFunctionCollapseMapGenerator::WaveFunctionCollapseMapGenerator(
    unsigned int width, unsigned int height)
    : MapGenerator(width, height) {
  for (auto i = 0; i < width_ * height_; ++i) {
    tiles_.push_back(Tile());
  }
}

bool WaveFunctionCollapseMapGenerator::collapse_most_probable() {
  std::vector<Tile *> tile_copy;

  for (auto &tile : tiles_) {
    if (tile.collapsed) {
      continue;
    }
    tile_copy.push_back(&tile);
  }
  if (tile_copy.size() == 0) {
    return false;
  }

  std::sort(tile_copy.begin(), tile_copy.end(), [](Tile *a, Tile *b) {
    return a->possible_tiles.size() < b->possible_tiles.size();
  });

  int lowest_probability = tile_copy[0]->possible_tiles.size();

  auto last_lowest_iter = std::find_if(
      tile_copy.begin(), tile_copy.end(), [lowest_probability](Tile *a) {
        return a->possible_tiles.size() > lowest_probability;
      });

  tile_copy.erase(last_lowest_iter, tile_copy.end());

  std::srand(std::time(0));
  int random_tile = std::rand() % tile_copy.size();
  if (tile_copy[random_tile]->possible_tiles.size() == 0) {
    tile_copy[random_tile]->collapsed = true;
    return true;
  }
  int random_type = std::rand() % tile_copy[random_tile]->possible_tiles.size();

  tile_copy[random_tile]->possible_tiles = {
      tile_copy[random_tile]->possible_tiles[random_type]};
  tile_copy[random_tile]->collapsed = true;

  return true;
}

void WaveFunctionCollapseMapGenerator::update_tiles() {
  for (auto y = 0; y < height_; ++y) {
    for (auto x = 0; x < width_; ++x) {

      if (tiles_[y * width_ + x].collapsed) {
        continue;
      }

      if (x - 1 >= 0) {
        update_intersection(x, y, Direction::Left);
      }

      if (x + 1 < width_) {
        update_intersection(x, y, Direction::Right);
      }

      if (y - 1 >= 0) {
        update_intersection(x, y, Direction::Up);
      }

      if (y + 1 < height_) {
        update_intersection(x, y, Direction::Down);
      }
    }
  }
}

void WaveFunctionCollapseMapGenerator::update_intersection(int x, int y,
                                                           Direction dir) {
  auto index_offset = 0;
  switch (dir) {
  case Direction::Down:
    index_offset = width_;
    dir = Direction::Up;
    break;
  case Direction::Up:
    index_offset = -width_;
    dir = Direction::Down;
    break;
  case Direction::Left:
    index_offset = -1;
    dir = Direction::Right;
    break;
  case Direction::Right:
    index_offset = 1;
    dir = Direction::Left;
    break;
  }

  if (tiles_[y * width_ + x + index_offset].collapsed) {

    std::vector<TileType> intersection{};

    auto this_tile_possibilities = tiles_[y * width_ + x].possible_tiles;

    for (auto i = this_tile_possibilities.begin();
         i != this_tile_possibilities.end(); ++i) {

      auto possible_tiles =
          possibility_matrix[tiles_[y * width_ + x + index_offset]
                                 .possible_tiles[0]][dir];
      if (std::find(possible_tiles.begin(), possible_tiles.end(), *i) !=
          possible_tiles.end()) {
        intersection.push_back(*i);
      }
      std::set<TileType> s(intersection.begin(), intersection.end());
      intersection.assign(s.begin(), s.end());
      tiles_[y * width_ + x].possible_tiles = intersection;
    }
  }
}

std::vector<TileType> WaveFunctionCollapseMapGenerator::generate() {
  bool something_to_colapse = true;
  while (something_to_colapse) {
    update_tiles();
    something_to_colapse = collapse_most_probable();
  }

  return get_result_vector();
}

std::vector<TileType> WaveFunctionCollapseMapGenerator::get_result_vector() {
  std::vector<TileType> output{};
  for (auto tile : tiles_) {
    output.push_back(tile.possible_tiles.size() != 1 ? TileType::Invalid
                                                     : tile.possible_tiles[0]);
  }
  return output;
}