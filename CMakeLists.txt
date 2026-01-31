






include_directories(${CMAKE_CURRENT_SOURCE_DIR}/glfw2/build/install/include)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/glfw2/build/install/lib)



find_package(OpenGL REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR})


file(GLOB_RECURSE Application ${CMAKE_CURRENT_SOURCE_DIR}/Application/*.cpp)
file(GLOB_RECURSE Geometry ${CMAKE_CURRENT_SOURCE_DIR}/Geometry/*.cpp)
file(GLOB_RECURSE GL ${CMAKE_CURRENT_SOURCE_DIR}/GL/*.c)
file(GLOB_RECURSE Math ${CMAKE_CURRENT_SOURCE_DIR}/Math/*.cpp)
file(GLOB_RECURSE Shader ${CMAKE_CURRENT_SOURCE_DIR}/Shaders/ShaderManager.cpp)



add_executable(universe ProcedurusMain.cpp ${Application} ${Geometry} ${GL} ${Math} ${Shader})

target_link_libraries(universe PUBLIC glfw ${OPENGL_LIBRARIES})