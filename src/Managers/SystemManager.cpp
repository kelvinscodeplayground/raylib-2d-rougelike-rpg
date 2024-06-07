#include "SystemManager.hpp"

SystemManager &getInstance()
{
    static SystemManager instance;
    return instance;
};