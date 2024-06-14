#pragma once

#include <vector>

#include <GUI/pixel.hpp>

class Drawable;
class Position;

class FrameBuffer {
public:
  FrameBuffer(unsigned int width, unsigned int height);
  void set_pixel(const Position &position, const Pixel &pixel);

  const std::vector<std::vector<Pixel>> &get_frame_buffer() const;
  std::vector<std::vector<Pixel>> &get_frame_buffer();

  unsigned int get_width() const { return width_; }
  unsigned int get_height() const { return height_; }

private:
  std::vector<std::vector<Pixel>> pixels_{};
  unsigned int width_{};
  unsigned int height_{};
};