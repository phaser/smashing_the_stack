cmake_minimum_required (VERSION 3.13)
project (smash)

enable_language( C CXX ASM_NASM )
set (CMAKE_ASM_NASM_LINK_EXECUTABLE "ld <FLAGS> <CMAKE_ASM_NASM_LINK_FLAGS> <LINK_FLAGS> <OBJECTS>  -o <TARGET> <LINK_LIBRARIES>")

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

# example 3
set (SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/smash/example3.c)
set (PROJECT example3)
add_executable (${PROJECT} ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE -D_FORTIFY_SOURCE=0)
target_compile_options(${PROJECT} PRIVATE -fno-stack-protector -z execstack -g -ggdb3)

# vulnerable
set (SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/smash/vulnerable.c)
set (PROJECT vulnerable)
add_executable (${PROJECT} ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE -D_FORTIFY_SOURCE=0)
target_compile_options(${PROJECT} PRIVATE -fno-stack-protector -z execstack -g -ggdb3)

# vulnerable
set (SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/smash/exploit.c)
set (PROJECT exploit)
add_executable (${PROJECT} ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE -D_FORTIFY_SOURCE=0)
target_compile_options(${PROJECT} PRIVATE -fno-stack-protector -z execstack -g -ggdb3)

# shellcode.nasm
set (SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/smash/shellcode.nasm)
set (PROJECT shellcode)
set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/smash/shellcode.nasm PROPERTIES LANGUAGE ASM_NASM)
add_executable (${PROJECT} ${SOURCES})

# shellcode_nz.nasm
set (SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/smash/shellcode_nz.nasm)
set (PROJECT shellcode_nz)
set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/smash/shellcode_nz.nasm PROPERTIES LANGUAGE ASM_NASM)
add_executable (${PROJECT} ${SOURCES})
