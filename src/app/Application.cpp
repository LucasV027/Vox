#include "Application.h"

#include "Time.h"

Application::Application() {
    window = std::make_unique<Window>(1280, 720, "Vox");
    inputs = std::make_unique<Input>(window->Get());

    renderer = std::make_unique<Renderer>(window->Get());

    vox = std::make_unique<Voxel>();
}

Application::~Application() = default;

void Application::Run() {
    Time::Update();

    while (!window->ShouldClose()) {
        Time::Update();
        inputs->Poll();

        vox->OnUpdate(*inputs, Time::DeltaTime());

        renderer->BeginFrame();
        vox->OnRender(*renderer);
        renderer->RenderUI();

        window->SwapBuffers();
    }
}
