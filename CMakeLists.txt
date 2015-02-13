cmake_minimum_required(VERSION 2.8.12)

if(APPLE)
   set(CMAKE_MACOSX_RPATH ON)
endif()

project(ccspec)
add_subdirectory(src)
add_subdirectory(demo)
