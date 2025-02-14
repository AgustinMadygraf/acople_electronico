#ifndef ILOGGER_H
#define ILOGGER_H

#include "LogLevel.h"

/**
 * @interface ILogger
 * @brief Interface for logging implementations.
 */
class ILogger {
public:
    virtual void begin(LogLevel level = LOG_DEBUG) = 0;
    virtual void log(LogLevel level, const char* message) = 0;
    virtual void setLevel(LogLevel level) = 0;
    virtual ~ILogger() {}
};

#endif // ILOGGER_H
