#ifndef HAL_ESP32_H
#define HAL_ESP32_H

#include "HAL.h"

class HAL_ESP32 : public HAL {
public:
    void setupPWM(int pin, int frequency, int resolution) override;
    void writePWM(int pin, int value) override;
};

#endif // HAL_ESP32_H