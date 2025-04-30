#pragma once

class Time {
public:
    static void Update();
    static double DeltaTime();

private:
    static double currentFrame;
    static double lastFrame;
    static double deltaTime;
};
