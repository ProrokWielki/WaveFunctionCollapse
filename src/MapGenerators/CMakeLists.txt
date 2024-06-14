add_library(MapGenerator 
    MapGenerator/map_generator.hpp)

set_target_properties(MapGenerator PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(MapGenerator
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
	${LIB_PROJECT_NAME})
