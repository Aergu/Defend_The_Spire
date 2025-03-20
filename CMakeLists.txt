cmake_minimum_required(VERSION 3.30)

# Automatically set project name to the folder name
get_filename_component(PROJECT_NAME ${CMAKE_SOURCE_DIR} NAME)
project(Defend_The_Spire C)

set(CMAKE_C_STANDARD 11)

# Set Raylib directory path
set(RAYLIB_DIR "C:/raylib/raylib/src")

# Include Raylib
include_directories(${RAYLIB_DIR})
link_directories(${RAYLIB_DIR})


# Add the executable using the dynamically set project name
add_executable(Defend_The_Spire main.c
        grid_map.h

)

# Link Raylib and required system libraries
target_link_libraries(Defend_The_Spire raylib opengl32 gdi32 winmm)