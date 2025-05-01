#pragma once

#include "Camera.h"
#include "SkyBox.h"
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
    std::unique_ptr<UI> ui;
    WindowRef window;

    Camera camera;
    SkyBox skybox;
};
