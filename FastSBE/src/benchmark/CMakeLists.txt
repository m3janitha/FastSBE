

# this helps remove the MSVCRTD warning
#add_definitions(-DNODEFAULTLIB:MSVCRTD)

# this helps remove a bunch of static vs dynamic erros
#set(CMAKE_CXX_FLAGS_DEBUG "/MTd")

#add_executable(max_test 
#	src/test.cpp src/Application.h src/Application.cpp src/Messages.h src/NewsTracker.cpp src/NewsTracker.h)

#target_link_libraries(max_test GTest::gtest GTest::gtest_main)
#add_test(NAME max_test COMMAND max_test)



