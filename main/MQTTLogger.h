#ifndef MQTTLOGGER_H
#define MQTTLOGGER_H

#include "Logger.h" // For LogLevel

class MQTTLogger {
public:
    MQTTLogger(const char* broker, int port);
    void begin();
    void log(LogLevel level, const char* message);
private:
    const char* broker;
    int port;
    // ...existing members for MQTT client instance...
};

#endif // MQTTLOGGER_H
