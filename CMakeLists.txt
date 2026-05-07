cmake_minimum_required(VERSION 3.20)
project(carena C)

set(CMAKE_C_STANDARD 11)

# Executable:
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

add_executable(carena
    main.c
    carena.c
    test.c
)

# Include:
target_include_directories(carena
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
