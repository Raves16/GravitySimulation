cmake_minimum_required(VERSION 3.22.1)
project(gravity)
include_directories(
    $(CMAKE_SOURCE_DIR)/glad 
    $(CMAKE_SOURCE_DIR)/include
)

configure_file(${CMAKE_SOURCE_DIR}/shaders/default.vert ${CMAKE_BINARY_DIR}/shaders/default.vert COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/shaders/default.frag ${CMAKE_BINARY_DIR}/shaders/default.frag COPYONLY)

add_executable(gravity 
    glad/glad.c
    src/main.cpp
    src/Circle.cpp
    src/VAO.cpp
    src/VBO.cpp
    src/Vector2f.cpp
    src/shaderClass.cpp
    src/Vector3f.cpp
    src/GravityEngine.cpp
)

install(TARGETS gravity DESTINATION bin)

target_link_libraries(gravity
    -lGL
    -lglfw
)
