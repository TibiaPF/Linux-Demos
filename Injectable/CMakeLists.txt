cmake_minimum_required(VERSION 2.6)

project(injectable)

add_library(injectable STATIC SHARED main.cpp)
set_target_properties(injectable PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")
