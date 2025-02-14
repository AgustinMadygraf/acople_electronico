#include "MQTTLogger.h"
#include <Arduino.h>

MQTTLogger::MQTTLogger(const char* broker, int port)
    : broker(broker), port(port), currentLevel(LOG_DEBUG), logBuffer("") {
    // ...initialize MQTT client if using an MQTT library...
}

void MQTTLogger::begin(LogLevel level) {
    currentLevel = level;
    Serial.print("[MQTTLogger] Connecting to broker: ");
    Serial.print(broker);
    Serial.print(":");
    Serial.println(port);
    // The logging level can be adjusted at runtime via setLevel().
    // ...actual MQTT connection logic...
}

void MQTTLogger::log(LogLevel level, const char* message) {
    if (level < currentLevel) return;
    unsigned long ts = millis();
    // Append log message with timestamp to the buffer.
    logBuffer += "[";
    logBuffer += String(ts);
    logBuffer += "] ";
    logBuffer += message;
    logBuffer += "\n";
    // Simulated asynchronous MQTT publication:
    Serial.print("[MQTT] ");
    Serial.println(message);
}

void MQTTLogger::setLevel(LogLevel level) {
    currentLevel = level;
}

void MQTTLogger::flushBuffer() {
    // Simulate flushing buffered log messages (e.g., publishing via MQTT).
    Serial.print("[MQTTLogger] Flushing log buffer:\n");
    Serial.print(logBuffer);
    logBuffer = "";
}
