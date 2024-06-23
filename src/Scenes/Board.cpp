#include "Board.hpp"

#include <format>
#include <random>

#include "Consts/Tiles.hpp"
#include "GameObjects/Floor.hpp"
#include "Managers/SystemManager.hpp"

scenes::Board::Board()
{
    initBoard();
    bgm.Play();
}

void scenes::Board::tick()
{
    for (const auto &j : grid) {
        for (const auto &i : j) {
            if (i == nullptr) continue;
            i->tick();
        }
    }

    bgm.Update();
}

void scenes::Board::draw()
{
    const auto tileSize = consts::tiles::tileSize;
    auto &system = managers::SystemManager::getInstance();
    auto &font = system.getDefaultFont();
    auto &texture = system.getTexture();
    auto &hardWallTiles = consts::tiles::hardWalls;

    for (const auto &wall : hardWalls) {
        const auto &wallPos = std::get<0>(wall);
        raylib::Rectangle wallSrcRect { hardWallTiles[std::get<1>(wall)] };
        texture.Draw(wallSrcRect, wallPos);
    }

    for (const auto &j : grid) {
        for (const auto &i : j) {
            if (i == nullptr) continue;
            i->draw();
        }
    }

    texture.Draw(consts::tiles::exit, raylib::Vector2 { 8 * 32, 1 * 32 });
}

void scenes::Board::initBoard()
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

    int gridY = 1;
    for (auto &j : grid) {
        int gridX = 1;
        for (auto &i : j) {
            if (gridX == 8 && gridY == 1) continue;

            std::uniform_int_distribution<int> dist { 0,
                static_cast<int>(consts::tiles::floors.size() - 1) };
            i = std::make_unique<game_objects::Floor>(
                    dist(re), raylib::Vector2 { gridX * 32.f, gridY * 32.f });
            gridX++;
        }
        gridY++;
    }
}
