#pragma once

#include <memory>

#include "Renderer.h"
#include "Window.h"

class Application {
public:
    Application();
    ~Application();
    void Run();

private:
    void Update(double deltaTime);

private:
    std::unique_ptr<Window> window;
    std::unique_ptr<Renderer> renderer;
};
