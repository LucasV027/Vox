#pragma once

#include "glm/glm.hpp"

#include "app/Input.h"

class Camera {
public:
    explicit Camera(const glm::vec3& position = glm::vec3(0.0f, 0.0f, -5.0f),
                    const glm::vec3& up = glm::vec3(0.0f, 1.0f, 0.0f),
                    const glm::vec3& orientation = glm::vec3(0.0f, 0.0f, 1.0f));

    void Compute(float fovDeg, float aspectRatio, float nearPlane, float farPlane);

    const glm::mat4& GetViewMatrix() const;
    const glm::mat4& GetProjectionMatrix() const;

    void Update();
    void ProcessInputs(const Input& inputs, double deltaTime);

private:
    void ProcessKeyboard(const Input& inputs, double deltaTime);
    void ProcessMouse(const Input& inputs);
    void ProcessWindowResize(const Input& inputs);

private:
    glm::vec3 position;
    glm::vec3 up;
    glm::vec3 orientation;

    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 proj = glm::mat4(1.0f);

private:
    float aspectRatio = 0.0f;
    bool firstClick = true;
    int width{}, height{};
    float speed = 10.f;
    float sensitivity = 100.0f;
};
