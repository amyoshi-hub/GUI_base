cmake_minimum_required(VERSION 3.10)

# プロジェクトの名前とバージョン
project(OpenGL_Project VERSION 1.0)

# C++の標準を指定
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# OpenGL ライブラリをリンク
find_package(OpenGL REQUIRED)

# GLVND を使うように設定 (警告抑制)
cmake_policy(SET CMP0072 NEW)

# Glad のソースコードをコンパイル対象として追加
set(GLAD_SRC ${CMAKE_SOURCE_DIR}/glad/src/glad.c)
add_library(glad STATIC ${GLAD_SRC})

# GLFW のソースコードをサブディレクトリとして追加
add_subdirectory(${CMAKE_SOURCE_DIR}/glfw-3.4)

# メインソースコード
add_executable(OpenGL_Project main.cpp)

# 必要なライブラリをリンク
target_link_libraries(OpenGL_Project PRIVATE glad glfw OpenGL::GL)

# Include Directories
target_include_directories(OpenGL_Project PRIVATE
    ${CMAKE_SOURCE_DIR}/glfw-3.4/include
    ${CMAKE_SOURCE_DIR}/glad/include
)

