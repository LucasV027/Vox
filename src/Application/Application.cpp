#include "Application.h"

#include "Timer.h"

Application::Application() : deltaClock() {
    window = std::make_unique<Window>(1280, 720, "Vox");
    inputs = std::make_unique<Input>(window->Get());
    renderer = std::make_unique<Renderer>(*window);

    vox = std::make_unique<Voxel>();
}

Application::~Application() = default;

void Application::Run() {
    deltaClock.Start();

    while (!window->ShouldClose()) {
        deltaClock.Update();
        inputs->Poll();

        vox->OnUpdate(*inputs, deltaClock.DeltaTime());
        renderer->GetCamera().ProcessInputs(*inputs, *window, deltaClock.DeltaTime());

        renderer->BeginFrame();
        renderer->RenderVoxel(*vox);
        renderer->RenderUI();

        window->SwapBuffers();
    }
}
