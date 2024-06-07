#pragma once

class SystemManager
{
public:
    SystemManager() = default;
    SystemManager(const SystemManager &) = delete;
    SystemManager &operator=(const SystemManager &) = delete;

    static SystemManager &getInstance();
};