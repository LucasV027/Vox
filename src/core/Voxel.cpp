#include "Voxel.h"

Voxel::Voxel() = default;

void Voxel::OnUpdate(const Input& inputs, const double deltaTime) { chunk.Update(deltaTime); }
