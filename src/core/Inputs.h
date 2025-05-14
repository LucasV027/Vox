#pragma once

#include <unordered_map>

#include "Window.h"

class Inputs {
public:
    explicit Inputs(WindowRef windowRef);
    void Poll();

    // Input
    bool IsKeyPressed(int key) const;
    bool IsMouseButtonPressed(int button) const;
    bool IsMouseFree() const;
    bool IsWindowResized() const;
    bool IsMouseScrolled() const;
    glm::dvec2 GetMousePosition() const;
    glm::ivec2 GetWindowSize() const;
    glm::dvec2 GetScrollOffset() const;

    // Output
    void SetCursorVisibility(bool visible) const;
    void SetMousePosition(double xPos, double yPos) const;

private:
    WindowRef windowRef;

    // Window resize
    bool resizeEvent = true;
    glm::ivec2 resizeSize;

    // Keyboard
    std::unordered_map<int, bool> keyStates;

    // Mouse
    std::unordered_map<int, bool> mouseStates;
    glm::dvec2 mouseScrollOffset;
    bool scrollEvent = false;
};
