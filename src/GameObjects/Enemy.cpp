#include "Enemy.hpp"

#include "Managers/SystemManager.hpp"

namespace game_objects {
Enemy::Enemy(size_t variant, raylib::Vector2 position) : position(position)
{
    tile = &consts::tiles::enemy::varian1::idle;
}

void Enemy::tick()
{
    const auto diff = std::chrono::steady_clock::now() - lastTick;
    if (diff > std::chrono::milliseconds(100)) {
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