#pragma once
#include <array>

#include <raylib-cpp.hpp>

namespace consts {
namespace tiles {
constexpr int tileSize { 32 };

// clang-format off
const std::array<raylib::Rectangle, 3> hardWalls {{
    raylib::Rectangle { 1 * tileSize, 3 * tileSize, tileSize, tileSize },
    raylib::Rectangle { 2 * tileSize, 3 * tileSize, tileSize, tileSize },
    raylib::Rectangle { 4 * tileSize, 3 * tileSize, tileSize, tileSize }
}};
const std::array<raylib::Rectangle, 8> walls {{
    raylib::Rectangle { 5 * tileSize, 2 * tileSize, tileSize, tileSize },
    raylib::Rectangle { 6 * tileSize, 2 * tileSize, tileSize, tileSize },
    raylib::Rectangle { 7 * tileSize, 2 * tileSize, tileSize, tileSize },
    raylib::Rectangle { 0, 3 * tileSize, tileSize, tileSize },
    raylib::Rectangle { 3 * tileSize, 3 * tileSize, tileSize, tileSize },
    raylib::Rectangle { 5 * tileSize, 3 * tileSize, tileSize, tileSize },
    raylib::Rectangle { 6 * tileSize, 3 * tileSize, tileSize, tileSize },
    raylib::Rectangle { 7 * tileSize, 3 * tileSize, tileSize, tileSize }
}};
const std::array<raylib::Rectangle, 8> floors {{
    { 0, 4 * tileSize, tileSize, tileSize },
    { 1 * tileSize, 4 * tileSize, tileSize, tileSize },
    { 2 * tileSize, 4 * tileSize, tileSize, tileSize },
    { 3 * tileSize, 4 * tileSize, tileSize, tileSize },
    { 4 * tileSize, 4 * tileSize, tileSize, tileSize },
    { 5 * tileSize, 4 * tileSize, tileSize, tileSize },
    { 6 * tileSize, 4 * tileSize, tileSize, tileSize },
    { 7 * tileSize, 4 * tileSize, tileSize, tileSize }
}};
// clang-format on

const raylib::Rectangle exit { 4 * tileSize, 2 * tileSize, tileSize, tileSize };
const raylib::Rectangle food { 3 * tileSize, 2 * tileSize };
const raylib::Rectangle soda { 2 * tileSize, 3 * tileSize };

// clang-format off
namespace player {
    const std::array<raylib::Rectangle, 6> idle {{
        { 0, 0, tileSize, tileSize },
        { 1 * tileSize, 0, tileSize, tileSize },
        { 2 * tileSize, 0, tileSize, tileSize },
        { 3 * tileSize, 0, tileSize, tileSize },
        { 4 * tileSize, 0, tileSize, tileSize },
        { 5 * tileSize, 0, tileSize, tileSize }
    }};
    const std::array<raylib::Rectangle, 2> chop {{
        { 0, 5 * tileSize, tileSize, tileSize },
        { 1 * tileSize, 5 * tileSize, tileSize, tileSize }
    }};
    const std::array<raylib::Rectangle, 2> damaged {{
        { 6 * tileSize, 5 * tileSize, tileSize, tileSize },
        { 7 * tileSize, 5 * tileSize, tileSize, tileSize }
    }};
}
// clang-format on
}
}