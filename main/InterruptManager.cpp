#include "InterruptManager.h"

void IRAM_ATTR InterruptManager::handleInterrupt(void* arg) {
    Sensor* sensor = static_cast<Sensor*>(arg);
    sensor->countPulse();
}
