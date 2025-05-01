#pragma once

#include "Render/Camera.h"
#include "Core/Voxel.h"
#include "Render/SkyBox.h"
#include "UI.h"
#include "Window.h"


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
