cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

project(exercise)

# Prepare "Catch" library for other executables
find_package(Catch2 REQUIRED)

set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/extern/catch)
add_library(Catch2::Catch IMPORTED INTERFACE)
# set_property(Catch2::Catch PROPERTY INTERFACE_INCLUDE_DIRECTORIES "${CATCH_INCLUDE_DIR}")


ENABLE_TESTING()
add_executable(main_app main.cpp exercise.cpp)
add_executable(test_app tests-main.cpp exercise.cpp)

#add_test(test test_app)

include(CPack)

