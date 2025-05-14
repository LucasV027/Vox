#include "RendererController.h"

RendererController::RendererController(Inputs& inputs, Renderer& renderer) :
    Controller(inputs), renderer(renderer) {}

void RendererController::ProcessInputs(double deltaTime) { ProcessResize(); }

void RendererController::ProcessResize() const {
    int width, height;
    if (inputs.IsWindowResized(width, height)) {
        renderer.SetViewPort(0, 0, width, height);
    }
}
