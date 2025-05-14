#pragma once

#include "Controller.h"
#include "core/Inputs.h"
#include "graphics/Camera.h"

class CameraController final : public Controller {
public:
    CameraController(Inputs& inputs, Camera& camera);

    void ProcessInputs(double deltaTime) override;

    void SetSensitivity(float newSensitivity);
    void SetSpeed(float newSpeed);

private:
    void ProcessKeyboard(float dt) const;
    void ProcessMouse();
    void ProcessResize();
    void ProcessScroll();
private:
    Camera& camera;

    float sensitivity = 100.0f;
    float baseSpeed = 10.0f;
    float boostSpeed = 40.0f;

    glm::ivec2 windowSize;

    bool firstClick = true;

    const float BASE_FOV = 90;
    float zoom = 1.0f;
};
