#include "GUI/position.hpp"
#include <GUI/drawable.hpp>
#include <memory>

const std::vector<std::pair<Position, std::shared_ptr<Drawable>>> &
Drawable::get_drawables() const {
  return drawables_;
}

const std::vector<std::pair<Position, Pixel>> &Drawable::get_pixels() const {
  return pixels_;
}

Position Drawable::get_position() const { return position_; }

void Drawable::set_position(const Position &position) { position_ = position; }

void Drawable::add_drawable(std::shared_ptr<Drawable> &drawable,
                            const Position &position) {
  drawables_.push_back({position, std::move(drawable)});
}
