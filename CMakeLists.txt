cmake_minimum_required (VERSION 3.13)
project (smash)

set (SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/smash/example1.c)

add_executable (smash ${SOURCES})