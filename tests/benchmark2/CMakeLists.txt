message("CMAKE_CURRENT_LIST_DIR is ${CMAKE_CURRENT_LIST_DIR}")
message("CMAKE_CURRENT_SRC_DIR is ${CMAKE_CURRENT_SRC_DIR}")

include_directories(${CMAKE_CURRENT_LIST_DIR})
include_directories(${PROJECT_SOURCE_DIR}/tests/utility)
include_directories(${CMAKE_CURRENT_LIST_DIR}/FastSBE/fastsbe)
include_directories(${CMAKE_CURRENT_LIST_DIR}/SBETool/sbetool)

set (fast_sbe_dir "${PROJECT_SOURCE_DIR}/FastSBE")
set (py_cmd "${fast_sbe_dir}/FastSBE.py")
set (log_file "${CMAKE_CURRENT_LIST_DIR}/log.txt")
set (schema_file "${CMAKE_CURRENT_LIST_DIR}/example-schema-sbe-v1.xml")
set (out_folder "${CMAKE_CURRENT_LIST_DIR}/FASTSBE/fastsbe")
set (override_namespace "fastsbe")

message("py_cmd is ${py_cmd} ${log_file} ${schema_file} ${out_folder} ${override_namespace}" )

if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/FastSBE/fastsbe/__header.h)
    message(FATAL_ERROR "File \"${CMAKE_CURRENT_LIST_DIR}/fastsbe/__header.h\" found, \
    this should never be created, remove!")
endif()

add_custom_target(
    generate_fastsbe_schema ALL
    DEPENDS ${CMAKE_CURRENT_LIST_DIR}/FastSBE/fastsbe/__header.h
)

add_custom_command(
    OUTPUT
        ${CMAKE_CURRENT_LIST_DIR}/FastSBE/fastsbe/__header.h
        ${CMAKE_CURRENT_LIST_DIR}/FastSBE/fastsbe/NewOrderSingle.h
    COMMAND ${PYTHON_EXECUTABLE} ${py_cmd} ${log_file} ${schema_file} ${out_folder} ${override_namespace}
    WORKING_DIRECTORY ${fast_sbe_dir}
)

get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach(dir ${dirs})
  message(STATUS "include dirs='${dir}'")
endforeach()

add_executable(benchmark_test benchmark_test.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/FastSBE/fastsbe/__header.h
)

target_link_libraries(benchmark_test GTest::gtest GTest::gtest_main)
target_link_libraries(benchmark_test benchmark::benchmark)

add_executable(validation_test validation_test.cpp)

target_link_libraries(validation_test GTest::gtest GTest::gtest_main)
target_link_libraries(validation_test benchmark::benchmark)
#target_link_libraries(FastSBE PRIVATE benchmark::benchmark)



