#ifndef HARDWAREMANAGER_H
#define HARDWAREMANAGER_H

#include <Arduino.h>

class HardwareManager {
public:
    HardwareManager(int pwmPin);    
    void beginPWM();     // Configures PWM hardware.
    void writePWM(int value); // Writes PWM output.

private:
    int pin;
};

#endif // HARDWAREMANAGER_H
