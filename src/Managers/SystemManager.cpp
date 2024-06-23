#include "SystemManager.hpp"

namespace managers {
void SystemManager::init()
{
    raylib::Image icon { "assets/raylib_256x256.png" };

    window.SetTargetFPS(60);
    window.SetIcon(icon);
}

void SystemManager::checkFullScreen()
{
    if (!raylib::Keyboard::IsKeyPressed(KeyboardKey::KEY_F11)) return;

    if (isFullScreen) {
        window.ToggleBorderless();
    } else {
        window.ToggleBorderless();
    }
}

raylib::Window &SystemManager::getWindow()
{
    return window;
}

raylib::Font &managers::SystemManager::getDefaultFont()
{
    return font;
}

raylib::Texture2D &SystemManager::getTexture()
{
    return texture;
}

SystemManager &SystemManager::getInstance()
{
    static SystemManager instance;
    return instance;
};
}