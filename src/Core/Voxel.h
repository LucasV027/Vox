#pragma once

#include "Application/Input.h"
#include "Chunk.h"

class Voxel {
public:
    Voxel();

    void OnUpdate(const Input& inputs, double deltaTime);

private:
    Chunk chunk;
};
