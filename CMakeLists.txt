cmake_minimum_required(VERSION 4.0)
project(nXoshiro256 C)

add_library(nXoshiro256 STATIC src/Xoshiro256.c)

target_include_directories(nXoshiro256 PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>)

target_compile_options(nXoshiro256 PRIVATE 
    -O2 
)
