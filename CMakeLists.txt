cmake_minimum_required(VERSION 3.16)
project(CorrosionEngine LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(glfw3 3.3 REQUIRED)

set(SOURCES
    src/main.cpp
    src/core/log/log.cpp
    src/core/glad.c
)

add_executable(CorrosionEngine ${SOURCES}
    src/core/shader/shader.h
    src/core/stb_image.c)

target_include_directories(CorrosionEngine PRIVATE 
    src
    includes
)

target_link_libraries(CorrosionEngine PRIVATE glfw)

add_custom_command(TARGET CorrosionEngine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_CURRENT_SOURCE_DIR}/assets" 
    "$<TARGET_FILE_DIR:CorrosionEngine>/assets"
)