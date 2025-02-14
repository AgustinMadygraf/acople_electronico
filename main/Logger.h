#ifndef LOGGER_H
#define LOGGER_H

#include <Arduino.h>
#include "ILogger.h"

/**
 * @class Logger
 * @brief Implements logging functionality using Serial.
 *
 * Provides methods to initialize the logger, log messages at various levels,
 * and set the active logging level. The logging level is configurable through
 * the begin() method.
 */
class Logger : public ILogger {
public:
    /**
     * @brief Constructs a Logger instance with default logging level.
     */
    Logger();
    
    /**
     * @brief Initializes Serial communication and sets the logging level.
     *
     * Configures Serial output and sets the logging level. The level can be adjusted
     * at startup by passing the desired LogLevel.
     *
     * @param level The logging level to be set (default: LOG_DEBUG).
     */
    void begin(LogLevel level = LOG_DEBUG) override;
    
    /**
     * @brief Logs a message with corresponding log level prefix.
     *
     * Ignores messages with a lower level than currentLevel.
     *
     * @param level Log level of the message.
     * @param message The message to log.
     */
    void log(LogLevel level, const char* message) override;
    
    /**
     * @brief Updates the logger's current logging level.
     *
     * Allows runtime adjustment of the verbosity of log output.
     *
     * @param level The new logging level.
     */
    void setLevel(LogLevel level) override;
    
    /**
     * @brief Flushes the buffered log messages.
     *
     * Prints and clears the accumulated log messages.
     */
    void flushBuffer();
    
private:
    LogLevel currentLevel;
    // Buffer to accumulate log messages with timestamps.
    String logBuffer;
};

#endif // LOGGER_H
