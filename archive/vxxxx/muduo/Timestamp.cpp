#include "Timestamp.hpp"

#include <ctime>

// #define BUFFER_SIZE 128
static const int BUFFER_SIZE = 128;

Timestamp::Timestamp() : microSecondsSinceEpoch_(0) {}

Timestamp::Timestamp(int64_t microSecondsSinceEpoch)
    : microSecondsSinceEpoch_(microSecondsSinceEpoch) {}

Timestamp Timestamp::now() { return Timestamp(time(NULL)); }

std::string Timestamp::toString() const {
    char buffer[BUFFER_SIZE] = {0};
    tm*  tm_time = localtime(&microSecondsSinceEpoch_);
    // 年-月-日 时：分：秒
    snprintf(
        buffer, BUFFER_SIZE, "%4d-%02d-%02d %02d:%02d:%02d", tm_time->tm_year + 1900,
        tm_time->tm_mon + 1, tm_time->tm_mday, tm_time->tm_hour, tm_time->tm_min, tm_time->tm_sec);

    return buffer;
}
