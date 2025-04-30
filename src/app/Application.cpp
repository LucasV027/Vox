#include "Application.h"

#include "Time.h"

Application::Application() {
    window = std::make_unique<Window>(1280, 720, "Vox");
    renderer = std::make_unique<Renderer>(window->Get());
    renderer->Init();
}

Application::~Application() = default;

void Application::Run() {
    while (!window->ShouldClose()) {
        Time::Update();
    
        Update(Time::DeltaTime());
        renderer->Render();

        window->SwapBuffers();
        glfwPollEvents();
    }
}

void Application::Update(double deltaTime) {}
