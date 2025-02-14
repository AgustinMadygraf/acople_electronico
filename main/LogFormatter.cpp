#include "LogFormatter.h"

// ...existing code for optional includes...

static const char* getLogLevelName(LogLevel level) {
    // ...reused from Logger...
    switch(level) {
        case LOG_DEBUG: return "DEBUG";
        case LOG_INFO:  return "INFO";
        case LOG_WARN:  return "WARN";
        case LOG_ERROR: return "ERROR";
        default:        return "UNKNOWN";
    }
}

String LogFormatter::format(LogLevel level, const char* message) {
    unsigned long ts = millis();
    String result = "[";
    result += String(ts);
    result += "] [";
    result += getLogLevelName(level);
    result += "] ";
    result += message;
    result += "\n";
    return result;
}
