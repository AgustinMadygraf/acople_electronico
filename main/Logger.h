#ifndef LOGGER_H
#define LOGGER_H

#include <Arduino.h>

/**
 * @enum LogLevel
 * @brief Represents the logging verbosity level.
 */
enum LogLevel {
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR
};

/**
 * @class Logger
 * @brief Provides static methods to perform logging.
 * 
 * This class handles initialization and logging messages with different levels.
 */
class Logger {
public:
    /**
     * @brief Initializes the Logger.
     * 
     * @param level Minimum log level to display.
     */
    static void begin(LogLevel level = LOG_DEBUG);
    
    /**
     * @brief Logs a message if the log level is sufficient.
     * 
     * @param level Level of the message.
     * @param message The message to log.
     */
    static void log(LogLevel level, const char* message);
    
    /**
     * @brief Sets the minimum log level.
     * 
     * @param level New log level
     */
    static void setLevel(LogLevel level);
    
private:
    static LogLevel currentLevel;
};

#endif // LOGGER_H
