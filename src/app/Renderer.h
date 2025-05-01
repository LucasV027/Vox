#pragma once

#include "Camera.h"
#include "UI.h"
#include "core/Voxel.h"
#include "opengl/Program.h"

class GLFWwindow;

class Renderer {
public:
    explicit Renderer(GLFWwindow* window);
    ~Renderer() = default;

    void BeginFrame();
    void RenderUI() const;

    void RenderVoxel(const Voxel& voxel);
    Camera& GetCamera();

private:
    static void OpenGLErrorCallback(unsigned int source, unsigned int type, unsigned int id,
                                    unsigned int severity, int length, const char* message,
                                    const void* userParam);

private:
    GLFWwindow* window;
    std::unique_ptr<UI> ui;
    Camera camera;
};
