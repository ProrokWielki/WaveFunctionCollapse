#pragma once

#include "../Blocks/block.hpp"
#include "GUI/grid.hpp"

class Chunk : public Grid<Block> {
public:
  constexpr static bool HAS_SUB_GRID{true};
  static constexpr int Size{3};

  virtual unsigned int get_width() const { return 3; }
  virtual unsigned int get_height() const { return 3; }
};