#pragma once

#include "graphics/Renderer.h"
#include "Controller.h"
#include "core/Inputs.h"

class RendererController final : public Controller {
public:
    RendererController(Inputs& inputs, Renderer& renderer);

    void ProcessInputs(double deltaTime) override;
private:
    void ProcessResize() const;

private:
    Renderer& renderer;
};
