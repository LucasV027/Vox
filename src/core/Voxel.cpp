#include "Voxel.h"

Voxel::Voxel() {
    program.Create(vsPath, fsPath);
    program.LocateVariable("mvp");
}

void Voxel::OnUpdate(const Input& inputs, const double deltaTime) {
    camera.ProcessInputs(inputs, deltaTime);
    camera.Update();
    chunk.Update(deltaTime);
}

void Voxel::OnRender(const Renderer& renderer) {
    program.Bind();
    program.SetUniformMat4f("mvp", camera.GetProjectionMatrix() * camera.GetViewMatrix());
    chunk.Render(renderer, program);
}
