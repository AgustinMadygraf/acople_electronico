#include "DebugManager.h"

DebugManager::DebugManager(ILogger* serialLogger, ILogger* mqttLogger, DebugOutputMode mode)
    : serialLogger(serialLogger), mqttLogger(mqttLogger), outputMode(mode) {
    // ...existing initialization if any...
}

void DebugManager::begin(LogLevel level) {
    if(serialLogger) serialLogger->begin(level);
    if(mqttLogger) mqttLogger->begin(level);
}

void DebugManager::log(LogLevel level, const char* message) {
    if(outputMode == LOG_SERIAL || outputMode == LOG_BOTH) {
        if(serialLogger) serialLogger->log(level, message);
    }
    if((outputMode == LOG_MQTT || outputMode == LOG_BOTH) && mqttLogger) {
        mqttLogger->log(level, message);
    }
}

void DebugManager::setOutputMode(DebugOutputMode mode) {
    outputMode = mode;
}

void DebugManager::flushBuffer() {
    // Assuming flushBuffer() is implemented in the concrete logger classes.
    if(serialLogger) {
        // ...existing code or dynamic_cast if using polymorphism...
        serialLogger->flushBuffer();
    }
    if(mqttLogger) {
        mqttLogger->flushBuffer();
    }
}
