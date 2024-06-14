#include <iostream>
#include <memory>

#include <argparse/argparse.hpp>

#include "MapGenerator/map_generator_factory.hpp"
#include <DrawingEngine/DrawingEngineFactory.hpp>

#include "Map/map.hpp"

DrawingEngineType to_drawing_engine_type(std::string name) {
  if (name == "CLI")
    return DrawingEngineType::CLI;
  if (name == "CURSES")
    return DrawingEngineType::NCURSES;
  return DrawingEngineType::FTXUI;
}

MapGenerators to_map_generator(std::string name) {
  if (name == "FIXED")
    return MapGenerators::Fixed;
  return MapGenerators::WaveFunctionCollapse;
}

int main(int argc, char *argv[]) {

  argparse::ArgumentParser program("Wave function collapse");

  program.add_argument("--drawing_engine")
      .help("Choose which drawing engine to use.")
      // .choices("CLI", "FTXUI")
      .required();

  program.add_argument("--map_generator")
      .help("Choose which map generator to use.")
      // .choices("FIXED", "WFC")
      .required();

  program.add_argument("--width")
      .help("Map width")
      .scan<'d', int>()
      .default_value(5);

  program.add_argument("--height")
      .help("Map height")
      .scan<'d', int>()
      .default_value(5);

  try {
    program.parse_args(argc, argv);
  } catch (const std::exception &err) {
    std::cerr << err.what() << std::endl;
    std::cerr << program;
    return 1;
  }

  auto width = program.get<int>("width");
  auto height = program.get<int>("height");

  auto map_generator = MapGeneratorFactory::create(
      to_map_generator(program.get("map_generator")), width, height);
  auto drawing_engine = DrawingEngineFactory::create(
      to_drawing_engine_type(program.get("drawing_engine")), 50, 50);

  std::shared_ptr<Map> map{std::make_shared<Map>(width, height)};

  auto tiles = map_generator->generate();
  map->generate(tiles);

  drawing_engine->draw(map, {0, 0});
  drawing_engine->show_frame_buffer();

  return 0;
}