

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/triangle)
add_executable(triangle_demo ${TRIANGLE_SOURCES} ${SOURCES})

target_link_libraries(triangle_demo glfw vulkan)
