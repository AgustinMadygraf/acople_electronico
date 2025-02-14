#include "HAL.h"
#include "HAL_Arduino.h"
#include "HAL_ESP32.h"

HAL* createHAL(PlatformType platform) {
    static HAL_Arduino instanceArduino;
    static HAL_ESP32 instanceESP32;
    switch (platform) {
        case PLATFORM_ARDUINO:
            return &instanceArduino;
        case PLATFORM_ESP32:
            return &instanceESP32;
        default:
            return &instanceArduino;
    }
}