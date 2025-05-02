#pragma once

#include "glm/glm.hpp"

#include "Application/Inputs.h"
#include "Application/Window.h"

class Camera {
public:
    explicit Camera(const glm::vec3& position = glm::vec3(0.0f, 0.0f, -5.0f),
                    const glm::vec3& up = glm::vec3(0.0f, 1.0f, 0.0f),
                    const glm::vec3& orientation = glm::vec3(0.0f, 0.0f, 1.0f));

    void Init(int width, int height);

    void Compute(float fovDeg, float aspectRatio, float nearPlane, float farPlane);

    const glm::mat4& GetViewMatrix() const;
    const glm::mat4& GetProjectionMatrix() const;

    void Update();

    void ProcessInputs(const Inputs& inputs, const Window& window, double deltaTime);

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
