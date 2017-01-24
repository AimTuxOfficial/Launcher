cmake_minimum_required(VERSION 2.8)
project(AimTuxLauncher)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(AimTuxLauncher ${SOURCES})

INCLUDE(FindPkgConfig)

pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
add_definitions(${GTK3_CFLAGS_OTHER})

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${GTK3_LIBRARIES})
