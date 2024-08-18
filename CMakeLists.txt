cmake_minimum_required(VERSION 3.28)
project(Interests_C_Plus_Plus)
find_package(Boost REQUIRED COMPONENTS ALL)
find_package(OpenCV)

set(CMAKE_CXX_STANDARD 17)
include_directories(${OpenCV_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})

add_executable(Interests_C_Plus_Plus main.cpp)
target_link_libraries(Interests_C_Plus_Plus ${OpenCV_LIBS} ${Boost_LIBRARIES})