#include <iostream>

#include <GUI/pixel.hpp>

#include "CLIDrawingEngine.hpp"

char to_char(const Pixel &pixel) {
  auto gray_scale_value(0.299 * pixel.red() + 0.587 * pixel.green() +
                        0.114 * pixel.blue());

  char characters[] = "@MBHENR#KWXDFPQASUZbdehx*8Gm&04LOVYkpq5Tagns69owz$"
                      "CIu23Jcfry%1v7l+it[] {}?j|()=~!-/<>\\\"^_\';,:`. ";

  return characters[static_cast<size_t>((255 - gray_scale_value) / 2)];
}

void CLIDrawingEngine::show_frame_buffer() {
  for (const auto &line : frame_buffer_->get_frame_buffer()) {
    for (const auto &pixel : line) {
      std::cout << to_char(pixel);
    }
    std::cout << '\n';
  }
}