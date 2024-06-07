#include <memory>
#include <functional>

#include <raylib-cpp.hpp>

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

    // raylib::dto::Music bgm { "assets/Audio/scavengers_music.aif.wav" };
    // bgm.playMusicStream();
    raylib::Music bgm { "assets/Audio/scavengers_music.aif.wav" };
    bgm.Play();

    while (!window.ShouldClose()) {
        bgm.Update();

        window.BeginDrawing();
        auto painter = std::unique_ptr<uint8_t, std::function<void(uint8_t *)>> { new uint8_t,
            [&window](uint8_t *ptr) {
                delete ptr;
                window.EndDrawing();
            } };

        window.ClearBackground({ 255, 255, 255, 255 });
        // DrawText("Hello World", 15, 15, 32, { 0, 0, 0, 255 });
        raylib::Color::Black().DrawText(font, "Hello World", { 15, 15 }, 32, 1);
    }

    return 0;
}