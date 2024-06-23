#pragma once

#include "Consts/Tiles.hpp"
#include "GameObjects/GameObject.hpp"

namespace game_objects {
class Floor : public GameObject
{
public:
    Floor(size_t tileIndex = 0, raylib::Vector2 position = { 0, 0 });

    virtual void tick() override;
    virtual void draw() override;

    virtual ~Floor() override {};

private:
    const raylib::Rectangle *tile { nullptr };
    raylib::Vector2 position {};
};
}