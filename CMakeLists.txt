cmake_minimum_required (VERSION 3.13)
project (smash)

# example 1
set (SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/smash/example1.c)
set (PROJECT example1)
add_executable (${PROJECT} ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE -D_FORTIFY_SOURCE=0)
target_compile_options(${PROJECT} PRIVATE -fno-stack-protector -z execstack -g -ggdb3)

# example 2
set (SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/smash/example2.c)
set (PROJECT example2)
add_executable (${PROJECT} ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE -D_FORTIFY_SOURCE=0)
target_compile_options(${PROJECT} PRIVATE -fno-stack-protector -z execstack -g -ggdb3)

# shellcode
set (SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/smash/shellcode.c)
set (PROJECT shellcode)
add_executable (${PROJECT} ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE -ggdb3 -static)

