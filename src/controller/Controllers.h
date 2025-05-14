#pragma once

#include <vector>


class Controller;

class Controllers {
public:
    Controllers() = default;
    ~Controllers();

    template <typename T, typename... Args>
    void Register(Args&&... args) {
        static_assert(std::is_base_of_v<Controller, T>, "T must inherit from Controller");
        controllers.push_back(new T(std::forward<Args>(args)...));
    }

    void ProcessInputs(double deltaTime);

private:
    std::vector<Controller*> controllers;
};
