#pragma once

#include "Chunk.h"
#include "core/Inputs.h"
#include "core/Renderer.h"
#include "graphics/Camera.h"
#include "graphics/SkyBox.h"

class Scene {
public:
    explicit Scene(WindowRef& windowRef);

    void OnInput(const Inputs& inputs, double deltaTime);
    void OnRender(const Renderer& renderer) const;

private:
    Camera camera;
    SkyBox skybox;
    Chunk chunk;
};
