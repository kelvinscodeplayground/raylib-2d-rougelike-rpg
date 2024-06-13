#pragma once
#include <raylib-cpp.hpp>

namespace scenes {
struct Scene
{
public:
    virtual void tick() = 0;
    virtual void draw() = 0;
};
}