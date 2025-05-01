#pragma once

#include "UI.h"
#include "opengl/IndexBuffer.h"
#include "opengl/Program.h"
#include "opengl/VertexArray.h"

class GLFWwindow;

class Renderer {
public:
    explicit Renderer(GLFWwindow* window);
    ~Renderer() = default;

    void BeginFrame();
    void RenderUI() const;

    void Draw(const VertexArray& vao, const IndexBuffer& ibo, const Program& program) const;
    void Clear(float r, float g, float b, float a = 1.0f);

private:
    static void OpenGLErrorCallback(unsigned int source, unsigned int type, unsigned int id,
                                    unsigned int severity, int length, const char* message,
                                    const void* userParam);

private:
    GLFWwindow* window;
    std::unique_ptr<UI> ui;
};
