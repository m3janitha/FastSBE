cmake_minimum_required (VERSION 3.24)

project(FastSBE VERSION 0.1.0)

set(CMAKE_CPP_COMPILER g++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

set(CMAKE_CONFIGURATION_TYPES "Release" CACHE STRING "" FORCE)

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    message("setting CMAKE_CXX_FLAGS")
    set(CMAKE_BUILD_TYPE Release)
    set(CMAKE_CXX_FLAGS "-O3")
endif()

add_subdirectory(FastSBE)

