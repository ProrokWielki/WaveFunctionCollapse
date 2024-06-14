add_library(MapGenerator 
    MapGenerator/map_generator.hpp)

set_target_properties(MapGenerator PROPERTIES LINKER_LANGUAGE CXX)

add_library(MapGeneratorFactory
    MapGenerator/map_generator_factory.hpp
    MapGenerator/map_generator_factory.cpp
)

target_include_directories(MapGenerator
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
	${LIB_PROJECT_NAME})

target_link_libraries(MapGeneratorFactory
  PUBLIC
    MapGenerator
  PRIVATE
    WaveFunctionColapseMapGenerator  
    FixedMapGenerator
)

add_subdirectory(WaveFunctionColapseMapGenerator)
add_subdirectory(FixedMapGenerator)