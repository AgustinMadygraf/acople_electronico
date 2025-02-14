#ifndef LOGGER_H
#define LOGGER_H

#include <Arduino.h>

/**
 * @enum LogLevel
 * @brief Representa los niveles de logging.
 */
enum LogLevel {
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR
};

#include "ILogger.h"

class Logger : public ILogger {
public:
    Logger();
    void begin(LogLevel level = LOG_DEBUG) override;
    void log(LogLevel level, const char* message) override;
    void setLevel(LogLevel level) override;
private:
    LogLevel currentLevel;
};

#endif // LOGGER_H
