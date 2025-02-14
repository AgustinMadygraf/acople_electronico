#include "HardwareManager.h"

HardwareManager::HardwareManager(int pwmPin) : pin(pwmPin) {
    // ...constructor logic...
}

void HardwareManager::beginPWM() {
    pinMode(pin, OUTPUT);
    ledcSetup(0, 1000, 8);
    ledcAttachPin(pin, 0);
}

void HardwareManager::writePWM(int value) {
    ledcWrite(0, value);
}
