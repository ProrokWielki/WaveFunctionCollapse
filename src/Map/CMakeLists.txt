add_library(Map
  Chunks/chunk_factory.cpp
)

target_link_libraries(Map
  PRIVATE
    GUI  
)
