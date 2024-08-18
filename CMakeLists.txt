cmake_minimum_required(VERSION 3.28)
project(Interests_C_Plus_Plus)
find_package(OpenCV REQUIRED)
find_package(Boost 1.84.0 REQUIRED COMPONENTS ALL)

set(CMAKE_CXX_STANDARD 17)
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})

add_executable(Interests_C_Plus_Plus main.cpp
        main.cpp)
target_link_libraries(Interests_C_Plus_Plus ${OpenCV_LIBS})
target_link_libraries(Interests_C_Plus_Plus ${Boost_LIBRARIES})

# print
message(STATUS "include_directories: ${OpenCV_INCLUDE_DIRS}")
message(STATUS "target_link_libraries: ${OpenCV_LIBS}")

