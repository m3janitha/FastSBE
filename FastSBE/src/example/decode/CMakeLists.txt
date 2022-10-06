message("CMAKE_CURRENT_LIST_DIR is ${CMAKE_CURRENT_LIST_DIR}")
message("CMAKE_CURRENT_SRC_DIR is ${CMAKE_CURRENT_SRC_DIR}")

include(FindPythonInterp)

set (py_cmd "${CMAKE_CURRENT_LIST_DIR}/../../python/FastSBE.py")
set (log_file "${CMAKE_CURRENT_LIST_DIR}/log.txt")
set (schema_file "${CMAKE_CURRENT_LIST_DIR}/example-schema.xml")
set (out_folder "${CMAKE_CURRENT_LIST_DIR}/generated")
set (override_namespace "test::sbe")

include_directories(${CMAKE_CURRENT_LIST_DIR})
include_directories(${CMAKE_CURRENT_LIST_DIR}/generated)

if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/generated/__header.h)
    message(FATAL_ERROR "File \"${CMAKE_CURRENT_LIST_DIR}/generated/__header.h\" found, \
    this should never be created, remove!")
endif()

add_executable(decode_test decode.cpp ${CMAKE_CURRENT_LIST_DIR}/generated/__header.h)

add_custom_target(
    always_run_target ALL
    DEPENDS ${CMAKE_CURRENT_LIST_DIR}/generated/__header.h
)

add_custom_command(
    OUTPUT
        ${CMAKE_CURRENT_LIST_DIR}/generated/__header.h
        ${CMAKE_CURRENT_LIST_DIR}/generated/CancelReplace.h
    COMMAND ${PYTHON_EXECUTABLE} ${py_cmd} ${log_file} ${schema_file} ${out_folder} ${override_namespace}
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/../../python
)




