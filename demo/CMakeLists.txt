set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_executable(demo demo.cc)
target_link_libraries(demo LINK_PUBLIC ccspec)
