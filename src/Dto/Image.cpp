#include "Image.hpp"

namespace raylib::dto {
Image::Image(std::string_view path)
{
    image = LoadImage(path.data());
}

Image::~Image()
{
    UnloadImage(image);
}

::Image &Image::operator*()
{
    return image;
}
}