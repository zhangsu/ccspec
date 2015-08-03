cmake_minimum_required(VERSION 2.8.11)

if(BIICODE)
  include("biicode.cmake")
  return()
endif()

if(APPLE)
  set(CMAKE_MACOSX_RPATH ON)
endif()

project(ccspec)
add_subdirectory(src)
add_subdirectory(spec)
add_subdirectory(demo)
enable_testing()
add_test(NAME ccspec_spec COMMAND ccspec_spec)
