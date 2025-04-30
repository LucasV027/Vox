#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <string>

class Window {
public:
    Window(int width, int height, const std::string& title);
    ~Window();

    void SwapBuffers() const;
    bool ShouldClose() const;
    GLFWwindow* Get() const;


private:
    std::string title;
    int width;
    int height;

    GLFWwindow* windowPtr;
};
