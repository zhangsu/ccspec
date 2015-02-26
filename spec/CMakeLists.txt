set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
file(GLOB_RECURSE SPEC "*.h" "*.cc")
add_executable(ccspec_spec ${SPEC})
target_link_libraries(ccspec_spec LINK_PUBLIC ccspec)
