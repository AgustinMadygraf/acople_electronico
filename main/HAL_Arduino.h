#ifndef HAL_ARDUINO_H
#define HAL_ARDUINO_H

#include "HAL.h"

class HAL_Arduino : public HAL {
public:
    void setupPWM(int pin, int frequency, int resolution) override;
    void writePWM(int pin, int value) override;
};

#endif // HAL_ARDUINO_H