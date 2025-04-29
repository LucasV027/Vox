#include "Application.h"

#include <iostream>

Application::Application() {
    // GLFW initialization
    if (!glfwInit()) {
        exit(1);
    }

    glfwSetErrorCallback([](int error, const char* description) {
        std::cerr << "GLFW Error (" << error << "): " << description << std::endl;
    });

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        exit(1);
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // V-Sync

    // GLAD initialization
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        exit(1);
    }

    renderer = new Renderer(window);
    renderer->Init();
}

Application::~Application() {
    delete renderer;

    glfwDestroyWindow(window);
    glfwTerminate();
}

void Application::Run() {
    double currentFrame = glfwGetTime();
    double lastFrame = currentFrame;
    double deltaTime;

    while (!glfwWindowShouldClose(window)) {
        currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        Update(deltaTime);
        renderer->Render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Application::Update(double deltaTime) {}
