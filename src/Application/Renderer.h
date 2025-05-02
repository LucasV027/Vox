#pragma once

#include "Core/Voxel.h"
#include "Render/Camera.h"
#include "Render/SkyBox.h"
#include "UI.h"
#include "Window.h"


class Renderer {
public:
    explicit Renderer(WindowRef window);
    ~Renderer() = default;

    void BeginFrame();
    void RenderUI() const;
    void Render();
    void Clear(float r = 0.2f, float g = 0.2f, float b = 0.2f, float a = 1.0f);
    void SetDepthTest(bool val);
    void SetViewPort(int x, int y, int width, int height);

    void RenderSkybox();
    void RenderVoxel(const Voxel& voxel);
    Camera& GetCamera();

    void OnInput(const Inputs& inputs, double deltaTime);

private:
    std::unique_ptr<UI> ui;
    WindowRef windowRef;

    Camera camera;
    SkyBox skybox;
};
