#pragma once

#include "../chunk.hpp"

#include "../../Blocks/grass.hpp"
#include "../../Blocks/road.hpp"

class HorizontalRoad : public Chunk {
public:
  HorizontalRoad() {

    add_element({0, 0}, std::make_shared<Grass>());
    add_element({1, 0}, std::make_shared<Grass>());
    add_element({2, 0}, std::make_shared<Grass>());

    add_element({0, 1}, std::make_shared<Road>());
    add_element({1, 1}, std::make_shared<Road>());
    add_element({2, 1}, std::make_shared<Road>());

    add_element({0, 2}, std::make_shared<Grass>());
    add_element({1, 2}, std::make_shared<Grass>());
    add_element({2, 2}, std::make_shared<Grass>());
  }
};