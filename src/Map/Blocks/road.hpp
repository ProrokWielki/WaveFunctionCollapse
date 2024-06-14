#pragma once

#include "block.hpp"

class Road : public Block {
public:
  Road() : Block() {
    pixels_ = {
        {{0, 0}, {255, 255, 255}},
        {{0, 1}, {255, 255, 255}},
        {{1, 0}, {255, 255, 255}},
        {{1, 1}, {255, 255, 255}},
    };
  }
  ~Road() override = default;
};