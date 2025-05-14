#pragma once

#include "Inputs.h"
#include "Window.h"
#include "graphics/IndexBuffer.h"
#include "graphics/Program.h"
#include "graphics/VertexArray.h"

class Renderer {
public:
    explicit Renderer(WindowRef window);
    ~Renderer() = default;

    void BeginFrame() const;

    void OnInput(const Inputs& inputs, double deltaTime) const;

    void Clear(float r = 0.2f, float g = 0.2f, float b = 0.2f, float a = 1.0f) const;
    void SetDepthTest(bool val) const;
    void SetViewPort(int x, int y, int width, int height) const;
    void Draw(const VertexArray& vao, const IndexBuffer& ibo, const Program& program) const;
    void Draw(const VertexArray& vao, int first, int count, const Program& program) const;

private:
    WindowRef windowRef;
};
