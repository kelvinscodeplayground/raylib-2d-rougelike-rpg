#include "Timer.hpp"

namespace timing_utils {
bool Timer::isTimedOut()
{
    if (!started) return false;

    if (Clock::now() > timeoutPoint) return true;

    return false;
}

void Timer::reset()
{
    started = false;
}

void Timer::next()
{
    if (Clock::now() < timeoutPoint) return;

    timeoutPoint = Clock::now() + duration;
}

void Timer::countDown(const std::chrono::milliseconds duration)
{
    started = true;
    this->duration = duration;
    timeoutPoint = Clock::now() + this->duration;
}
}