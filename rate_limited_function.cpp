#include "rate_limited_function.hpp"

RateLimitedFunction::RateLimitedFunction(int rate_limit_hz, std::function<void()> func)
    : rate_limit_duration(std::chrono::milliseconds(1000 / rate_limit_hz)), function(func) {
    last_execution_time = std::chrono::steady_clock::now() - rate_limit_duration;
}

bool RateLimitedFunction::attempt_to_run() {
    auto now = std::chrono::steady_clock::now();
    if (now - last_execution_time >= rate_limit_duration) {
        function();
        last_execution_time = now;
        return true;
    } else {
        return false;
    }
}
