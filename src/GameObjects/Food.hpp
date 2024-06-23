#pragma once

#include "Consts/Tiles.hpp"
#include "GameObjects/GameObject.hpp"

namespace game_objects {
class Food : public GameObject
{
public:
    Food(raylib::Vector2 position = { 0, 0 });
    virtual void tick() override;
    virtual void draw() override;
    virtual ~Food() override { }

private:
    const raylib::Rectangle *tile { &consts::tiles::food };
    raylib::Vector2 position;
};
}