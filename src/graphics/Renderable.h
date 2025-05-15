#pragma once

#include "Program.h"

class Renderable {
public:
    virtual ~Renderable() = default;
    virtual void Render(const Program& program) const = 0;
};
