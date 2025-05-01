#include "Renderer.h"

#include <iostream>

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"

#include "opengl/DebugCallBack.h"

Renderer::Renderer(WindowRef window) : window(window) {
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

    int width, height;
    window.GetSize(width, height);
    camera.Init(width, height);

    skybox.Init();
}

void Renderer::BeginFrame() {
    glClearColor(0.f, 0.f, 0.f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glDepthMask(GL_FALSE);
    skybox.program.Bind();
    skybox.program.SetUniformMat4f(
        "mvp", camera.GetProjectionMatrix() * glm::mat4(glm::mat3(camera.GetViewMatrix())));
    skybox.vao.Bind();
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glDepthMask(GL_TRUE);
}

void Renderer::RenderUI() const { ui->Render(); }

void Renderer::RenderVoxel(const Voxel& voxel) {
    // TODO
}


Camera& Renderer::GetCamera() { return camera; }
