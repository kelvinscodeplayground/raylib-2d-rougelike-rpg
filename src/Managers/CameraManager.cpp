#include "CameraManager.hpp"

#include <cmath>

#include "Managers/SystemManager.hpp"

namespace managers {
CameraManager::CameraManager()
{
    centerWorldCamera();
}

CameraManager &CameraManager::getInstance()
{
    static CameraManager instance;
    return instance;
}

raylib::Camera2D &CameraManager::getWorldCamera()
{
    return worldCamera;
}

void CameraManager::centerWorldCamera()
{
    auto &system = managers::SystemManager::getInstance();
    auto &window = system.getWindow();
    const raylib::Vector2 offset { window.GetWidth() / 2.f, window.GetHeight() / 2.f };
    const raylib::Vector2 mapTarget { 320.f / 2.f, 320.f / 2.f };
    const float scale { std::min(window.GetWidth(), window.GetHeight()) / 320.f };
    worldCamera.SetOffset(offset);
    worldCamera.SetTarget(mapTarget);
    worldCamera.SetZoom(scale);
}
}