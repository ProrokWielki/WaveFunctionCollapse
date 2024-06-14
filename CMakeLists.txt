cmake_minimum_required(VERSION 3.29)

project(RandomMap)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(ftxui REQUIRED)
find_package(argparse REQUIRED)
find_package(Curses REQUIRED)

add_subdirectory(src)
