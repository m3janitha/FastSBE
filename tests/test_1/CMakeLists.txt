message("CMAKE_CURRENT_LIST_DIR is ${CMAKE_CURRENT_LIST_DIR}")
message("CMAKE_CURRENT_SRC_DIR is ${CMAKE_CURRENT_SRC_DIR}") 

include_directories(${CMAKE_CURRENT_LIST_DIR})

add_executable (test_1
	main.cpp "message_test.h" )



