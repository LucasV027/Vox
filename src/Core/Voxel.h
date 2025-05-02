#pragma once

#include "Application/Inputs.h"
#include "Chunk.h"

class Voxel {
public:
    Voxel();

    void OnUpdate(const Inputs& inputs, double deltaTime);

private:
    Chunk chunk;
};
