message("CMAKE_CURRENT_LIST_DIR is ${CMAKE_CURRENT_LIST_DIR}")
message("CMAKE_CURRENT_SRC_DIR is ${CMAKE_CURRENT_SRC_DIR}")

include(FetchContent)

include_directories(${CMAKE_CURRENT_LIST_DIR})
include_directories(${CMAKE_CURRENT_LIST_DIR}/generated)
include_directories(${CMAKE_CURRENT_LIST_DIR}/genSBE/sbetest)

#include_directories(${googletest_SOURCE_DIR}/googletest/include)
include_directories(${googlebenchmark_SOURCE_DIR}/include)

get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach(dir ${dirs})
  message(STATUS "include dirs='${dir}'")
endforeach()

add_executable (perf_test perf_test.cpp)

target_link_libraries(perf_test GTest::gtest GTest::gtest_main)
target_link_libraries(perf_test benchmark::benchmark)

add_executable (msg_test msg_test.cpp)

target_link_libraries(msg_test GTest::gtest GTest::gtest_main)
target_link_libraries(msg_test benchmark::benchmark)
#target_link_libraries(FastSBE PRIVATE benchmark::benchmark)



