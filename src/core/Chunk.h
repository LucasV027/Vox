#pragma once

#include <array>

#include "glm/vec3.hpp"

#include "Block.h"
#include "app/Renderer.h"

class Chunk {
public:
    Chunk();
    ~Chunk() = default;

    void Update(double deltaTime);
    void Render(const Renderer& renderer, const Program& program);

    static void AddCube(const glm::vec3& position, std::vector<glm::vec3>& vertices,
                        std::vector<unsigned int>& indices);

    static glm::ivec3 IndexTo3D(int i);

    static constexpr int CHUNK_SIZE = 16;
    static constexpr int CHUNK_TOTAL_SIZE = CHUNK_SIZE * CHUNK_SIZE * CHUNK_SIZE;

private:
    glm::vec3 position;
    std::array<Block, CHUNK_TOTAL_SIZE> blocks;
};
