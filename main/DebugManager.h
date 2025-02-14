#ifndef DEBUGMANAGER_H
#define DEBUGMANAGER_H

#include "ILogger.h"
#include "LogLevel.h"

enum DebugOutputMode {
    LOG_SERIAL,
    LOG_MQTT,
    LOG_BOTH
};

class DebugManager {
public:
    DebugManager(ILogger* serialLogger, ILogger* mqttLogger, DebugOutputMode mode = LOG_SERIAL);
    void begin(LogLevel level);
    void log(LogLevel level, const char* message);
    void setOutputMode(DebugOutputMode mode);
    void flushBuffer();
private:
    ILogger* serialLogger;
    ILogger* mqttLogger;
    DebugOutputMode outputMode;
};

#endif // DEBUGMANAGER_H
