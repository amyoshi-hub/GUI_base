cmake_minimum_required(VERSION 3.10)
project(ImGuiExample)

# C++バージョンの設定
set(CMAKE_CXX_STANDARD 11)

# ImGui関連ファイルの追加
set(IMGUI_DIR imgui)
set(IMGUI_SOURCES
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)

# gladの設定
add_library(glad glad/src/glad.c)
target_include_directories(glad PUBLIC glad/include)

# GLFWの設定
add_subdirectory(glfw-3.4)

# 実行ファイルの設定
add_executable(ImGuiExample main.cpp ${IMGUI_SOURCES})

# インクルードディレクトリ
target_include_directories(ImGuiExample PUBLIC ${IMGUI_DIR} ${IMGUI_DIR}/backends)

# ライブラリのリンク
target_link_libraries(ImGuiExample PRIVATE glfw glad GL dl pthread)

