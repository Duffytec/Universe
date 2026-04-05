cmake_minimum_required(VERSION 3.16)

project(vendored_glew LANGUAGES C)

add_library(glew_s STATIC src/glew.c)
add_library(GLEW::GLEW ALIAS glew_s)

target_include_directories(glew_s PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_definitions(glew_s
  PUBLIC GLEW_STATIC
  PRIVATE GLEW_NO_GLU
)

if (WIN32)
  target_link_libraries(glew_s PUBLIC opengl32)
elseif (APPLE)
  find_library(OpenGL_FRAMEWORK OpenGL REQUIRED)
  target_link_libraries(glew_s PUBLIC ${OpenGL_FRAMEWORK})
else()
  find_package(OpenGL REQUIRED)
  if (OPENGL_opengl_LIBRARY)
    target_link_libraries(glew_s PUBLIC ${OPENGL_opengl_LIBRARY})
  else()
    target_link_libraries(glew_s PUBLIC ${OPENGL_gl_LIBRARY})
  endif()

  if (OPENGL_glx_LIBRARY)
    target_link_libraries(glew_s PUBLIC ${OPENGL_glx_LIBRARY})
  endif()

  find_package(X11 REQUIRED)
  target_include_directories(glew_s PUBLIC ${X11_INCLUDE_DIR})
  target_link_libraries(glew_s PUBLIC ${X11_LIBRARIES})
endif()
