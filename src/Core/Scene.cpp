#include "Scene.h"

Scene::Scene(WindowRef& windowRef) {
    int width, height;
    windowRef.GetSize(width, height);
    camera.Init(width, height);
    skybox.Init({ASSETS_DIR "/textures/skybox/right.jpg", ASSETS_DIR "/textures/skybox/left.jpg",
                 ASSETS_DIR "/textures/skybox/top.jpg", ASSETS_DIR "/textures/skybox/bottom.jpg",
                 ASSETS_DIR "/textures/skybox/front.jpg", ASSETS_DIR "/textures/skybox/back.jpg"});
}

void Scene::OnInput(const Inputs& inputs, const double deltaTime) {
    camera.OnInput(inputs, deltaTime);
}

void Scene::OnRender(const Renderer& renderer) const {
    skybox.Render(renderer, camera);
    chunk.Render(renderer, camera);
}
