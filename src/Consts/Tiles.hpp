#pragma once
#include <array>

#include <raylib-cpp.hpp>

namespace consts {
namespace tiles {
constexpr int tileSize { 32 };

// clang-format off
const std::array<raylib::Rectangle, 2> hardWalls {{
    raylib::Rectangle { 1 * tileSize, 3 * tileSize, tileSize, tileSize },
    raylib::Rectangle { 2 * tileSize, 3 * tileSize, tileSize, tileSize }
}};
// clang-format on

const raylib::Rectangle exit { 4 * tileSize, 2 * tileSize, tileSize, tileSize };
}
}