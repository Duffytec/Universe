cmake_minimum_required(VERSION 3.10)
project(universe LANGUAGES C CXX)


set(GLFW3_INSTALL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/glfw/build/install")
if (EXISTS "${GLFW3_INSTALL_DIR}/lib/cmake/glfw3/glfw3Config.cmake")
  set(CMAKE_PREFIX_PATH "${GLFW3_INSTALL_DIR};${CMAKE_PREFIX_PATH}")
  find_package(glfw3 CONFIG REQUIRED)
elseif (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/glfw/CMakeLists.txt")
  set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
  set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
  set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
  set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
  add_subdirectory(glfw)
else()
  find_package(glfw3 CONFIG REQUIRED)
endif()
find_package(OpenGL REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR})


file(GLOB_RECURSE Application ${CMAKE_CURRENT_SOURCE_DIR}/Application/*.cpp)
file(GLOB_RECURSE Geometry ${CMAKE_CURRENT_SOURCE_DIR}/Geometry/*.cpp)
file(GLOB_RECURSE GL ${CMAKE_CURRENT_SOURCE_DIR}/GL/*.c)
file(GLOB_RECURSE Math ${CMAKE_CURRENT_SOURCE_DIR}/Math/*.cpp)
file(GLOB_RECURSE Shader ${CMAKE_CURRENT_SOURCE_DIR}/Shaders/ShaderManager.cpp)



add_executable(universe ProcedurusMain.cpp ${Application} ${Geometry} ${GL} ${Math} ${Shader})

target_link_libraries(universe PUBLIC glfw ${OPENGL_LIBRARIES})