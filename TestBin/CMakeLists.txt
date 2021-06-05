cmake_minimum_required(VERSION 3.19)
project(TestBin)

set(CMAKE_CXX_STANDARD 20)

# find MakeEngine lib
set(INC_DIR ../include)
set(LIB_DIR ../cmake-build-debug)

include_directories(${INC_DIR})
link_directories(${LIB_DIR})
link_libraries(MakeEngine)

add_executable(TestBin main.cpp)

target_link_libraries(TestBin MakeEngine)