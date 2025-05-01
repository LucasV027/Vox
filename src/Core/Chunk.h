#pragma once

#include <array>

#include "glm/vec3.hpp"

#include "Block.h"

class Chunk {
public:
    Chunk();
    ~Chunk() = default;

    void Update(double deltaTime);

    static constexpr int CHUNK_SIZE = 16;
    static constexpr int CHUNK_TOTAL_SIZE = CHUNK_SIZE * CHUNK_SIZE * CHUNK_SIZE;

private:
    glm::vec3 position;
    std::array<Block, CHUNK_TOTAL_SIZE> blocks;
};
