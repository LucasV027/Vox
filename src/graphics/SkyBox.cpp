#include "SkyBox.h"

void SkyBox::Init(const std::vector<std::filesystem::path>& faces) {
    vao.Init();
    vbo.Load(CUBE, sizeof(CUBE));

    VertexBufferLayout skyboxVboLayout;
    skyboxVboLayout.Push<float>(3);

    vao.AddBuffer(vbo, skyboxVboLayout);

    program.Create(skyboxVsPath, skyboxFsPath);
    program.LocateVariable("mvp");
    program.LocateVariable("skybox");

    constexpr int slot = 0;
    texture.LoadCubeMap(faces);
    texture.Bind(slot);
    program.SetUniform1i("skybox", slot);
}

void SkyBox::Render(const Renderer& renderer, const Camera& camera) const {
    renderer.SetDepthTest(false);
    program.Bind();
    program.SetUniformMat4f(
        "mvp", camera.GetProjection() * glm::mat4(glm::mat3(camera.GetView())));

    renderer.Draw(vao, 0, 36, program);
    renderer.SetDepthTest(true);
    program.Unbind();
}
