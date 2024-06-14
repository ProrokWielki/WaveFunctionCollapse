add_library(WaveFunctionColapseMapGenerator 
    wave_function_colapse_generator.cpp
    wave_function_colapse_generator.hpp
)

target_link_libraries(WaveFunctionColapseMapGenerator
  PUBLIC
    MapGenerator  
)

