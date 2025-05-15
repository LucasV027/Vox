#pragma once

#include "glm/vec3.hpp"
#include "graphics/Renderable.h"
#include "graphics/VertexArray.h"

class Cube final : public Renderable {
public:
    Cube();
    ~Cube() override = default;
    void Render(const Program& program) const override;

private:
    VertexArray vao;
    VertexBuffer vbo;
    glm::vec3 position{0, 0, -5};
    glm::vec3 size{1, 1, 1};
};
