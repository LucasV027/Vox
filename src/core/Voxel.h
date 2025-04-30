#pragma once

#include "Camera.h"
#include "Chunk.h"

#include "app/Input.h"
#include "app/Renderer.h"

class Voxel {
public:
    Voxel();

    void OnUpdate(const Input& inputs, double deltaTime);
    void OnRender(const Renderer& renderer);

private:
    Camera camera;
    Chunk chunk;
    Program program;

    const std::filesystem::path fsPath = RES_DIR "/shaders/cube.frag";
    const std::filesystem::path vsPath = RES_DIR "/shaders/cube.vert";
};
