#include "Application.h"

#include "Time.h"

Application::Application() {
    window = std::make_unique<Window>(1280, 720, "Vox");
    inputs = std::make_unique<Input>(window->Get());
    renderer = std::make_unique<Renderer>(*window);

    vox = std::make_unique<Voxel>();
}

Application::~Application() = default;

void Application::Run() {
    Time::Update();

    while (!window->ShouldClose()) {
        Time::Update();
        inputs->Poll();

        vox->OnUpdate(*inputs, Time::DeltaTime());
        renderer->GetCamera().ProcessInputs(*inputs, *window, Time::DeltaTime());

        renderer->BeginFrame();
        renderer->RenderVoxel(*vox);
        renderer->RenderUI();

        window->SwapBuffers();
    }
}
