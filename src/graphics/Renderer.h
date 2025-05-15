#pragma once

#include "Camera.h"
#include "Program.h"
#include "core/Window.h"

class World;

class Renderer {
public:
    explicit Renderer(WindowRef window);
    ~Renderer() = default;

    void SetViewPort(int x, int y, int width, int height) const;

    void Render(const Camera& camera, const World& world) const;


private:
    WindowRef windowRef;
    Program mainProgram;

    const std::filesystem::path vsPath = ASSETS_DIR "/shaders/main.vert";
    const std::filesystem::path fsPath = ASSETS_DIR "/shaders/main.frag";
};
