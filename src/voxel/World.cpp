#include "World.h"

#include "Cube.h"

World::World() {
    skybox.Init({ASSETS_DIR "/textures/skybox/right.jpg", ASSETS_DIR "/textures/skybox/left.jpg",
                 ASSETS_DIR "/textures/skybox/top.jpg", ASSETS_DIR "/textures/skybox/bottom.jpg",
                 ASSETS_DIR "/textures/skybox/front.jpg", ASSETS_DIR "/textures/skybox/back.jpg"});

    renderables.emplace_back(new Cube());
}

World::~World() {
    for (const auto renderable : renderables) {
        delete renderable;
    }
}

void World::Render(const Program& program, const Camera& camera) const {
    skybox.Render(camera);

    for (const auto renderable : renderables) {
        renderable->Render(program);
    }
}
