#pragma once

#include <string>

#include "glm/vec2.hpp"

class GLFWwindow;

class Window {
public:
    Window(int width, int height, const std::string& title);
    ~Window();

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    void SwapBuffers() const;
    bool ShouldClose() const;
    GLFWwindow* Get() const;

    void SetCursorVisibility(bool visible) const;
    void SetMousePosition(double xPos, double yPos) const;
    void ChangeTitle(const std::string& newTitle) const;
    glm::dvec2 GetMousePosition() const;
    glm::ivec2 GetSize() const;
    float GetAspectRatio() const;

private:
    GLFWwindow* windowPtr;
};

using WindowRef = Window&;
