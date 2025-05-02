#pragma once

#include "Application/Inputs.h"
#include "Application/Renderer.h"
#include "Render/Camera.h"
#include "Render/SkyBox.h"
#include "Voxel.h"

class Scene {
public:
    explicit Scene(WindowRef& windowRef);

    void OnInput(const Inputs& inputs, double deltaTime);
    void OnRender(const Renderer& renderer) const;

private:
    Camera camera;
    SkyBox skybox;
    Voxel voxel;
};
