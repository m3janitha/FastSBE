message("CMAKE_CURRENT_LIST_DIR is ${CMAKE_CURRENT_LIST_DIR}")
message("CMAKE_CURRENT_SRC_DIR is ${CMAKE_CURRENT_SRC_DIR}")

include(FindPythonInterp)

set (fast_sbe_dir "${PROJECT_SOURCE_DIR}/FastSBE")
set (py_cmd "${fast_sbe_dir}/FastSBE.py")
set (log_file "${CMAKE_CURRENT_LIST_DIR}/log.txt")
set (schema_file "${CMAKE_CURRENT_LIST_DIR}/example-schema.xml")
set (out_folder "${CMAKE_CURRENT_LIST_DIR}/generated")
set (override_namespace "test::sbe")

message("py_cmd is ${py_cmd} ${log_file} ${schema_file} ${out_folder} ${override_namespace}" )

if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/generated/__header.h)
    message(FATAL_ERROR "File \"${CMAKE_CURRENT_LIST_DIR}/generated/__header.h\" found, \
    this should never be created, remove!")
endif()

include_directories(${CMAKE_CURRENT_LIST_DIR})
include_directories(${PROJECT_SOURCE_DIR}/tests/utility)
include_directories(${CMAKE_CURRENT_LIST_DIR}/generated)

add_executable(decode_sbe_v2 decode_sbe_v2.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/generated/__header.h
)

target_link_libraries(decode_sbe_v2 GTest::gtest GTest::gtest_main)

add_test(NAME decode_sbe_v2 COMMAND decode_sbe_v2
)

add_custom_target(
    sbe_v2_target ALL
    DEPENDS ${CMAKE_CURRENT_LIST_DIR}/generated/__header.h
)

add_custom_command(
    OUTPUT
        ${CMAKE_CURRENT_LIST_DIR}/generated/__header.h
        ${CMAKE_CURRENT_LIST_DIR}/generated/CancelReplace.h
    COMMAND ${PYTHON_EXECUTABLE} ${py_cmd} ${log_file} ${schema_file} ${out_folder} ${override_namespace}
    WORKING_DIRECTORY ${fast_sbe_dir}
)




