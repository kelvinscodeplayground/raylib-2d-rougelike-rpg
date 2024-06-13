#pragma once
#include <memory>

#include "Scenes/Scene.hpp"

namespace managers {
class SceneManager
{
public:
    SceneManager() = default;
    SceneManager(const SceneManager &) = delete;
    const SceneManager &operator=(const SceneManager &) = delete;

    static SceneManager &getInstance();

    void apply(std::unique_ptr<scenes::Scene> newScene);
    void tick();
    void draw();

    ~SceneManager() = default;

private:
    std::unique_ptr<scenes::Scene> currentScene;
};
}