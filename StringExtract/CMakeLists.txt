cmake_minimum_required(VERSION 3.27)
project(StringExtract)

set(CMAKE_CXX_STANDARD 17)
find_package(Boost 1.84.0 REQUIRED COMPONENTS ALL)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(StringExtract StringExtract.cpp)

target_link_libraries(StringExtract ${Boost_LIBRARIES})