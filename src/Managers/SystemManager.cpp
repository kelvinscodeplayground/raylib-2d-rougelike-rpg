#include "SystemManager.hpp"

namespace managers {
void SystemManager::init()
{
    raylib::Image icon { "assets/raylib_256x256.png" };

    window.SetTargetFPS(60);
    window.SetIcon(icon);
}

raylib::Window &SystemManager::getWindow()
{
    return window;
}

raylib::Font &managers::SystemManager::getDefaultFont()
{
    return font;
}

SystemManager &SystemManager::getInstance()
{
    static SystemManager instance;
    return instance;
};
}