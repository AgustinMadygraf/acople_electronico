#include "HAL.h"
#include <Arduino.h>

/**
 * @class HAL_ESP32
 * @brief HAL implementation for ESP32.
 *
 * Uses ledcSetup, ledcAttachPin, and ledcWrite for PWM control.
 */
class HAL_ESP32 : public HAL {
public:
    void setupPWM(int pin, int frequency, int resolution) override {
        int channel = 0; // Simplified: using channel 0
        ledcSetup(channel, frequency, resolution);
        ledcAttachPin(pin, channel);
    }
    
    void writePWM(int pin, int value) override {
        int channel = 0; // Using the same channel
        ledcWrite(channel, value);
    }
};

#ifdef ESP32_PLATFORM
HAL* createHAL() {
    static HAL_ESP32 instance;
    return &instance;
}
#endif // ESP32_PLATFORM
