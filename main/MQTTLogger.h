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
private:
    const char* broker;
    int port;
    // ...existing members for MQTT client instance...
    LogLevel currentLevel;
};

#endif // MQTTLOGGER_H
