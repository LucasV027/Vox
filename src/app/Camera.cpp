#include "Camera.h"

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/vector_angle.hpp"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"

Camera::Camera(const glm::vec3& position, const glm::vec3& up, const glm::vec3& orientation) :
    position(position), up(up), orientation(orientation) {}

void Camera::Init(const int width, const int height) {
    this->width = width;
    this->height = height;
    aspectRatio = static_cast<float>(width) / static_cast<float>(height);
}


void Camera::Compute(const float fovDeg, const float aspectRatio, const float nearPlane,
                     const float farPlane) {
    view = lookAt(position, position + orientation, up);
    proj = glm::perspective(glm::radians(fovDeg), aspectRatio, nearPlane, farPlane);
}

const glm::mat4& Camera::GetViewMatrix() const { return view; }

const glm::mat4& Camera::GetProjectionMatrix() const { return proj; }

void Camera::Update() { Compute(45.f, aspectRatio, 0.1f, 100.0f); }

void Camera::ProcessInputs(const Input& inputs, const Window& window, const double deltaTime) {
    const auto dt = static_cast<float>(deltaTime);
    if (inputs.IsKeyPressed(GLFW_KEY_W))
        position += dt * speed * orientation;
    if (inputs.IsKeyPressed(GLFW_KEY_S))
        position -= dt * speed * orientation;
    if (inputs.IsKeyPressed(GLFW_KEY_D))
        position += dt * speed * normalize(cross(orientation, up));
    if (inputs.IsKeyPressed(GLFW_KEY_A))
        position -= dt * speed * normalize(cross(orientation, up));
    if (inputs.IsKeyPressed(GLFW_KEY_SPACE))
        position += dt * speed * up;
    if (inputs.IsKeyPressed(GLFW_KEY_LEFT_CONTROL))
        position -= dt * speed * up;
    if (inputs.IsKeyPressed(GLFW_KEY_LEFT_SHIFT))
        speed = 40.f;
    if (!inputs.IsKeyPressed(GLFW_KEY_LEFT_SHIFT))
        speed = 10.f;

    if (inputs.IsMouseFree() && inputs.IsMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT)) {
        window.SetCursorVisibility(false);

        // Prevent camera from jumping on the first click
        if (firstClick) {
            window.SetMousePosition(width / 2, height / 2);
            firstClick = false;
        }

        // Stores the coordinates of the cursor
        double mouseX, mouseY;
        window.GetMousePosition(mouseX, mouseY);

        // Normalizes and shifts the coordinates of the cursor
        const float rotX = sensitivity * static_cast<float>(mouseY - (height / 2)) / height;
        const float rotY = sensitivity * static_cast<float>(mouseX - (width / 2)) / width;

        // Calculate upcoming vertical change in the orientation
        glm::vec3 newOrientation =
            rotate(orientation, glm::radians(-rotX), normalize(cross(orientation, up)));

        // Ensure the vertical orientation stays within legal bounds
        if (abs(glm::angle(newOrientation, up) - glm::radians(90.0f)) <= glm::radians(85.0f)) {
            orientation = newOrientation;
        }

        // Rotate the orientation left and right
        orientation = rotate(orientation, glm::radians(-rotY), up);

        // inputs.SetMousePosition(width / 2, height / 2);
    } else if (!inputs.IsMouseButtonPressed(GLFW_RELEASE)) {
        window.SetCursorVisibility(true);
        firstClick = true;
    }

    if (inputs.IsWindowResized(width, height)) {
        aspectRatio = static_cast<float>(width) / static_cast<float>(height);
    }
}
