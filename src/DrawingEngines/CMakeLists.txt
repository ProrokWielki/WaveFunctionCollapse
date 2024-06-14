
add_library(DrawingEngineFactory 
    DrawingEngine/DrawingEngineFactory.cpp 
    DrawingEngine/DrawingEngineFactory.hpp
)

target_link_libraries(DrawingEngineFactory
  PUBLIC
    GUI
  PRIVATE
    CLIDrawingEngine
    FTXUIDrawingEngine
    NCursesDrawingEngine
)

target_include_directories(DrawingEngineFactory
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
	${LIB_PROJECT_NAME})

add_subdirectory(CLIDrawingEngine)
add_subdirectory(FTXUIDrawingEngine)
add_subdirectory(NCursesDrawingEngine)