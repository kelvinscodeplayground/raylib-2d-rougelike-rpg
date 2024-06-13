#include "Board.hpp"

#include <format>

#include "Managers/SystemManager.hpp"

scenes::Board::Board()
{
    bgm.Play();
}

void scenes::Board::tick()
{
    bgm.Update();
}

void scenes::Board::draw()
{
    auto &font = managers::SystemManager::getInstance().getDefaultFont();
    auto WindowWidth = managers::SystemManager::WindowWidth;
    auto WindowHeight = managers::SystemManager::WindowHeight;

    raylib::Color::Black().DrawText(font, "Hello World", { 15, 15 }, 32, 1);
    raylib::Color::Black().DrawText(font,
            std::format("Window size is {}x{}", WindowWidth, WindowHeight), { 15, 15 + 32 }, 16, 1);
}
