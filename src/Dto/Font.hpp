#pragma once
#include <raylib.h>
#include <string_view>

namespace raylib::dto {
class Font
{
public:
    Font();
    Font(std::string_view path);
    ~Font();

    ::Font &operator*();
    ::Font &data();

private:
    ::Font _data;
};
}