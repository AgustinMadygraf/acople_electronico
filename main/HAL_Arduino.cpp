#include "HAL.h"
#include <Arduino.h>

/**
 * @class HAL_Arduino
 * @brief HAL implementation for Arduino Uno.
 *
 * Uses analogWrite for PWM control. Frequency and resolution settings are ignored.
 */
class HAL_Arduino : public HAL {
public:
    void setupPWM(int pin, int frequency, int resolution) override {
        pinMode(pin, OUTPUT);
        // Arduino Uno does not support dynamic frequency/resolution adjustments.
    }
    
    void writePWM(int pin, int value) override {
        analogWrite(pin, value);
    }
};
