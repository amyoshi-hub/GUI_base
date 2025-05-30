#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

void render_gui() {
    // ImGui のウィンドウを描画
    ImGui::Text("Hello, ImGui!");
    if (ImGui::Button("Exit")) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    ImGui::Render();
}

int main() {
    // GLFW の初期化
    if (!glfwInit()) {
        return -1;
    }

    // OpenGL コンテキストの設定
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // GLFW でウィンドウ作成
    GLFWwindow* window = glfwCreateWindow(1280, 720, "ImGui with GLFW and OpenGL", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // OpenGL コンテキストをウィンドウに設定
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // V-Sync をオン

    // Glad を初期化して OpenGL の関数をロード
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize OpenGL loader!" << std::endl;
        return -1;
    }

    // ImGui の初期化
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;

    // ImGui スタイルの設定（オプション）
    ImGui::StyleColorsDark();

    // ImGui のバックエンドの設定
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    // メインループ
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        // ImGui フレームの開始
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // GUI を描画
        render_gui();

        // 描画内容を OpenGL に描画
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // バッファをスワップ
        glfwSwapBuffers(window);
    }

    // クリーンアップ
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
