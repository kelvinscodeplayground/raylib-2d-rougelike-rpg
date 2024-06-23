#pragma once

#include "Consts/Tiles.hpp"
#include "GameObjects/GameObject.hpp"

namespace game_objects {
class Soda : public GameObject
{
public:
    Soda(raylib::Vector2 = { 0, 0 });
    virtual void tick() override;
    virtual void draw() override;
    virtual ~Soda() override;

private:
    const raylib::Rectangle *tile { &consts::tiles::soda };
    raylib::Vector2 position;
};
}