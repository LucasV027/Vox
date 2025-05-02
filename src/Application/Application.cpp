#include "Application.h"

#include "Timer.h"

Application::Application() : deltaClock() {
    window = std::make_unique<Window>(1280, 720, "Vox");
    inputs = std::make_unique<Inputs>(*window);
    renderer = std::make_unique<Renderer>(*window);
}

Application::~Application() = default;

void Application::Run() {
    deltaClock.Start();

    while (!window->ShouldClose()) {
        deltaClock.Update();
        inputs->Poll();

        renderer->OnInput(*inputs, deltaClock.DeltaTime());

        renderer->BeginFrame();
        renderer->Render();
        renderer->RenderUI();

        window->SwapBuffers();
    }
}
