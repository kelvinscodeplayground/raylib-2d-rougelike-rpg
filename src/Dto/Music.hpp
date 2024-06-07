#pragma once
#include <raylib.h>
#include <string>

namespace raylib::dto {
class Music
{
public:
    Music(std::string_view path);
    ::Music &operator*();

    void playMusicStream();
    void updateMusicStream();

    ~Music();

private:
    ::Music music;
};
}