cmake_minimum_required (VERSION 3.13)
project (smash)

set (SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/smash/example1.c)

add_executable (smash ${SOURCES})

target_compile_definitions(smash PRIVATE -D_FORTIFY_SOURCE=0)
target_compile_options(smash PRIVATE -fno-stack-protector -z execstack -g -ggdb3)