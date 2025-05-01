#pragma once

#include "Window.h"

class UI {
    friend class Renderer;
public:
    explicit UI(WindowRef window);
    ~UI();

    void Render();

private:
    void BeginFrame();
    void EndFrame();
};
