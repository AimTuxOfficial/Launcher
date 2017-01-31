cmake_minimum_required(VERSION 2.8)
project(AimTuxLauncher)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(AimTuxLauncher ${SOURCES})

INCLUDE(FindPkgConfig)

pkg_check_modules(GTKMM3 REQUIRED gtkmm-3.0)

include_directories(${GTKMM3_INCLUDE_DIRS})
link_directories(${GTKMM3_LIBRARY_DIRS})
add_definitions(${GTKMM3_CFLAGS_OTHER})

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${GTKMM3_LIBRARIES})
