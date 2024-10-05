#ifndef RATE_LIMITED_FUNCTION_HPP
#define RATE_LIMITED_FUNCTION_HPP

#include <functional>
#include <chrono>

class RateLimitedFunction {
public:
    RateLimitedFunction(int rate_limit_hz, std::function<void()> func);
    bool attempt_to_run();
private:
    std::chrono::milliseconds rate_limit_duration;
    std::chrono::steady_clock::time_point last_execution_time;
    std::function<void()> function;
};

#endif // RATE_LIMITED_FUNCTION_HPP
