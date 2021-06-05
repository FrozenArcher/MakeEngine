cmake_minimum_required(VERSION 3.19)
project(MakeEngine)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -D ME_DEBUG_MODE")

include_directories(./include ./src ./src/MESystem ./src/MEApplication)

# here
add_subdirectory(test_bin)
add_subdirectory(src)

target_link_libraries(TestMakeEngine MakeEngine)

# below: sdl configures
INCLUDE(FindPkgConfig)

pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_IMG REQUIRED SDL2_image)
pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)
pkg_check_modules(SDL2_MIX REQUIRED SDL2_mixer)

include_directories(${SDL2_INCLUDE_DIRS}
        ${SDL2_IMG_INCLUDE_DIRS}
        ${SDL2_TTF_INCLUDE_DIRS}
        ${SDL2_MIX_INCLUDE_DIRS})

link_directories (${SDL2_LIBRARY_DIRS}
        ${SDL2_IMG_LIBRARY_DIRS}
        ${SDL2_TTF_LIBRARY_DIRS}
        ${SDL2_MIX_LIBRARY_DIRS})

target_link_libraries (MakeEngine
        ${SDL2_LIBRARIES}
        ${SDL2_IMG_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
        ${SDL2_MIX_LIBRARIES})
