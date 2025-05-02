#pragma once

#include <memory>

#include "Inputs.h"
#include "Renderer.h"
#include "Timer.h"
#include "Window.h"

class Application {
public:
    Application();
    ~Application();
    void Run();

private:
    std::unique_ptr<Window> window;
    std::unique_ptr<Renderer> renderer;
    std::unique_ptr<Inputs> inputs;
    Timer deltaClock;
};
