#pragma once

#include "../chunk.hpp"

class WallOnTheTopRight : public Chunk {
public:
  WallOnTheTopRight() {

    add_element({0, 0}, std::make_shared<Wall>());
    add_element({1, 0}, std::make_shared<Wall>());
    add_element({2, 0}, std::make_shared<Wall>());

    add_element({0, 1}, std::make_shared<Grass>());
    add_element({1, 1}, std::make_shared<Grass>());
    add_element({2, 1}, std::make_shared<Wall>());

    add_element({0, 2}, std::make_shared<Grass>());
    add_element({1, 2}, std::make_shared<Grass>());
    add_element({2, 2}, std::make_shared<Wall>());
  }
};