#ifndef HARDWAREMANAGER_H
#define HARDWAREMANAGER_H

#include <Arduino.h>

class HardwareManager {
public:
    HardwareManager();    
    void beginPWM();     // Configures PWM hardware.
    void writePWM(int value); // Writes PWM output.
};

#endif // HARDWAREMANAGER_H
