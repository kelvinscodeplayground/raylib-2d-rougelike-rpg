#pragma once

#include "Consts/Tiles.hpp"
#include "GameObjects/GameObject.hpp"

namespace game_objects {
class Wall : public game_objects::GameObject
{
public:
    Wall(size_t tileIndex = 0);
    virtual void tick() override;
    virtual void draw() override;

    virtual ~Wall() override {};

private:
    const raylib::Rectangle *tile { nullptr };
    const raylib::Vector2 position { 0, 0 };
};
}