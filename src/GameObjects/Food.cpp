#include "Food.hpp"

#include "Managers/SystemManager.hpp"

namespace game_objects {
Food::Food(raylib::Vector2 position) : position { position } { }

void Food::tick() { }

void Food::draw()
{
    auto &sysman = managers::SystemManager::getInstance();
    auto &texture = sysman.getTexture();
    texture.Draw(*tile, position);
}
}