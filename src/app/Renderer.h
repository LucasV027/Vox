#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

class Renderer {
public:
    explicit Renderer(GLFWwindow* window) ;
    ~Renderer();
    void Init();
    void Render();

private:
    void ImGuiRender();
    void OpenGLRender();

private:
    GLFWwindow* window;
    float bg[3] = {0.2f, 0.2f, 0.2f};
};
