#include "InterruptManager.h"

void IRAM_ATTR InterruptManager::handleInterrupt(void* arg) {
    Sensor* sensor = static_cast<Sensor*>(arg);
    sensor->countPulse();
}

void InterruptManager::attachSensorInterrupt(int pin, Sensor* sensor, int mode) {
    attachInterruptArg(digitalPinToInterrupt(pin), handleInterrupt, sensor, mode);
}
