#include <format>

#include <raylib-cpp.hpp>
#include <scope_guard.hpp>

#include "Scenes/Board.hpp"
#include "Managers/SceneManager.hpp"
#include "Managers/SystemManager.hpp"

int main()
{
    managers::SystemManager::getInstance().init();
    auto &window = managers::SystemManager::getInstance().getWindow();
    auto &font = managers::SystemManager::getInstance().getDefaultFont();

    managers::SceneManager::getInstance().apply(std::make_unique<scenes::Board>());

    while (!window.ShouldClose()) {
        window.BeginDrawing();
        auto painterGuard = sg::make_scope_guard([&]() { window.EndDrawing(); });
        window.ClearBackground({ 255, 255, 255, 255 });
        managers::SceneManager::getInstance().tick();
        managers::SceneManager::getInstance().draw();
    }

    return 0;
}