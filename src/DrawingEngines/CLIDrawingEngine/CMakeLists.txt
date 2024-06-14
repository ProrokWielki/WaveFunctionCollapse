add_library(CLIDrawingEngine
    CLIDrawingEngine.hpp
    CLIDrawingEngine.cpp
)

target_link_libraries(CLIDrawingEngine 
  PUBLIC
    GUI
) 

target_include_directories(CLIDrawingEngine
  PUBLIC
	  ${CMAKE_CURRENT_SOURCE_DIR}
		${LIB_PROJECT_NAME})