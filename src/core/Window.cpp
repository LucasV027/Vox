#include "Window.h"

#include <iostream>

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"

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

void Window::SetCursorVisibility(const bool visible) const {
    const int mode = visible ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_DISABLED;
    glfwSetInputMode(windowPtr, GLFW_CURSOR, mode);
}

void Window::SetMousePosition(const double xPos, const double yPos) const {
    glfwSetCursorPos(windowPtr, xPos, yPos);
}

void Window::ChangeTitle(const std::string& newTitle) const {
    glfwSetWindowTitle(windowPtr, newTitle.c_str());
}

glm::dvec2 Window::GetMousePosition() const {
    glm::dvec2 mousePos;
    glfwGetCursorPos(windowPtr, &mousePos.x, &mousePos.y);
    return mousePos;
}

glm::ivec2 Window::GetSize() const {
    glm::ivec2 size;
    glfwGetWindowSize(windowPtr, &size.x, &size.y);
    return size;
}

float Window::GetAspectRatio() const {
    const auto size = GetSize();
    return static_cast<float>(size.x) / static_cast<float>(size.y);
}
