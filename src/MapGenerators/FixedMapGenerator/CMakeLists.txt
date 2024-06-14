add_library(FixedMapGenerator 
   fixed_map_generator.cpp
   fixed_map_generator.hpp
)

target_link_libraries(FixedMapGenerator
  PUBLIC
    MapGenerator  
)

