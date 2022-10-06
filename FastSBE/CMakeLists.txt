add_subdirectory(src)

FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)

set(BENCHMARK_ENABLE_TESTING OFF)

FetchContent_Declare(
	googlebenchmark
	GIT_REPOSITORY https://github.com/google/benchmark
	GIT_TAG v1.6.0
)

FetchContent_MakeAvailable(googlebenchmark)

include(FindPythonInterp)