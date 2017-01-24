cmake_minimum_required(VERSION 2.8)
project(AimTuxLauncher)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(AimTuxLauncher ${SOURCES})

INCLUDE(FindPkgConfig)

TARGET_LINK_LIBRARIES(${PROJECT_NAME})
