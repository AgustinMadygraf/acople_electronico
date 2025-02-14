#ifndef MQTTLOGGER_H
#define MQTTLOGGER_H

#include "Logger.h" // Para LogLevel
#include "ILogger.h"

class MQTTLogger : public ILogger {
public:
    MQTTLogger(const char* broker, int port);
    void begin(LogLevel level = LOG_DEBUG) override;
    void log(LogLevel level, const char* message) override;
    void setLevel(LogLevel level) override;
    // New method to flush buffered logs.
    void flushBuffer();
    
private:
    const char* broker;
    int port;
    // ...existing members for MQTT client instance...
    LogLevel currentLevel;
    // Buffer to accumulate log messages.
    String logBuffer;
};

#endif // MQTTLOGGER_H
