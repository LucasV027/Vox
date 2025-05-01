#pragma once

#include <filesystem>
#include <vector>

#include "opengl/Program.h"
#include "opengl/Texture.h"
#include "opengl/VertexArray.h"
#include "opengl/VertexBuffer.h"

class SkyBox {
public:
    SkyBox() = default;
    void Init();

    VertexArray vao;
    Program program;
private:
    Texture texture;
    VertexBuffer vbo;

    const std::filesystem::path skyboxFsPath = RES_DIR "/shaders/skybox.frag";
    const std::filesystem::path skyboxVsPath = RES_DIR "/shaders/skybox.vert";

    const std::vector<std::filesystem::path> SKYBOX_PATHS{
        RES_DIR "/textures/skybox/right.jpg", RES_DIR "/textures/skybox/left.jpg",
        RES_DIR "/textures/skybox/top.jpg",   RES_DIR "/textures/skybox/bottom.jpg",
        RES_DIR "/textures/skybox/front.jpg", RES_DIR "/textures/skybox/back.jpg"};

    static constexpr float CUBE[] = {
        -1.0f, 1.0f,  -1.0f, -1.0f, -1.0f, -1.0f, 1.0f,  -1.0f, -1.0f, 1.0f,  -1.0f, -1.0f,
        1.0f,  1.0f,  -1.0f, -1.0f, 1.0f,  -1.0f, -1.0f, -1.0f, 1.0f,  -1.0f, -1.0f, -1.0f,
        -1.0f, 1.0f,  -1.0f, -1.0f, 1.0f,  -1.0f, -1.0f, 1.0f,  1.0f,  -1.0f, -1.0f, 1.0f,
        1.0f,  -1.0f, -1.0f, 1.0f,  -1.0f, 1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  -1.0f, 1.0f,  -1.0f, -1.0f, -1.0f, -1.0f, 1.0f,  -1.0f, 1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  -1.0f, 1.0f,  -1.0f, -1.0f, 1.0f,
        -1.0f, 1.0f,  -1.0f, 1.0f,  1.0f,  -1.0f, 1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f,
        -1.0f, 1.0f,  1.0f,  -1.0f, 1.0f,  -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, 1.0f,
        1.0f,  -1.0f, -1.0f, 1.0f,  -1.0f, -1.0f, -1.0f, -1.0f, 1.0f,  1.0f,  -1.0f, 1.0f};
};
