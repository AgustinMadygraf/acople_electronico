#ifndef INTERRUPTMANAGER_H
#define INTERRUPTMANAGER_H

#include "Sensor.h"

class InterruptManager {
public:
    // Encapsulates interrupt handling for sensors.
    static void IRAM_ATTR handleInterrupt(void* arg);
    static void attachSensorInterrupt(int pin, Sensor* sensor, int mode = RISING);
};

#endif // INTERRUPTMANAGER_H
