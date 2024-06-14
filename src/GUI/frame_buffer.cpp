
#include "GUI/frame_buffer.hpp"
#include "GUI/pixel.hpp"
#include "GUI/position.hpp"

FrameBuffer::FrameBuffer(unsigned int width, unsigned int height)
    : width_{width}, height_{height} {

  for (auto y = 0; y < height; ++y) {
    pixels_.push_back({});
    for (auto x = 0; x < width; ++x) {
      pixels_.back().push_back(Pixel());
    }
  }
}

void FrameBuffer::set_pixel(const Position &position, const Pixel &pixel) {
  if (position.x() >= width_ or position.x() < 0 or position.y() >= height_ or
      position.y() < 0) {
    return;
  }

  pixels_[position.y()][position.x()] = pixel;
}

const std::vector<std::vector<Pixel>> &FrameBuffer::get_frame_buffer() const {
  return pixels_;
};

std::vector<std::vector<Pixel>> &FrameBuffer::get_frame_buffer() {
  return pixels_;
};