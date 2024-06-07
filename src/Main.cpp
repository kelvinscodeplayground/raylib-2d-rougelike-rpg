#include <iostream>
#include <raylib.h>
#include <memory>
#include <filesystem>

#include "Dto/Music.hpp"

struct Window
{
    Window()
    {
        InitWindow(Window::WindowWidth, Window::WindowHeight, "2D Rouge Like");
        SetTargetFPS(60);
        InitAudioDevice();
    }

    ~Window()
    {
        CloseWindow();
        CloseAudioDevice();
    }

    static constexpr int WindowHeight { 480 };
    static constexpr int WindowWidth { 640 };
};

struct Painter
{
    Painter() { BeginDrawing(); }
    ~Painter() { EndDrawing(); }
};

int main(int argc, char **argv)
{
    Window window;

    raylib::dto::Music bgm { "assets/Audio/scavengers_music.aif.wav" };
    bgm.playMusicStream();

    while (!WindowShouldClose()) {
        bgm.updateMusicStream();
        Painter painter;

        ClearBackground({ 255, 255, 255, 255 });
        DrawText("Hello World", 15, 15, 32, { 0, 0, 0, 255 });
    }

    return 0;
}