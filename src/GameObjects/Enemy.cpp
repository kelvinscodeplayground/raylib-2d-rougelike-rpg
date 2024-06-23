#include "Enemy.hpp"

#include <random>

#include "Managers/SystemManager.hpp"

namespace game_objects {
Enemy::Enemy(size_t variant, raylib::Vector2 position) : position(position)
{
    if (variant == 0) {
        std::random_device rd;
        std::mt19937 mt { rd() };
        std::uniform_int_distribution<int> dist { 1, 2 };
        variant = dist(mt);
    }

    if (variant == 1)
        tile = &consts::tiles::enemy::varian1::idle;
    else
        tile = &consts::tiles::enemy::varian2::idle;
}

void Enemy::tick()
{
    const auto diff = std::chrono::steady_clock::now() - lastTick;
    if (diff > std::chrono::milliseconds(150)) {
        frame = frame >= 5 ? 0 : frame + 1;
        lastTick = std::chrono::steady_clock::now();
    }
}

void Enemy::draw()
{
    auto &sysman = managers::SystemManager::getInstance();
    auto &texture = sysman.getTexture();
    auto &window = sysman.getWindow();

    texture.Draw(tile->at(frame), position);
}

Enemy::~Enemy() { }
}