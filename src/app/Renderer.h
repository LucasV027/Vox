#pragma once

#include "opengl/IndexBuffer.h"
#include "opengl/Program.h"
#include "opengl/VertexArray.h"

class GLFWwindow;

class Renderer {
public:
    explicit Renderer(GLFWwindow* window);
    ~Renderer();
    void Init();

    void BeginFrame();
    void RenderUI();

    void Draw(const VertexArray& vao, const IndexBuffer& ibo, const Program& program) const;
    void Draw(const VertexArray& vao, int first, int count, const Program& program) const;
    void SetPolygonMode(bool state) const;
    void Clear(float r, float g, float b, float a = 1.0f);

private:
    void ImGuiRender();

    static void OpenGLErrorCallback(unsigned int source, unsigned int type, unsigned int id,
                                    unsigned int severity, int length, const char* message,
                                    const void* userParam);

private:
    GLFWwindow* window;
    float bg[3] = {0.2f, 0.2f, 0.2f};
    mutable bool currentPolygonState = true;
};
