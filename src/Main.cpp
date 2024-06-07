#include <iostream>
#include <raylib.h>
#include <memory>
#include <filesystem>
#include <functional>

#include "Dto/Music.hpp"

static constexpr int WindowHeight { 480 };
static constexpr int WindowWidth { 640 };

int main(int argc, char **argv)
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
        DrawText("Hello World", 15, 15, 32, { 0, 0, 0, 255 });
    }

    return 0;
}