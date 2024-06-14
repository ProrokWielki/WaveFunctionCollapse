
#pragma once

#include "GUI/drawing_engine.hpp"

class NCursesDrawingEngine : public DrawingEngine {
public:
  NCursesDrawingEngine(unsigned int width, unsigned int height);
  void show_frame_buffer() override;
  ~NCursesDrawingEngine();

private:
  void put_pixel(int x, int y, const Pixel &pixel);
};