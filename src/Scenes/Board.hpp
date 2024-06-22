#pragma once
#include "Scenes/Scene.hpp"

#include <array>
#include <tuple>

#include <raylib-cpp.hpp>

namespace scenes {
class Board : public Scene
{
public:
    Board();

    void tick() override;
    void draw() override;

private:
    raylib::Music bgm { "assets/Audio/scavengers_music.aif.wav" };
    std::array<std::tuple<raylib::Vector2, size_t>, 36> hardWalls;
};
}