#pragma once
#include <string_view>

#include <raylib.h>

namespace raylib::dto {
class Image
{
public:
    Image(std::string_view path);

    ::Image &operator*();
    ~Image();

private:
    ::Image image;
};
}