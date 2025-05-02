#include "Voxel.h"

Voxel::Voxel() = default;

void Voxel::OnUpdate(const Inputs& inputs, const double deltaTime) { chunk.Update(deltaTime); }
