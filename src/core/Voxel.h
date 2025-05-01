#pragma once

#include "Chunk.h"
#include "app/Input.h"

class Voxel {
public:
    Voxel();

    void OnUpdate(const Input& inputs, double deltaTime);

private:
    Chunk chunk;
};
