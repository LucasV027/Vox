#include "SkyBox.h"

#include <iostream>

#include "RenderCommand.h"

void SkyBox::Init(const std::vector<std::filesystem::path>& faces) {
    vao.Init();
    vbo.Load(CUBE, sizeof(CUBE));

    VertexBufferLayout skyboxVboLayout;
    skyboxVboLayout.Push<float>(3);

    vao.AddBuffer(vbo, skyboxVboLayout);

    skyboxProgram.Create(skyboxVsPath, skyboxFsPath);
    skyboxProgram.LocateVariable("view");
    skyboxProgram.LocateVariable("proj");
    skyboxProgram.LocateVariable("skybox");

    texture.LoadCubeMap(faces);
    texture.Bind(slot);
    skyboxProgram.SetUniform1i("skybox", slot);
}

void SkyBox::Render(const Camera& camera) const {
    RenderCommand::SetDepthTest(false);

    skyboxProgram.Bind();

    skyboxProgram.SetUniformMat4f("view", glm::mat4(glm::mat3(camera.GetView())));
    skyboxProgram.SetUniformMat4f("proj", camera.GetProjection());
    texture.Bind(slot);
    RenderCommand::Draw(vao, 0, 36, skyboxProgram);

    skyboxProgram.Unbind();
    RenderCommand::SetDepthTest(true);
}
