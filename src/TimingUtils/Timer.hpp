#pragma once

#include <chrono>

namespace timing_utils {
class Timer
{
    using TimePoint = std::chrono::steady_clock::time_point;
    using Clock = std::chrono::steady_clock;

public:
    bool isTimedOut();
    void reset();
    void next();
    void countDown(const std::chrono::milliseconds duration);

private:
    bool started { false };
    TimePoint timeoutPoint { Clock::now() };
    std::chrono::milliseconds duration { 0 };
};
}