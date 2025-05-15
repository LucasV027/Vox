#pragma once

#include "core/Window.h"
#include "IndexBuffer.h"
#include "Program.h"
#include "VertexArray.h"

class Renderer {
public:
    explicit Renderer(WindowRef window);
    ~Renderer() = default;

    void BeginFrame() const;
    void Clear(float r = 0.2f, float g = 0.2f, float b = 0.2f, float a = 1.0f) const;
    void SetDepthTest(bool val) const;
    void SetViewPort(int x, int y, int width, int height) const;
    void Draw(const VertexArray& vao, const IndexBuffer& ibo, const Program& program) const;
    void Draw(const VertexArray& vao, int first, int count, const Program& program) const;

private:
    WindowRef windowRef;
};
