#pragma once

#include <string>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h> // Do not remove

class Application {
public:
    Application();
    ~Application();
    void Run();

private:
    void Update(double deltaTime);
    void Render() const;

private:
    std::string title = "Vox";
    int width = 640;
    int height = 480;

    GLFWwindow* window;
};
