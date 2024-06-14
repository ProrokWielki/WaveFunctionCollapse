#pragma once

#include "GUI/drawing_engine.hpp"
#include <memory>

enum class DrawingEngineType { FTXUI, CLI, NCURSES };

class DrawingEngineFactory {
public:
  static std::shared_ptr<DrawingEngine>
  create(DrawingEngineType type, unsigned int width, unsigned int height);

private:
  DrawingEngineFactory() = default;
};