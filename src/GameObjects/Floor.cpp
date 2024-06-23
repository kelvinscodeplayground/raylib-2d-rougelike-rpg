#include "Floor.hpp"

#include <random>

#include "Managers/SystemManager.hpp"

namespace game_objects {
Floor::Floor(raylib::Vector2 position) : position { position }
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, static_cast<int>(consts::tiles::floors.size() - 1));
    const auto tileIndex = dist(mt);
    tile = &consts::tiles::floors[tileIndex];
}

Floor::Floor(size_t tileIndex, raylib::Vector2 position)
    : tile { &consts::tiles::floors[tileIndex] }, position { position }
{
}

void Floor::tick() { }

void Floor::draw()
{
    auto &sysman = managers::SystemManager::getInstance();
    auto &texture = sysman.getTexture();
    texture.Draw(*tile, position);
}
}