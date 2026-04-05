cmake_minimum_required(VERSION 3.10)
if(POLICY CMP0072)
  cmake_policy(SET CMP0072 NEW)
endif()
project(universe LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR})


file(GLOB_RECURSE Application ${CMAKE_CURRENT_SOURCE_DIR}/Application/*.cpp)
file(GLOB_RECURSE Geometry ${CMAKE_CURRENT_SOURCE_DIR}/Geometry/*.cpp)
file(GLOB_RECURSE Math ${CMAKE_CURRENT_SOURCE_DIR}/Math/*.cpp)
file(GLOB_RECURSE Shader ${CMAKE_CURRENT_SOURCE_DIR}/Shaders/ShaderManager.cpp)



add_executable(universe ProcedurusMain.cpp ${Application} ${Geometry} ${Math} ${Shader})

target_link_libraries(universe PUBLIC glfw GLEW::GLEW ${OPENGL_LIBRARIES})
