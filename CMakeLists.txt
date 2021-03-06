cmake_minimum_required(VERSION 3.5)
project(renderer)

set(CMAKE_CXX_STANDARD 14)

set(default_build_type "Release")
if(EXISTS "${CMAKE_SOURCE_DIR}/.git")
  set(default_build_type "RelWithDebInfo")
  add_definitions(-DGLDEBUG)
endif()

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
  message(STATUS "Use -DCMAKE_BUILD_TYPE=${default_build_type} to specify build type")
  set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
      STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

find_package(OpenGL REQUIRED)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(third-party/glfw)
include_directories(third-party/glfw/include)
include_directories(third-party/glad/include)
include_directories(third-party/glm)
include_directories(third-party/stb)
include_directories(third-party/tinyobjloader)
include_directories(third-party)
include_directories(${OPENGL_INCLUDE_DIR})

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(SOURCE_FILES
  src/main.cpp
  src/env.cpp
  src/game.cpp
  src/shader.cpp
  src/shader_cache.cpp
  src/renderer.cpp
  src/text_renderer.cpp
  src/ui_renderer.cpp
  src/camera.cpp
  src/vao.cpp
  src/texture.cpp
  src/io.cpp
  src/model.cpp
  third-party/glad/src/glad.c)

add_executable(renderer ${SOURCE_FILES})

if (MSVC)
  set_target_properties(renderer PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
  set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT renderer)
endif(MSVC)

target_link_libraries(renderer glfw ${GLFW_LIBRARIES})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")
