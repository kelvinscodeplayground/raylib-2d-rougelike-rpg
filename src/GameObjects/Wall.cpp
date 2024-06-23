#include "Wall.hpp"

#include <random>

#include "Managers/SystemManager.hpp"

namespace game_objects {
Wall::Wall(raylib::Vector2 position) : position { position }
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, static_cast<int>(consts::tiles::walls.size() - 1));
    const auto tileIndex = dist(mt);
    tile = &consts::tiles::walls[tileIndex];
}

Wall::Wall(size_t tileIndex, raylib::Vector2 position)
    : tile { &consts::tiles::walls[tileIndex] }, position { position }
{
}

void Wall::tick() { }

void Wall::draw()
{
    auto &sysman = managers::SystemManager::getInstance();
    auto &texture = sysman.getTexture();

    texture.Draw(*tile, position);
}
}