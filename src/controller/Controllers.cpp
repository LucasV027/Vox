#include "Controllers.h"

#include "Controller.h"

Controllers::~Controllers() {
    for (const auto controller : controllers) {
        delete controller;
    }
}

void Controllers::ProcessInputs(const double deltaTime) {
    for (const auto& controller : controllers) {
        controller->ProcessInputs(deltaTime);
    }
}
