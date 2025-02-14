#include "Logger.h"
#include "LogFormatter.h"

/**
 * @brief Helper function to convert LogLevel enum to its string representation.
 *
 * @param level The LogLevel value.
 * @return const char* The string representation of the log level.
 */
static const char* getLogLevelName(LogLevel level) {
    switch(level) {
        case LOG_DEBUG: return "DEBUG";
        case LOG_INFO:  return "INFO";
        case LOG_WARN:  return "WARN";
        case LOG_ERROR: return "ERROR";
        default:        return "UNKNOWN";
    }
}

/**
 * @brief Logger constructor initializing the default log level.
 */
Logger::Logger() : currentLevel(LOG_DEBUG), logBuffer("") {
}

/**
 * @brief Initializes Serial communication and sets the log level.
 *
 * Also outputs the configured logging level via Serial for confirmation.
 *
 * @param level The logging level to initialize.
 */
void Logger::begin(LogLevel level) {
    currentLevel = level;
    Serial.begin(115200); // Initialize Serial communication
    Serial.print("[Logger] Initializing with log level: ");
    Serial.println(getLogLevelName(currentLevel));
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
    // Use the shared formatter:
    String entry = LogFormatter::format(level, message);
    logBuffer += entry;
}

/**
 * @brief Updates the logger's current logging level.
 *
 * @param level The new logging level.
 */
void Logger::setLevel(LogLevel level) {
    currentLevel = level;
    Serial.print("[Logger] Log level updated to: ");
    Serial.println(getLogLevelName(currentLevel));
}

/**
 * @brief Flushes buffered log messages via Serial.
 */
void Logger::flushBuffer() {
    Serial.print(logBuffer);
    logBuffer = "";
}
