#include "Renderer.h"

#include <iostream>

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"

#include "DebugCallBack.h"
#include "RenderCommand.h"
#include "voxel/World.h"

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

    const auto windowSize = window.GetSize();
    SetViewPort(0, 0, windowSize.x, windowSize.y);

    mainProgram.Create(vsPath, fsPath);
    mainProgram.LocateVariable("view");
    mainProgram.LocateVariable("proj");
    mainProgram.LocateVariable("model");
}

void Renderer::SetViewPort(const int x, const int y, const int width, const int height) const {
    glad_glViewport(x, y, width, height);
}

void Renderer::Render(const Camera& camera, const World& world) const {
    RenderCommand::Clear(0.f, 0.f, 0.f, 1.0f);

    mainProgram.Bind();
    mainProgram.SetUniformMat4f("proj", camera.GetProjection());
    mainProgram.SetUniformMat4f("view", camera.GetView());

    world.Render(mainProgram, camera);
}
