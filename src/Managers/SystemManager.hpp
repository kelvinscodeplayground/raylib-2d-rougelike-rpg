#pragma once
#include <raylib-cpp.hpp>

namespace managers {
class SystemManager
{
public:
    SystemManager() = default;
    SystemManager(const SystemManager &) = delete;
    SystemManager &operator=(const SystemManager &) = delete;

    void init();
    void checkFullScreen();

    raylib::Window &getWindow();
    raylib::Font &getDefaultFont();
    raylib::Texture2D &getTexture();

    static SystemManager &getInstance();

    static constexpr int WindowHeight { 800 };
    static constexpr int WindowWidth { 800 };

private:
    raylib::Window window { WindowWidth, WindowHeight, "2D Rouge Like" };
    raylib::AudioDevice audioDevice;
    raylib::Font font { "assets/Fonts/PressStart2P-Regular.ttf" };
    raylib::Texture2D texture { "assets/Sprites/Scavengers_SpriteSheet.png" };
};
}