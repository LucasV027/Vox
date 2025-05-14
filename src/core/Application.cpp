#include "Application.h"

#include "Timer.h"
#include "controller/CameraController.h"
#include "controller/RendererController.h"
#include "imgui.h"

Application::Application() : deltaClock() {
    window = std::make_unique<Window>(1280, 720, "Vox");
    inputs = std::make_unique<Inputs>(*window);
    renderer = std::make_unique<Renderer>(*window);
    ui = std::make_unique<UI>(*window);

    camera = std::make_unique<Camera>();
    camera->SetPerspective(90, window->GetAspectRatio(), 0.01f, 100.0f);

    controllers = std::make_unique<Controllers>();
    controllers->Register<CameraController>(*inputs, *camera);
    controllers->Register<RendererController>(*inputs, *renderer);

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

        controllers->ProcessInputs(deltaClock.DeltaTime());

        renderer->BeginFrame();
        skybox.Render(*renderer, *camera);

        ui->BeginFrame();
        const glm::vec3& pos = camera->GetPosition();
        const glm::vec3& dir = camera->GetOrientation();
        ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);
        ImGui::Text("Camera Pos: (%.2f, %.2f, %.2f)", pos.x, pos.y, pos.z);
        ImGui::Text("Camera Dir: (%.2f, %.2f, %.2f)", dir.x, dir.y, dir.z);
        ui->EndFrame();

        window->SwapBuffers();
    }
}
