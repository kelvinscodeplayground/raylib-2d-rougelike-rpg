#include "Music.hpp"

namespace raylib::dto {
Music::Music(std::string_view path)
{
    music = LoadMusicStream(path.data());
}

void Music::playMusicStream()
{
    PlayMusicStream(music);
}

void Music::updateMusicStream()
{
    UpdateMusicStream(music);
}

::Music &Music::operator*()
{
    return music;
}

Music::~Music()
{
    UnloadMusicStream(music);
}
}