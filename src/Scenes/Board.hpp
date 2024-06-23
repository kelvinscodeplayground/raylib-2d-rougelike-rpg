#pragma once
#include "Scenes/Scene.hpp"

#include <array>
#include <memory>
#include <tuple>
#include <vector>

#include <raylib-cpp.hpp>

#include "GameObjects/GameObject.hpp"

namespace scenes {
class Board : public Scene
{
public:
    Board();

    void tick() override;
    void draw() override;

private:
    void initBoard();

private:
    raylib::Music bgm { "assets/Audio/scavengers_music.aif.wav" };
    std::array<std::tuple<raylib::Vector2, size_t>, 36> hardWalls;
    std::array<std::array<std::unique_ptr<game_objects::GameObject>, 8>, 8> grid;
    std::vector<std::unique_ptr<game_objects::GameObject>> floorGrid;
    int level { 5 };
};
}