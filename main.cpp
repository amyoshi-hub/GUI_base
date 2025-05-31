// main.cpp

#include <GLFW/glfw3.h>
#include <iostream>

extern "C" int run_glfw_app() {
    if (!glfwInit()) {
        std::cerr << "GLFW 初期化失敗" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Project", NULL, NULL);
    if (!window) {
        std::cerr << "ウィンドウ作成失敗" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // 描画処理

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

// mainは空か、もしくは使わない
int main() {
    return run_glfw_app();
}

