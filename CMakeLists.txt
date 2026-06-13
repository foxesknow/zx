cmake_minimum_required(VERSION 3.25)

project(zx CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED  ON)

file(GLOB_RECURSE ZX_HEADERS "include/zx/**.h")