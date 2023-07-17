#include "Logger.hpp"

#include <iostream>

#include "Timestamp.hpp"

Logger& Logger::instance() {
    static Logger logger;
    return logger;
}

void Logger::setLogLevel(logLevel level) { logLevel_ = level; }

void Logger::log(std::string msg) {

    // 打印日志级别
    switch (logLevel_) {
        case INFO: {
            std::cout << "[INFO]";
            break;
        }
        case ERROR: {
            std::cout << "[ERROR]";
            break;
        }
        case FATAL: {
            std::cout << "[FATAL]";
            break;
        }
        case DEBUG: {
            std::cout << "[DEBUG]";
            break;
        }
        default:
            break;
    }

    // 打印时间和 msg
    std::cout << Timestamp::now().toString() << " : " << msg << std::endl;
}