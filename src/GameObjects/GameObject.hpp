#pragma once

namespace game_objects {
struct GameObject
{
    virtual void tick() = 0;
    virtual void draw() = 0;
    virtual ~GameObject() = 0 {};
};
}