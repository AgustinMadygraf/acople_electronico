#include "Logger.h"

/**
 * @brief Logger constructor initializing the default log level.
 */
Logger::Logger() : currentLevel(LOG_DEBUG) {
}

/**
 * @brief Initializes Serial communication and sets the log level.
 *
 * @param level The logging level to initialize.
 */
void Logger::begin(LogLevel level) {
    currentLevel = level;
    Serial.begin(115200); // Initialize Serial communication
    // The logger's level is configurable at runtime using setLevel().
}

/**
 * @brief Logs the message with corresponding log level prefix.
 *
 * Ignores messages with a lower level than currentLevel.
 *
 * @param level Log level of the message.
 * @param message The message to log.
 */
void Logger::log(LogLevel level, const char* message) {
    if (level < currentLevel) return;
    const char* levelStr = "";
    switch(level) {
        case LOG_DEBUG: levelStr = "DEBUG"; break;
        case LOG_INFO:  levelStr = "INFO";  break;
        case LOG_WARN:  levelStr = "WARN";  break;
        case LOG_ERROR: levelStr = "ERROR"; break;
    }
    Serial.print("[");
    Serial.print(levelStr);
    Serial.print("] ");
    Serial.println(message);
}

/**
 * @brief Updates the logger's current logging level.
 *
 * @param level The new logging level.
 */
void Logger::setLevel(LogLevel level) {
    currentLevel = level;
}
