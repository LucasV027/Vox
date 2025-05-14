#pragma once

class Timer {
public:
    Timer() = default;
    void Start();
    void Update();
    double DeltaTime() const;

private:
    double currentFrame;
    double lastFrame;
    double deltaTime;
};
