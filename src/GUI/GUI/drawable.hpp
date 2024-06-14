#pragma once

#include <memory>
#include <vector>

#include "pixel.hpp"
#include "position.hpp"

class Drawable {
public:
  const std::vector<std::pair<Position, std::shared_ptr<Drawable>>> &
  get_drawables() const;
  virtual const std::vector<std::pair<Position, Pixel>> &get_pixels() const;
  Position get_position() const;
  void set_position(const Position &position);
  void add_drawable(std::shared_ptr<Drawable> &drawable,
                    const Position &position);

  virtual unsigned int get_width() const { return 1; }
  virtual unsigned int get_height() const { return 1; }

  virtual ~Drawable() = default;

protected:
  Drawable() = default;
  std::vector<std::pair<Position, Pixel>> pixels_{};

private:
  Position position_{};
  std::vector<std::pair<Position, std::shared_ptr<Drawable>>> drawables_{};
};