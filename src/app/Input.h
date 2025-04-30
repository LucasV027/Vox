#pragma once

#include <unordered_map>

class GLFWwindow;

class Input {
public:
    explicit Input(GLFWwindow* window);
    void Poll();

    bool IsKeyPressed(int key) const;
    bool IsMouseButtonPressed(int button) const;
    bool IsMouseFree() const;
    bool IsWindowResized(int& newWidth, int& newHeight) const;
    void GetMousePosition(double& x, double& y) const;

private:
    // Window resize
    bool resizeEvent = true;
    int width;
    int height;

    // Cursor position
    double xPos;
    double yPos;

    // Keyboard
    std::unordered_map<int, bool> keyStates;

    // Mouse
    std::unordered_map<int, bool> mouseStates;
};
