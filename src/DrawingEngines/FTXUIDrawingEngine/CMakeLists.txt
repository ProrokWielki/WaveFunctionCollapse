add_library(FTXUIDrawingEngine
    FTXUIDrawingEngine.hpp
    FTXUIDrawingEngine.cpp
)

target_link_libraries(FTXUIDrawingEngine 
  PUBLIC
    GUI
  PRIVATE 
    ftxui::ftxui
) 

target_include_directories(FTXUIDrawingEngine
  PUBLIC
	  ${CMAKE_CURRENT_SOURCE_DIR}
		${LIB_PROJECT_NAME})