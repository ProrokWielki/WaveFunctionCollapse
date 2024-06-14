add_executable(${CMAKE_PROJECT_NAME} main.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME} 
  DrawingEngineFactory 
  MapGeneratorFactory
  Map
  argparse::argparse
)

add_subdirectory(GUI)
add_subdirectory(DrawingEngines)
add_subdirectory(MapGenerators)
add_subdirectory(Map)