#pragma once

#include <memory>

#include "Inputs.h"
#include "Renderer.h"
#include "Timer.h"
#include "Window.h"
#include "voxel/Scene.h"

class Application {
public:
    Application();
    ~Application();
    void Run();

private:
    std::unique_ptr<Window> window;
    std::unique_ptr<Renderer> renderer;
    std::unique_ptr<Inputs> inputs;
    std::unique_ptr<Scene> scene;
    Timer deltaClock;
};
