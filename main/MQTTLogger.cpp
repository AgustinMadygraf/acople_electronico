#include "MQTTLogger.h"
#include <Arduino.h>

MQTTLogger::MQTTLogger(const char* broker, int port)
    : broker(broker), port(port), currentLevel(LOG_DEBUG) {
    // ...initialize MQTT client if using an MQTT library...
}

void MQTTLogger::begin(LogLevel level) {
    currentLevel = level;
    Serial.print("[MQTTLogger] Connecting to broker: ");
    Serial.print(broker);
    Serial.print(":");
    Serial.println(port);
    // ...actual MQTT connection logic...
}

void MQTTLogger::log(LogLevel level, const char* message) {
    if (level < currentLevel) return;
    // Simulación de publicación asíncrona vía MQTT.
    Serial.print("[MQTT] ");
    Serial.println(message);
}

void MQTTLogger::setLevel(LogLevel level) {
    currentLevel = level;
}
