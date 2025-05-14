#include "CameraController.h"

#include <iostream>

#define GLM_ENABLE_EXPERIMENTAL
#include "GLFW/glfw3.h"
#include "glm/gtx/rotate_vector.hpp"
#include "glm/gtx/vector_angle.hpp"

CameraController::CameraController(Camera& camera, Inputs& inputs, const int screenWidth,
                                   const int screenHeight) :
    camera(camera), inputs(inputs), width(screenWidth), height(screenHeight) {}

void CameraController::SetSensitivity(const float newSensitivity) { sensitivity = newSensitivity; }

void CameraController::SetSpeed(const float newSpeed) { baseSpeed = newSpeed; }

void CameraController::Update(const double deltaTime) {
    const auto dt = static_cast<float>(deltaTime);
    ProcessKeyboard(dt);
    ProcessMouse();
}

void CameraController::ProcessKeyboard(const float dt) const {
    glm::vec3 pos = camera.GetPosition();
    const glm::vec3 orientation = camera.GetOrientation();
    constexpr glm::vec3 up = {0.f, 1.f, 0.f};

    const float speed = inputs.IsKeyPressed(GLFW_KEY_LEFT_SHIFT) ? boostSpeed : baseSpeed;

    if (inputs.IsKeyPressed(GLFW_KEY_W))
        pos += dt * speed * orientation;
    if (inputs.IsKeyPressed(GLFW_KEY_S))
        pos -= dt * speed * orientation;
    if (inputs.IsKeyPressed(GLFW_KEY_D))
        pos += dt * speed * glm::normalize(glm::cross(orientation, up));
    if (inputs.IsKeyPressed(GLFW_KEY_A))
        pos -= dt * speed * glm::normalize(glm::cross(orientation, up));
    if (inputs.IsKeyPressed(GLFW_KEY_SPACE))
        pos += dt * speed * up;
    if (inputs.IsKeyPressed(GLFW_KEY_LEFT_CONTROL))
        pos -= dt * speed * up;

    camera.SetPosition(pos);
}

void CameraController::ProcessMouse() {
    if (inputs.IsMouseFree() && inputs.IsMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT)) {
        inputs.SetCursorVisibility(false);

        if (firstClick) {
            inputs.SetMousePosition(width / 2.0, height / 2.0);
            firstClick = false;
            return;
        }

        double mouseX, mouseY;
        inputs.GetMousePosition(mouseX, mouseY);

        float rotX = sensitivity * static_cast<float>(mouseY - height / 2) / height;
        float rotY = sensitivity * static_cast<float>(mouseX - width / 2) / width;

        glm::vec3 orientation = camera.GetOrientation();
        glm::vec3 up = {0.f, 1.f, 0.f};

        glm::vec3 newOrientation = glm::rotate(orientation, glm::radians(-rotX),
                                               glm::normalize(glm::cross(orientation, up)));

        if (std::abs(glm::angle(newOrientation, up) - glm::radians(90.0f)) <= glm::radians(85.0f)) {
            orientation = newOrientation;
        }

        orientation = glm::rotate(orientation, glm::radians(-rotY), up);

        camera.SetOrientation(orientation);
        inputs.SetMousePosition(width / 2.0, height / 2.0);
    } else {
        inputs.SetCursorVisibility(true);
        firstClick = true;
    }

    int newWidth, newHeight;
    if (inputs.IsWindowResized(width, height)) {
        width = newWidth;
        height = newHeight;
    }
}
