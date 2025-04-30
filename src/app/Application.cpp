#include "Application.h"

Application::Application() {
    window = std::make_unique<Window>(1280, 720, "Vox");
    renderer = std::make_unique<Renderer>(window->Get());
    renderer->Init();
}

Application::~Application() = default;

void Application::Run() {
    double currentFrame = glfwGetTime();
    double lastFrame = currentFrame;
    double deltaTime;

    while (!window->ShouldClose()) {
        currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        Update(deltaTime);
        renderer->Render();

        window->SwapBuffers();
        glfwPollEvents();
    }
}

void Application::Update(double deltaTime) {}
