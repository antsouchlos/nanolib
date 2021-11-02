cmake_minimum_required(VERSION 3.1)

project(arduino_lib)

add_definitions("-std=c++20")

include_directories(.)

#
# Live tests
#

#add_subdirectory(live_tests)

#
# Unit tests
#

enable_testing()
include(GoogleTest)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
endif()

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    add_subdirectory(unit_tests)
endif()

