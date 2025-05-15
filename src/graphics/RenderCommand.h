#pragma once

#include "IndexBuffer.h"
#include "Program.h"
#include "VertexArray.h"

class RenderCommand {
public:
    static void Clear(float r, float g, float b, float a);
    static void Draw(const VertexArray& vao, const IndexBuffer& ibo, const Program& program);
    static void Draw(const VertexArray& vao, int first, int count, const Program& program);

    static void SetDepthTest(bool enabled);
    static void SetCullFace(bool enabled);
    static void SetWireframe(bool enabled);
};
