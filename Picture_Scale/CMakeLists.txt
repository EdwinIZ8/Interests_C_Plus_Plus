cmake_minimum_required(VERSION 3.28)
project(Picture_Scale)
find_package(OpenCV REQUIRED)

set(CMAKE_CXX_STANDARD 17)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(Picture_Scale Picture_Scale.cpp)
target_link_libraries(Picture_Scale ${OpenCV_LIBS})

# print
message(STATUS "include_directories: ${OpenCV_INCLUDE_DIRS}")
message(STATUS "target_link_libraries: ${OpenCV_LIBS}")