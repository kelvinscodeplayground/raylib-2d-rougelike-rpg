#include "Board.hpp"

#include <format>
#include <random>

#include "Consts/Tiles.hpp"
#include "Managers/SystemManager.hpp"

scenes::Board::Board()
{
    std::random_device rd;
    std::mt19937 re { rd() };
    std::uniform_int_distribution<int> dist { 0,
        static_cast<int>(consts::tiles::hardWalls.size()) - 1 };

    int wallCount = 0;
    for (int wallY = 0; wallY < 10; wallY++) {
        for (int wallX = 0; wallX < 10; wallX++) {
            if (wallY != 0 && wallY != 9 && wallX != 0 && wallX != 9) continue;

            hardWalls[wallCount++] = std::make_tuple(
                    raylib::Vector2 { static_cast<float>(wallX * consts::tiles::tileSize),
                            static_cast<float>(wallY * consts::tiles::tileSize) },
                    dist(re));
        }
    }

    bgm.Play();
}

void scenes::Board::tick()
{
    bgm.Update();
}

void scenes::Board::draw()
{
    auto &system = managers::SystemManager::getInstance();
    auto &font = system.getDefaultFont();
    auto &texture = system.getTexture();
    auto &hardWallTiles = consts::tiles::hardWalls;

    for (const auto &wall : hardWalls) {
        const auto &wallPos = std::get<0>(wall);
        raylib::Rectangle wallSrcRect { hardWallTiles[std::get<1>(wall)] };
        texture.Draw(wallSrcRect, wallPos);
    }
}