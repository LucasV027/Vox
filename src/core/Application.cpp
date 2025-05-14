#include "Application.h"

#include "Timer.h"

Application::Application() : deltaClock() {
    window = std::make_unique<Window>(1280, 720, "Vox");
    inputs = std::make_unique<Inputs>(*window);
    renderer = std::make_unique<Renderer>(*window);

    int w, h;
    window->GetSize(w, h);

    camera = std::make_unique<Camera>();

    camera->SetPerspective(90, float(w) / float(h), 0.01f, 100.0f);

    cameraController = std::make_unique<CameraController>(*camera, *inputs, w, h);
    skybox.Init({ASSETS_DIR "/textures/skybox/right.jpg", ASSETS_DIR "/textures/skybox/left.jpg",
                 ASSETS_DIR "/textures/skybox/top.jpg", ASSETS_DIR "/textures/skybox/bottom.jpg",
                 ASSETS_DIR "/textures/skybox/front.jpg", ASSETS_DIR "/textures/skybox/back.jpg"});
}

Application::~Application() = default;

void Application::Run() {
    deltaClock.Start();

    while (!window->ShouldClose()) {
        deltaClock.Update();
        inputs->Poll();

        renderer->OnInput(*inputs, deltaClock.DeltaTime());
        cameraController->Update(deltaClock.DeltaTime());

        renderer->BeginFrame();
        skybox.Render(*renderer, *camera);
        renderer->RenderUI();

        window->SwapBuffers();
    }
}
