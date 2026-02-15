cmake_minimum_required (VERSION 3.20)
project(fw_graphics)

add_library(fw_graphics)
target_sources(fw_graphics PRIVATE
    "src/index_buffer.cpp"
    "src/vertex_buffer.cpp"
    "src/vertex_array.cpp"
    "src/shader.cpp"
    "src/mesh.cpp"
    "src/vertex_int8.cpp"
    "src/vertex_f.cpp"
    "src/renderer2d.cpp"
)
target_include_directories(fw_graphics PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(fw_graphics PUBLIC
    glad
    glm::glm
    fw_utility
)