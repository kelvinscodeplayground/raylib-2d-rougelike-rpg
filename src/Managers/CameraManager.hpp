#pragma once
#include <raylib-cpp.hpp>

namespace managers {
class CameraManager
{
public:
    CameraManager();
    CameraManager(const CameraManager &) = delete;
    CameraManager &operator=(const CameraManager &) = delete;

    static CameraManager &getInstance();

    raylib::Camera2D &getWorldCamera();

    void centerWorldCamera();

    ~CameraManager() = default;

private:
    raylib::Camera2D worldCamera;
};
}