#include "Time.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

double Time::currentFrame;
double Time::deltaTime;
double Time::lastFrame;

void Time::Update() {
    currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
}

double Time::DeltaTime() { return deltaTime; }
