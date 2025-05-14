#pragma once

#include "core/Inputs.h"

class Controller {
public:
    virtual ~Controller() = default;
    virtual void ProcessInputs(double deltaTime) = 0;

protected:
    explicit Controller(Inputs& inputs) : inputs(inputs) {}
    Inputs& inputs;
};
