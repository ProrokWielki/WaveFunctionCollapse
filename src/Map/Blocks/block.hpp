#pragma once

#include "GUI/grid.hpp"
#include <GUI/drawable.hpp>

class Block : public Grid<Drawable> {
public:
  static const int Size{2};
  constexpr static bool HAS_SUB_GRID{false};

  virtual unsigned int get_width() const { return 2; }
  virtual unsigned int get_height() const { return 2; }
};