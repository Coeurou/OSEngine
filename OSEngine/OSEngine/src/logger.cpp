#include <fmt/chrono.h>
#include <logger.h>

#include <chrono>
#include <nameof.hpp>

namespace ose {

string to_string(const syslog &log) {
    return format("{} | {} | {} | {} ", get_formatted_date(), NAMEOF_ENUM(log.my_category),
                  NAMEOF_ENUM(log.my_severity), log.my_msg);
}

string get_formatted_date() {
    using namespace std::chrono;
    system_clock::time_point now = system_clock::now();
    system_clock::duration fraction = now.time_since_epoch();
    fraction -= duration_cast<seconds>(fraction);

    time_t timer = system_clock::to_time_t(now);
    std::tm tm_info;
#ifdef __APPLE__
    localtime_r(&timer, &tm_info);
#else
    localtime_s(&tm_info, &timer);
#endif
    return format("{:%Y-%m-%d %H:%M:%S}.{:#03d}", tm_info, static_cast<u32>(fraction / milliseconds(1)));
}

}  // namespace ose