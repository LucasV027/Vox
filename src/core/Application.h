#pragma once

#include <memory>

#include "Inputs.h"
#include "Renderer.h"
#include "Timer.h"
#include "Window.h"
#include "graphics/CameraController.h"
#include "graphics/SkyBox.h"

class Application {
public:
    Application();
    ~Application();
    void Run();

private:
    std::unique_ptr<Window> window;
    std::unique_ptr<Renderer> renderer;
    std::unique_ptr<Inputs> inputs;

    std::unique_ptr<Camera> camera;
    std::unique_ptr<CameraController> cameraController;
    SkyBox skybox;

    Timer deltaClock;
};
