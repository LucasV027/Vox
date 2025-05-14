#include "RendererController.h"

RendererController::RendererController(Inputs& inputs, Renderer& renderer) :
    Controller(inputs), renderer(renderer) {}

void RendererController::ProcessInputs(double deltaTime) { ProcessResize(); }

void RendererController::ProcessResize() const {
    if (inputs.IsWindowResized()) {
        const auto newSize = inputs.GetWindowSize();
        renderer.SetViewPort(0, 0, newSize.x, newSize.y);
    }
}
