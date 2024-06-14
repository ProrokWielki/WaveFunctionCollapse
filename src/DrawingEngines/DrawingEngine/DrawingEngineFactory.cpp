#include <cstddef>
#include <memory>

#include "DrawingEngineFactory.hpp"

#include "CLIDrawingEngine.hpp"
#include "FTXUIDrawingEngine.hpp"
#include "NCursesDrawingEngine/NCursesDrawingEngine.hpp"

std::shared_ptr<DrawingEngine>
DrawingEngineFactory::create(DrawingEngineType type, unsigned int width,
                             unsigned int height) {
  switch (type) {
  case DrawingEngineType::FTXUI:
    return std::make_shared<FTXUIrawingEngine>(width, height);
  case DrawingEngineType::CLI:
    return std::make_shared<CLIDrawingEngine>(width, height);
  case DrawingEngineType::NCURSES:
    return std::make_shared<NCursesDrawingEngine>(width, height);
  default:
    return nullptr;
  };
}
