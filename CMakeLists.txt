cmake_minimum_required(VERSION 3.16)
project(PanicLib)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
find_package(SDL2 REQUIRED)
find_package(SDL2TTF REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2TTF_INCLUDE_DIRS})
include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_library(Panic ${SOURCES})

# For some reason we need to explicitly link with SDL2 as well as it's libraries, tbh i have no idea why but it works
target_link_libraries(Panic SDL2 ${SDL2_LIBRARIES} SDL2_ttf ${SDL2TTF_LIBRARIES})
add_subdirectory(demo)