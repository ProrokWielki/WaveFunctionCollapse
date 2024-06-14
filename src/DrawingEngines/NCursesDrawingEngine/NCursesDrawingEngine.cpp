

#include <memory>
#include <string>

#include "ncursesw/curses.h"

#include "NCursesDrawingEngine.hpp"

namespace {
constexpr int width_correction = 4;
constexpr int height_correction = 4;

} // namespace

std::string to_char(const Pixel &pixel) {
  auto gray_scale_value(0.299 * pixel.red() + 0.587 * pixel.green() +
                        0.114 * pixel.blue());

  char characters[] = "@MBHENR#KWXDFPQASUZbdehx*8Gm&04LOVYkpq5Tagns69owz$"
                      "CIu23Jcfry%1v7l+it[] {}?j|()=~!-/<>\\\"^_\';,:`. ";

  return std::string(
      1, characters[static_cast<size_t>((255 - gray_scale_value) / 2)]);
}

NCursesDrawingEngine::NCursesDrawingEngine(unsigned int width,
                                           unsigned int height)
    : DrawingEngine(width, height) {}

void NCursesDrawingEngine::show_frame_buffer() {

  initscr();
  cbreak();
  noecho();
  for (auto y = 0; y < frame_buffer_->get_height(); ++y) {
    for (auto x = 0; x < frame_buffer_->get_width(); ++x) {
      put_pixel(x, y, frame_buffer_->get_frame_buffer()[y][x]);
    }
  }

  refresh();
}

void NCursesDrawingEngine::put_pixel(int x, int y, const Pixel &pixel) {

  mvaddstr(x, y, to_char(pixel).c_str());
}

NCursesDrawingEngine::~NCursesDrawingEngine() = default;