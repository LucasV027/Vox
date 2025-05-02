#include "Application.h"

#include "Timer.h"

Application::Application() : deltaClock() {
    window = std::make_unique<Window>(1280, 720, "Vox");
    inputs = std::make_unique<Inputs>(*window);
    renderer = std::make_unique<Renderer>(*window);
    scene = std::make_unique<Scene>(*window);
}

Application::~Application() = default;

void Application::Run() {
    deltaClock.Start();

    while (!window->ShouldClose()) {
        deltaClock.Update();
        inputs->Poll();

        renderer->OnInput(*inputs, deltaClock.DeltaTime());
        scene->OnInput(*inputs, deltaClock.DeltaTime());

        renderer->BeginFrame();
        scene->OnRender(*renderer);
        renderer->RenderUI();

        window->SwapBuffers();
    }
}
