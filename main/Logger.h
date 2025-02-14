#ifndef LOGGER_H
#define LOGGER_H

#include <Arduino.h>
#include "ILogger.h"

/**
 * @class Logger
 * @brief Implements logging functionality using Serial.
 *
 * Provides methods to initialize the logger, log messages at various levels,
 * and set the active logging level.
 */
class Logger : public ILogger {
public:
    /**
     * @brief Constructs a Logger instance with default logging level.
     */
    Logger();
    
    /**
     * @brief Initializes the logger and Serial communication.
     *
     * Configures Serial output and sets the logging level.
     * The logging level can be adjusted at runtime via setLevel().
     *
     * @param level The logging level to be set (default: LOG_DEBUG).
     */
    void begin(LogLevel level = LOG_DEBUG) override;
    
    /**
     * @brief Logs a message if the log level is at or above the current threshold.
     *
     * The log output includes a prefix indicating the log level.
     *
     * @param level The logging level of the message.
     * @param message The message to log.
     */
    void log(LogLevel level, const char* message) override;
    
    /**
     * @brief Sets the logger's logging level.
     *
     * Allows runtime adjustment of the verbosity of log output.
     *
     * @param level The new logging level.
     */
    void setLevel(LogLevel level) override;
    
private:
    LogLevel currentLevel;
};

#endif // LOGGER_H
