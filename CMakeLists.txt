cmake_minimum_required(VERSION 3.20)
project(HomeWork30_4_1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(BUILD_CPR_TESTS OFF)
set(CMAKE_USE_OPENSSL OFF)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git GIT_TAG f4622efcb59d84071ae11404ae61bd821c1c344b) # the commit hash for 1.6.2
FetchContent_MakeAvailable(cpr)

add_executable(HomeWork30_4_1 main.cpp)
target_link_libraries(HomeWork30_4_1 cpr::cpr)