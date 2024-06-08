#include <format>

#include <raylib-cpp.hpp>
#include <scope_guard.hpp>

static constexpr int WindowHeight { 480 };
static constexpr int WindowWidth { 640 };

int main()
{
    raylib::Window window { WindowWidth, WindowHeight, "2D Rouge Like" };
    raylib::AudioDevice audio;
    raylib::Image icon { "assets/raylib_256x256.png" };
    raylib::Font font { "assets/Fonts/PressStart2P-Regular.ttf" };

    window.SetTargetFPS(60);
    window.SetIcon(icon);

    raylib::Music bgm { "assets/Audio/scavengers_music.aif.wav" };
    bgm.Play();

    while (!window.ShouldClose()) {
        bgm.Update();

        window.BeginDrawing();
        auto painterGuard = sg::make_scope_guard([&]() { window.EndDrawing(); });

        window.ClearBackground({ 255, 255, 255, 255 });
        raylib::Color::Black().DrawText(font, "Hello World", { 15, 15 }, 32, 1);
        raylib::Color::Black().DrawText(font,
                std::format("Window size is {}x{}", WindowWidth, WindowHeight), { 15, 15 + 32 }, 16,
                1);
    }

    return 0;
}