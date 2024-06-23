#include "Enemy.hpp"

#include <random>

#include "Managers/SystemManager.hpp"

using namespace std::chrono_literals;
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

    spriteTimer.countDown(150ms);
}

void Enemy::tick()
{
    if (spriteTimer.isTimedOut()) {
        frame = frame == 5 ? 0 : frame + 1;
        spriteTimer.next();
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