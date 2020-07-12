cmake_minimum_required(VERSION 3.3)

set(CMAKE_CXX_STANDARD 11)

set(GLSAMPLE_PROJECT_NAME GLSample)

project(${GLSAMPLE_PROJECT_NAME})

set( GLSAMPLE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR} CACHE STRING "Output directory")
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY "${GLSAMPLE_OUTPUT_DIRECTORY}/bin" )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/RELEASE" )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/DEBUG" )

option (glew-cmake_BUILD_SHARED "Build shared libraries" ON)
set(glew-cmake_BUILD_SHARED OFF)
option(glew-cmake_BUILD_SINGLE_CONTEXT "Build the single context glew library" ON)
set(glew-cmake_BUILD_SINGLE_CONTEXT OFF)
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/lib/glfw")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/lib/glew")
OPTION( BUILD_SHARED_LIBS
  "Build package with shared libraries."
  ON
)
set(BUILD_SHARED_LIBS OFF)
OPTION( ASSIMP_BUILD_ASSIMP_TOOLS
  "If the supplementary tools for Assimp are built in addition to the library."
  ON
)
set(ASSIMP_BUILD_ASSIMP_TOOLS OFF)
OPTION ( ASSIMP_BUILD_TESTS
  "If the test suite for Assimp is built in addition to the library."
  ON
)
set(ASSIMP_BUILD_TESTS OFF)
OPTION( ASSIMP_INSTALL
  "Disable this if you want to use assimp as a submodule."
  ON
)
set(ASSIMP_INSTALL OFF) 
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/lib/assimp")

include_directories(${OPENGL_INCLUDE_DIRS})
find_package(OpenGL REQUIRED)
include_directories("${CMAKE_SOURCE_DIR}/lib/glfw/include")
include_directories("${CMAKE_SOURCE_DIR}/lib/glew/include")
include_directories("${CMAKE_SOURCE_DIR}/lib/glm")

include_directories("${CMAKE_SOURCE_DIR}/lib")
include_directories("${CMAKE_SOURCE_DIR}/include")

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src")