#pragma once

#include "Camera.h"
#include "core/Inputs.h"

class CameraController {
public:
    CameraController(Camera& camera, Inputs& inputs, int screenWidth, int screenHeight);

    void Update(double deltaTime);

    void SetSensitivity(float newSensitivity);
    void SetSpeed(float newSpeed);

private:
    void ProcessKeyboard(float dt) const;
    void ProcessMouse();

private:
    Camera& camera;
    Inputs& inputs;

    float sensitivity = 100.0f;
    float baseSpeed = 10.0f;
    float boostSpeed = 40.0f;

    int width;
    int height;

    bool firstClick = true;
};
