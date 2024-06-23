#include "Floor.hpp"

#include "Managers/SystemManager.hpp"

namespace game_objects {
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