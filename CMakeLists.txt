cmake_minimum_required(VERSION 2.6)
project(vulkan_wrapper)

include_directories("src")
include_directories("third_party")

if(NOT MSVC)
    list(APPEND CMAKE_CXX_FLAGS "-std=c++17")
endif()

add_subdirectory(${PROJECT_SOURCE_DIR}/src)
add_subdirectory(${PROJECT_SOURCE_DIR}/test)

add_executable(wrapper ${SOURCES})

target_link_libraries(wrapper glfw vulkan)


