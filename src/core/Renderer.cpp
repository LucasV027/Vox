#include "Renderer.h"

#include <iostream>

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"

#include "graphics/DebugCallBack.h"

Renderer::Renderer(WindowRef window) : windowRef(window) {
    // OpenGL Debug
    GLint flags;
    glGetIntegerv(GL_CONTEXT_FLAGS, &flags);
    if (flags & GL_CONTEXT_FLAG_DEBUG_BIT) {
        glEnable(GL_DEBUG_OUTPUT);
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback(OpenGLErrorCallback, nullptr);
        glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
    }

    ui = std::make_unique<UI>(window);
}

void Renderer::BeginFrame() const { Clear(0.f, 0.f, 0.f, 1.0f); }

void Renderer::RenderUI() const { ui->Render(); }

void Renderer::OnInput(const Inputs& inputs, const double deltaTime) const {
    int width, height;
    if (inputs.IsWindowResized(width, height)) {
        SetViewPort(0, 0, width, height);
    }
}

void Renderer::Clear(const float r, const float g, const float b, const float a) const {
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::SetDepthTest(const bool val) const { glDepthMask(val ? GL_TRUE : GL_FALSE); }

void Renderer::SetViewPort(const int x, const int y, const int width, const int height) const {
    glad_glViewport(x, y, width, height);
}

void Renderer::Draw(const VertexArray& vao, const IndexBuffer& ibo, const Program& program) const {
    vao.Bind();
    ibo.Bind();
    program.Bind();
    glDrawElements(GL_TRIANGLES, ibo.GetCount(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::Draw(const VertexArray& vao, int first, int count, const Program& program) const {
    vao.Bind();
    program.Bind();
    glDrawArrays(GL_TRIANGLES, first, count);
}
