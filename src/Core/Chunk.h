#pragma once

#include <array>

#include "glm/vec3.hpp"

#include "Application/Renderer.h"
#include "Block.h"
#include "Render/Camera.h"

class Chunk {
public:
    Chunk();
    ~Chunk() = default;

    void Update(double deltaTime) const;
    void Render(const Renderer& renderer, const Camera& camera) const;

    static constexpr int CHUNK_SIZE = 16;
    static constexpr int CHUNK_TOTAL_SIZE = CHUNK_SIZE * CHUNK_SIZE * CHUNK_SIZE;


    static void AddCube(const glm::vec3& position, std::vector<glm::vec3>& vertices,
                        std::vector<unsigned int>& indices);

    static glm::ivec3 IndexTo3D(int i);

private:
    glm::vec3 position;
    std::array<Block, CHUNK_TOTAL_SIZE> blocks;

    Program program;
    VertexArray vao;
    VertexBuffer vbo;
    IndexBuffer ibo;

    const std::filesystem::path fsPath = RES_DIR "/shaders/cube.frag";
    const std::filesystem::path vsPath = RES_DIR "/shaders/cube.vert";

    static constexpr float CUBE[] = {
        0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f, -0.5f, -0.5f,
        0.5f, 0.5f,  -0.5f, 0.5f, 0.5f,  0.5f, -0.5f, 0.5f,  0.5f, -0.5f, 0.5f,  -0.5f,
    };

    static constexpr unsigned int CUBE_INDICES[] = {1, 2, 3, 4, 7, 6, 4, 5, 1, 1, 5, 6,
                                                    6, 7, 3, 4, 0, 3, 0, 1, 3, 5, 4, 6,
                                                    0, 4, 1, 2, 1, 6, 2, 6, 3, 7, 4, 3};
};
