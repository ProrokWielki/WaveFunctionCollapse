#pragma once

#include "block.hpp"

class Grass : public Block {
public:
  Grass() : Block() {
    pixels_ = {
        {{0, 0}, {24, 219, 122}},
        {{0, 1}, {24, 219, 122}},
        {{1, 0}, {24, 219, 122}},
        {{1, 1}, {24, 219, 122}},
    };
  }
  ~Grass() override = default;
};