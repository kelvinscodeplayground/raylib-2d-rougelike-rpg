#include <format>

#include <raylib-cpp.hpp>
#include <scope_guard.hpp>

#include "Scenes/Board.hpp"
#include "Managers/CameraManager.hpp"
#include "Managers/SceneManager.hpp"
#include "Managers/SystemManager.hpp"

int main()
{
    managers::SystemManager::getInstance().init();
    auto &window = managers::SystemManager::getInstance().getWindow();
    auto &font = managers::SystemManager::getInstance().getDefaultFont();

    managers::SceneManager::getInstance().apply(std::make_unique<scenes::Board>());

    auto &camera = managers::CameraManager::getInstance().getWorldCamera();

    while (!window.ShouldClose()) {
        managers::SystemManager::getInstance().checkFullScreen();

        window.BeginDrawing();
        auto painterGuard = sg::make_scope_guard([&]() { window.EndDrawing(); });
        window.ClearBackground(raylib::Color::Black());

        camera.BeginMode();
        managers::SceneManager::getInstance().tick();
        managers::SceneManager::getInstance().draw();
        camera.EndMode();
    }

    return 0;
}