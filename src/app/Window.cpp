#include "Window.h"

#include <iostream>

Window::Window(const int width, const int height, const std::string& title) {
    // GLFW initialization
    if (!glfwInit()) {
        exit(1);
    }

    glfwSetErrorCallback([](int error, const char* description) {
        std::cerr << "GLFW Error (" << error << "): " << description << std::endl;
    });

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

    windowPtr = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!windowPtr) {
        glfwTerminate();
        exit(1);
    }

    glfwMakeContextCurrent(windowPtr);
    glfwSwapInterval(1); // V-Sync

    // GLAD initialization
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        exit(1);
    }
}

Window::~Window() {
    glfwDestroyWindow(windowPtr);
    glfwTerminate();
}

void Window::SwapBuffers() const { glfwSwapBuffers(windowPtr); }

bool Window::ShouldClose() const { return glfwWindowShouldClose(windowPtr); }

GLFWwindow* Window::Get() const { return windowPtr; }
