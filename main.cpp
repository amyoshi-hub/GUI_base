#include <GLFW/glfw3.h>
#include <iostream>

int main() {
    // GLFW の初期化
    if (!glfwInit()) {
        std::cerr << "GLFW 初期化失敗" << std::endl;
        return -1;
    }

    // ウィンドウを作成
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Project", NULL, NULL);
    if (!window) {
        std::cerr << "ウィンドウ作成失敗" << std::endl;
        glfwTerminate();
        return -1;
    }

    // ウィンドウのコンテキストを現在のものに設定
    glfwMakeContextCurrent(window);

    // メインループ
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // ここで描画処理を追加

        // バッファのスワップ
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // GLFW 終了
    glfwTerminate();
    return 0;
}

