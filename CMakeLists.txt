cmake_minimum_required(VERSION 3.10)
project(OpenGL_Project VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(OpenGL REQUIRED)
cmake_policy(SET CMP0072 NEW)

# gladは既にadd_libraryでビルドしている想定
add_library(glad STATIC ${CMAKE_SOURCE_DIR}/glad/src/glad.c)

# glfwのソースをサブディレクトリとして追加
add_subdirectory(${CMAKE_SOURCE_DIR}/glfw-3.4)

# 自作ライブラリ
add_library(mylib STATIC c_lib/GUI.cpp)

target_link_libraries(mylib PRIVATE glad glfw OpenGL::GL)

target_include_directories(mylib PRIVATE
    ${CMAKE_SOURCE_DIR}/glfw-3.4/include
    ${CMAKE_SOURCE_DIR}/glad/include
)
