#include "SceneManager.hpp"

namespace managers {
SceneManager &SceneManager::getInstance()
{
    static SceneManager instance;
    return instance;
}

void SceneManager::apply(std::unique_ptr<scenes::Scene> newScene)
{
    currentScene = std::move(newScene);
}

void SceneManager::tick()
{
    if (currentScene == nullptr) return;
    currentScene->tick();
}

void SceneManager::draw()
{
    if (currentScene == nullptr) return;
    currentScene->draw();
}
}