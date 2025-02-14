#ifndef INTERRUPTMANAGER_H
#define INTERRUPTMANAGER_H

#include "Sensor.h"

class InterruptManager {
public:
    // Encapsulates interrupt handling for sensors.
    static void IRAM_ATTR handleInterrupt(void* arg);
};

#endif // INTERRUPTMANAGER_H
