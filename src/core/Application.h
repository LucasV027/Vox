#pragma once

#include <memory>

#include "Inputs.h"
#include "Renderer.h"
#include "Timer.h"
#include "UI.h"
#include "Window.h"
#include "controller/Controllers.h"
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
    std::unique_ptr<UI> ui;
    std::unique_ptr<Controllers> controllers;

    std::unique_ptr<Camera> camera;
    SkyBox skybox;

    Timer deltaClock;
};
