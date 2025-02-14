#include "Logger.h"

LogLevel Logger::currentLevel = LOG_DEBUG;

void Logger::begin(LogLevel level) {
    currentLevel = level;
    Serial.begin(115200);
}

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

void Logger::setLevel(LogLevel level) {
    currentLevel = level;
}
