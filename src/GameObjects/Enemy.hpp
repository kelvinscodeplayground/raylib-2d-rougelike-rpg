#pragma once

#include "Consts/Tiles.hpp"
#include "GameObjects/GameObject.hpp"
#include "TimingUtils/Timer.hpp"

namespace game_objects {
class Enemy : public GameObject
{
public:
    Enemy(raylib::Vector2 position = { 0, 0 });
    Enemy(size_t variant = 0, raylib::Vector2 position = { 0, 0 });
    virtual void tick() override;
    virtual void draw() override;
    virtual ~Enemy() override;

private:
    const decltype(consts::tiles::enemy::varian1::idle) *tile { nullptr };
    raylib::Vector2 position;
    int frame { 0 };
    timing_utils::Timer spriteTimer;
};
}