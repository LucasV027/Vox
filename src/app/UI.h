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

private:
    float bg[3] = {0.2f, 0.2f, 0.2f};
};
