#pragma once

#include <vector>

#include "graphics/Camera.h"
#include "graphics/Renderable.h"
#include "graphics/SkyBox.h"

class World {
public:
    World();
    ~World();

    void Render(const Program& program, const Camera& camera) const;

private:
    SkyBox skybox;
    std::vector<Renderable*> renderables;
};
