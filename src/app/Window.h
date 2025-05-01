#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <string>

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
    void GetMousePosition(double& x, double& y) const;
    void ChangeTitle(const std::string& newTitle) const;
    void GetSize(int& width, int& height) const;

private:
    GLFWwindow* windowPtr;
};

using WindowRef = Window&;
