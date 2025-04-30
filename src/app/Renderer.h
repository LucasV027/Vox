#pragma once

class GLFWwindow;

class Renderer {
public:
    explicit Renderer(GLFWwindow* window);
    ~Renderer();
    void Init();
    void Render();

private:
    void ImGuiRender();
    void OpenGLRender();

    static void OpenGLErrorCallback(unsigned int source, unsigned int type, unsigned int id,
                                    unsigned int severity, int length, const char* message,
                                    const void* userParam);

private:
    GLFWwindow* window;
    float bg[3] = {0.2f, 0.2f, 0.2f};
};
