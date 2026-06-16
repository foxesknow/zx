cmake_minimum_required(VERSION 3.25)

project(zx CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED  ON)

file(GLOB_RECURSE ZX_HEADERS "include/zx/**.h")

add_library(${PROJECT_NAME} INTERFACE)

add_subdirectory(tests)

target_include_directories(
    ${PROJECT_NAME}
    INTERFACE
    $<BUILD_INTERFACE:${${PROJECT_NAME}_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)