#pragma once

#include "Controller.h"
#include "core/Inputs.h"
#include "core/Renderer.h"

class RendererController final : public Controller {
public:
    RendererController(Inputs& inputs, Renderer& renderer);

    void ProcessInputs(double deltaTime) override;
private:
    void ProcessResize() const;

private:
    Renderer& renderer;
};
