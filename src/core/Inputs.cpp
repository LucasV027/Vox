#include "Inputs.h"

#include "GLFW/glfw3.h"

#include "imgui.h"

Inputs::Inputs(WindowRef windowRef) : windowRef(windowRef) {
    glfwSetWindowUserPointer(windowRef.Get(), this);

    glfwSetWindowSizeCallback(
        windowRef.Get(), [](GLFWwindow* window, const int width, const int height) {
            if (auto* _this = static_cast<Inputs*>(glfwGetWindowUserPointer(window))) {
                _this->width = width;
                _this->height = height;
                _this->resizeEvent = true;
            }
        });

    glfwSetKeyCallback(
        windowRef.Get(), [](GLFWwindow* window, int key, int scancode, int action, int mods) {
            if (auto* _this = static_cast<Inputs*>(glfwGetWindowUserPointer(window))) {
                if (action == GLFW_PRESS) {
                    _this->keyStates[key] = true;
                } else if (action == GLFW_RELEASE) {
                    _this->keyStates[key] = false;
                }
            }
        });

    glfwSetMouseButtonCallback(
        windowRef.Get(), [](GLFWwindow* window, int button, int action, int mods) {
            if (auto* _this = static_cast<Inputs*>(glfwGetWindowUserPointer(window))) {
                if (action == GLFW_PRESS) {
                    _this->mouseStates[button] = true;
                } else if (action == GLFW_RELEASE) {
                    _this->mouseStates[button] = false;
                }
            }
        });
}

void Inputs::Poll() {
    resizeEvent = false;
    glfwPollEvents();
}


bool Inputs::IsKeyPressed(const int key) const {
    if (!keyStates.contains(key))
        return false;
    return keyStates.at(key);
}
bool Inputs::IsMouseButtonPressed(const int button) const {
    if (!mouseStates.contains(button))
        return false;
    return mouseStates.at(button);
}

bool Inputs::IsMouseFree() const { return !ImGui::GetIO().WantCaptureMouse; }

bool Inputs::IsWindowResized(int& newWidth, int& newHeight) const {
    if (resizeEvent) {
        newWidth = width;
        newHeight = height;
        return true;
    }
    return false;
}


void Inputs::GetMousePosition(double& x, double& y) const { windowRef.GetMousePosition(x, y); }

void Inputs::SetCursorVisibility(const bool visible) const {
    windowRef.SetCursorVisibility(visible);
}

void Inputs::SetMousePosition(const double xPos, const double yPos) const {
    windowRef.SetMousePosition(xPos, yPos);
}
