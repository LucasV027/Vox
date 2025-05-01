#include "SkyBox.h"

void SkyBox::Init() {
    vao.Init();
    vbo.Load(CUBE, sizeof(CUBE));

    VertexBufferLayout skyboxVboLayout;
    skyboxVboLayout.Push<float>(3);

    vao.AddBuffer(vbo, skyboxVboLayout);

    program.Create(skyboxVsPath, skyboxFsPath);
    program.LocateVariable("mvp");
    program.LocateVariable("skybox");

    constexpr int slot = 0;
    texture.LoadCubeMap(SKYBOX_PATHS);
    texture.Bind(slot);
    program.SetUniform1i("skybox", slot);
}
