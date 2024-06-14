#pragma once

#include "block.hpp"
#include <GUI/grid.hpp>
#include <GUI/pixel.hpp>

class Wall : public Block {
public:
  Wall() : Block() {
    pixels_ = {
        {{0, 0}, {104, 116, 117}},
        {{0, 1}, {104, 116, 117}},
        {{1, 0}, {104, 116, 117}},
        {{1, 1}, {104, 116, 117}},
    };
  }
  ~Wall() override = default;
};