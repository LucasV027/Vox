#pragma once

#include "Camera.h"
#include "UI.h"
#include "Window.h"
#include "core/Voxel.h"
#include "opengl/Program.h"


class Renderer {
public:
    explicit Renderer(WindowRef window);
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
    std::unique_ptr<UI> ui;
    WindowRef window;

    Camera camera;
};
