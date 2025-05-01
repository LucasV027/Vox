#include "Time.h"

#include "GLFW/glfw3.h"

double Time::currentFrame;
double Time::deltaTime;
double Time::lastFrame;

void Time::Update() {
    currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
}

double Time::DeltaTime() { return deltaTime; }
