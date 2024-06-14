

add_library(GUI
    GUI/drawable.hpp
    GUI/drawing_engine.hpp
    GUI/frame_buffer.hpp
    GUI/pixel.hpp
    GUI/position.hpp
    frame_buffer.cpp
    drawable.cpp
    drawing_engine.cpp
)

target_include_directories(GUI
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
	${LIB_PROJECT_NAME})