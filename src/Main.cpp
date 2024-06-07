#include <raylib.h>
#include <memory>
#include <functional>

#include "Dto/Font.hpp"
#include "Dto/Image.hpp"
#include "Dto/Music.hpp"

static constexpr int WindowHeight { 480 };
static constexpr int WindowWidth { 640 };

int main()
{
    InitWindow(WindowWidth, WindowHeight, "2D Rouge Like");
    SetTargetFPS(60);
    InitAudioDevice();
    auto windowHandler =
            std::unique_ptr<uint8_t, std::function<void(uint8_t *)>>(new uint8_t, [](uint8_t *ptr) {
                delete ptr;
                CloseWindow();
                CloseAudioDevice();
            });

    raylib::dto::Image icon { "assets/raylib_256x256.png" };
    SetWindowIcon(*icon);

    raylib::dto::Font font;

    raylib::dto::Music bgm { "assets/Audio/scavengers_music.aif.wav" };
    bgm.playMusicStream();

    while (!WindowShouldClose()) {
        bgm.updateMusicStream();

        BeginDrawing();
        auto painter = std::unique_ptr<uint8_t, std::function<void(uint8_t *)>> { new uint8_t,
            [](uint8_t *ptr) {
                delete ptr;
                EndDrawing();
            } };

        ClearBackground({ 255, 255, 255, 255 });
        // DrawText("Hello World", 15, 15, 32, { 0, 0, 0, 255 });
        DrawTextEx(font.data(), "Hello World", { 15, 15 }, 32, 0, { 0, 0, 0, 255 });
    }

    return 0;
}