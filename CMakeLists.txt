cmake_minimum_required(VERSION 3.21.0)
project(Starfields)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(lib/external/GLFW)
add_subdirectory(lib/external/GLEW)
add_executable(${PROJECT_NAME} Starfields.c)
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} glfw libglew_static)