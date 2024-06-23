#include "Soda.hpp"

#include "Managers/SystemManager.hpp"

namespace game_objects {
Soda::Soda(raylib::Vector2 position) : position { position } { }

void Soda::tick() { }

void Soda::draw()
{
    auto &sysman = managers::SystemManager::getInstance();
    auto &texture = sysman.getTexture();
    texture.Draw(*tile, position);
}

Soda::~Soda() { }
}