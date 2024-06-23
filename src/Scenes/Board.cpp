#include "Board.hpp"

#include <format>
#include <random>
#include <vector>

#include "Consts/Tiles.hpp"
#include "GameObjects/Floor.hpp"
#include "GameObjects/Wall.hpp"
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
    std::mt19937 mt(rd());
    std::srand(rd());

    int wallCount = 0;
    for (int wallY = 0; wallY < 10; wallY++) {
        for (int wallX = 0; wallX < 10; wallX++) {
            if (wallY != 0 && wallY != 9 && wallX != 0 && wallX != 9) continue;

            hardWalls[wallCount++] = std::make_tuple(
                    raylib::Vector2 { static_cast<float>(wallX * consts::tiles::tileSize),
                            static_cast<float>(wallY * consts::tiles::tileSize) },
                    std::rand() % 3);
        }
    }

    std::vector<raylib::Vector2> floorPositions;

    for (int j = 2; j < 7; j++) {
        for (int i = 2; i < 7; i++) {
            floorPositions.emplace_back(
                    raylib::Vector2 { static_cast<float>(i), static_cast<float>(j) });
        }
    }

    std::shuffle(floorPositions.begin(), floorPositions.end(), mt);

    const auto softWallCount = std::uniform_int_distribution<int> { 5, 9 }(mt);
    for (int count = 0; count < softWallCount; count++) {
        const auto selectedPos = floorPositions.back();
        floorPositions.pop_back();

        const auto i = static_cast<int>(selectedPos.GetX());
        const auto j = static_cast<int>(selectedPos.GetY());

        grid[j][i] = std::make_unique<game_objects::Wall>(selectedPos * 32);
    }
}
