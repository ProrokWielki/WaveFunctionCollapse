#pragma once

#include "GUI/drawing_engine.hpp"

class CLIDrawingEngine : public DrawingEngine {
public:
  CLIDrawingEngine(unsigned int width, unsigned int height)
      : DrawingEngine(width, height) {}
  void show_frame_buffer() override;
};