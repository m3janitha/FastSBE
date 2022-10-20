message("CMAKE_CURRENT_LIST_DIR is ${CMAKE_CURRENT_LIST_DIR}")
message("CMAKE_CURRENT_SRC_DIR is ${CMAKE_CURRENT_SRC_DIR}")

include_directories(${CMAKE_CURRENT_LIST_DIR})
include_directories(${CMAKE_CURRENT_LIST_DIR}/FastSBE/generated)
include_directories(${CMAKE_CURRENT_LIST_DIR}/SBETool/sbetest)

set (fast_sbe_dir "${PROJECT_SOURCE_DIR}/FastSBE")
set (py_cmd "${fast_sbe_dir}/FastSBE.py")
set (log_file "${CMAKE_CURRENT_LIST_DIR}/log.txt")
set (schema_file "${CMAKE_CURRENT_LIST_DIR}/example-schema.xml")
set (out_folder "${CMAKE_CURRENT_LIST_DIR}/FASTSBE/generated")
set (override_namespace "test::sbe")

message("py_cmd is ${py_cmd} ${log_file} ${schema_file} ${out_folder} ${override_namespace}" )

if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/generated/__header.h)
    message(FATAL_ERROR "File \"${CMAKE_CURRENT_LIST_DIR}/generated/__header.h\" found, \
    this should never be created, remove!")
endif()

add_custom_target(
    generate_fast_sbe_benchmark ALL
    DEPENDS ${CMAKE_CURRENT_LIST_DIR}/generated/__header.h
)

add_custom_command(
    OUTPUT
        ${CMAKE_CURRENT_LIST_DIR}/generated/__header.h
        ${CMAKE_CURRENT_LIST_DIR}/generated/CancelReplace.h
    COMMAND ${PYTHON_EXECUTABLE} ${py_cmd} ${log_file} ${schema_file} ${out_folder} ${override_namespace}
    WORKING_DIRECTORY ${fast_sbe_dir}
)

get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach(dir ${dirs})
  message(STATUS "include dirs='${dir}'")
endforeach()

add_executable(perf_test perf_test.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/generated/__header.h
)

target_link_libraries(perf_test GTest::gtest GTest::gtest_main)
target_link_libraries(perf_test benchmark::benchmark)

add_executable(msg_test msg_test.cpp)

target_link_libraries(msg_test GTest::gtest GTest::gtest_main)
target_link_libraries(msg_test benchmark::benchmark)
#target_link_libraries(FastSBE PRIVATE benchmark::benchmark)



