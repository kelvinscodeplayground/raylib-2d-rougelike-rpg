#include "Wall.hpp"

#include "Managers/SystemManager.hpp"

namespace game_objects {
Wall::Wall(size_t tileIndex) : tile { &consts::tiles::walls[tileIndex] } { }

void Wall::tick() { }

void Wall::draw()
{
    auto &sysman = managers::SystemManager::getInstance();
    auto &texture = sysman.getTexture();

    texture.Draw(*tile, position);
}
}