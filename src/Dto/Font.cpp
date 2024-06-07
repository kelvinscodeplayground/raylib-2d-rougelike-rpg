#include "Font.hpp"

namespace raylib::dto {
Font::Font() : Font { "assets/Fonts/PressStart2P-Regular.ttf" } { }

Font::Font(std::string_view path)
{
    _data = LoadFont(path.data());
}

Font::~Font()
{
    UnloadFont(_data);
}

::Font &Font::operator*()
{
    return _data;
}

::Font &Font::data()
{
    return _data;
}
}