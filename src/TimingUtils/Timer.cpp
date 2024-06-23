#include "Timer.hpp"

using namespace std::chrono_literals;
using std::chrono::duration_cast;

namespace timing_utils {
bool Timer::isTimedOut()
{
    if (!started) return false;

    if (Clock::now() > timeoutPoint) return true;

    return false;
}

std::chrono::milliseconds Timer::delta()
{
    if (!isTimedOut()) return 0ms;

    return duration_cast<std::chrono::milliseconds>(Clock::now() - timeoutPoint);
}

long long Timer::deltaRatio()
{
    return delta() / duration;
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