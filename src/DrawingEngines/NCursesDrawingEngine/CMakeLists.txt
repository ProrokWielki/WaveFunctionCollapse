add_library(NCursesDrawingEngine
    NCursesDrawingEngine.hpp
    NCursesDrawingEngine.cpp
)

target_link_libraries(NCursesDrawingEngine 
  PUBLIC
    GUI
  PRIVATE
    Curses::Curses
) 

target_include_directories(NCursesDrawingEngine
  PUBLIC
	  ${CMAKE_CURRENT_SOURCE_DIR}
		${LIB_PROJECT_NAME})