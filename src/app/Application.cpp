#include "Application.h"

#include "Time.h"

Application::Application() {
    window = std::make_unique<Window>(1280, 720, "Vox");
    input = std::make_unique<Input>(window->Get());
    renderer = std::make_unique<Renderer>(window->Get());
    renderer->Init();
}

Application::~Application() = default;

void Application::Run() {
    while (!window->ShouldClose()) {
        Time::Update();
        input->Poll();
        renderer->Render();
        window->SwapBuffers();
    }
}
