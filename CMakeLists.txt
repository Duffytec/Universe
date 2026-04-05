cmake_minimum_required(VERSION 3.16)
if(POLICY CMP0072)
  cmake_policy(SET CMP0072 NEW)
endif()
project(universe LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(OpenGL REQUIRED)

if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/third_party/glfw/CMakeLists.txt")
  set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
  set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
  set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
  set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
  if (UNIX AND NOT APPLE)
    set(GLFW_BUILD_WAYLAND OFF CACHE BOOL "" FORCE)
  endif()
  add_subdirectory(third_party/glfw)
  set(GLFW_TARGET glfw)
else()
  find_package(glfw3 CONFIG REQUIRED)
  set(GLFW_TARGET glfw)
endif()

if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/third_party/glew/CMakeLists.txt")
  add_subdirectory(third_party/glew)
  set(GLEW_TARGET glew_s)
else()
  find_package(GLEW REQUIRED)
  set(GLEW_TARGET GLEW::GLEW)
endif()

include_directories(${OPENGL_INCLUDE_DIR})


file(GLOB_RECURSE Application ${CMAKE_CURRENT_SOURCE_DIR}/Application/*.cpp)
file(GLOB_RECURSE Geometry ${CMAKE_CURRENT_SOURCE_DIR}/Geometry/*.cpp)
file(GLOB_RECURSE Math ${CMAKE_CURRENT_SOURCE_DIR}/Math/*.cpp)
file(GLOB_RECURSE Shader ${CMAKE_CURRENT_SOURCE_DIR}/Shaders/ShaderManager.cpp)



add_executable(universe ProcedurusMain.cpp ${Application} ${Geometry} ${Math} ${Shader})

target_link_libraries(universe PUBLIC ${GLFW_TARGET} ${GLEW_TARGET} ${OPENGL_LIBRARIES})
