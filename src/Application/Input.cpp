#include "Input.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"

#include "imgui.h"

Input::Input(GLFWwindow* window) {
    glfwSetWindowUserPointer(window, this);

    glfwSetWindowSizeCallback(window, [](GLFWwindow* window, const int width, const int height) {
        if (auto* _this = static_cast<Input*>(glfwGetWindowUserPointer(window))) {
            glViewport(0, 0, width, height);
            _this->width = width;
            _this->height = height;
            _this->resizeEvent = true;
        }
    });

    glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
        if (auto* _this = static_cast<Input*>(glfwGetWindowUserPointer(window))) {
            if (action == GLFW_PRESS) {
                _this->keyStates[key] = true;
            } else if (action == GLFW_RELEASE) {
                _this->keyStates[key] = false;
            }
        }
    });

    glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods) {
        if (auto* _this = static_cast<Input*>(glfwGetWindowUserPointer(window))) {
            if (action == GLFW_PRESS) {
                _this->mouseStates[button] = true;
            } else if (action == GLFW_RELEASE) {
                _this->mouseStates[button] = false;
            }
        }
    });

    glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xpos, double ypos) {
        if (auto* _this = static_cast<Input*>(glfwGetWindowUserPointer(window))) {
            _this->xPos = xpos;
            _this->yPos = ypos;
        }
    });
}

void Input::Poll() {
    resizeEvent = false;
    glfwPollEvents();
}


bool Input::IsKeyPressed(const int key) const {
    if (!keyStates.contains(key))
        return false;
    return keyStates.at(key);
}
bool Input::IsMouseButtonPressed(const int button) const {
    if (!mouseStates.contains(button))
        return false;
    return mouseStates.at(button);
}

bool Input::IsMouseFree() const { return !ImGui::GetIO().WantCaptureMouse; }

bool Input::IsWindowResized(int& newWidth, int& newHeight) const {
    if (resizeEvent) {
        newWidth = width;
        newHeight = height;
        return true;
    }
    return false;
}


void Input::GetMousePosition(double& x, double& y) const {
    x = xPos;
    y = yPos;
}
