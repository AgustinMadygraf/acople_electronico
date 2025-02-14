#include "HardwareManager.h"

HardwareManager::HardwareManager() {
    // ...existing code...
}

void HardwareManager::beginPWM() {
    const int pwmPin = 25; // PWM output pin.
    pinMode(pwmPin, OUTPUT);
    ledcSetup(0, 1000, 8);
    ledcAttachPin(pwmPin, 0);
}

void HardwareManager::writePWM(int value) {
    ledcWrite(0, value);
}
