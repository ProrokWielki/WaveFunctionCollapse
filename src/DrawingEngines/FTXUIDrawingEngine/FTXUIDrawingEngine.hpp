
#pragma once

#include "GUI/drawing_engine.hpp"

namespace ftxui {
class Canvas;
class Screen;
} // namespace ftxui

class FTXUIrawingEngine : public DrawingEngine {
public:
  FTXUIrawingEngine(unsigned int width, unsigned int height);
  void show_frame_buffer() override;
  ~FTXUIrawingEngine();

private:
  void put_pixel(int x, int y, const Pixel &pixel);

  std::shared_ptr<ftxui::Canvas> canvas_;
  std::shared_ptr<ftxui::Screen> screen_;
};