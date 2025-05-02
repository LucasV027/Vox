#pragma once

#include <memory>

#include "Core/Voxel.h"
#include "Input.h"
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
    std::unique_ptr<Input> inputs;
    std::unique_ptr<Voxel> vox;
    Timer deltaClock;
};
