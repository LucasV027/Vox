#pragma once

#include "Window.h"

class UI {
public:
    explicit UI(WindowRef window);
    ~UI();

    void BeginFrame();
    void EndFrame();
};
