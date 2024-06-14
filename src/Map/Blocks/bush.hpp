#pragma once

#include "block.hpp"

class Bush : public Block {
public:
  Bush() : Block() {
    pixels_ = {
        {{0, 0}, {15, 111, 34}},
        {{0, 1}, {15, 111, 34}},
        {{1, 0}, {15, 111, 34}},
        {{1, 1}, {15, 111, 34}},
    };
  }
  ~Bush() override = default;
};