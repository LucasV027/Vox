#include "Scene.h"

Scene::Scene(WindowRef& windowRef) {
    int width, height;
    windowRef.GetSize(width, height);
    camera.Init(width, height);
    skybox.Init({RES_DIR "/textures/skybox/right.jpg", RES_DIR "/textures/skybox/left.jpg",
                 RES_DIR "/textures/skybox/top.jpg", RES_DIR "/textures/skybox/bottom.jpg",
                 RES_DIR "/textures/skybox/front.jpg", RES_DIR "/textures/skybox/back.jpg"});
}

void Scene::OnInput(const Inputs& inputs, const double deltaTime) {
    camera.OnInput(inputs, deltaTime);
}

void Scene::OnRender(const Renderer& renderer) const { skybox.Render(renderer, camera); }
