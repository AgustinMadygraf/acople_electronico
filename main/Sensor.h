#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

class Sensor {
public:
    Sensor(int pin, int pulsesPerRevolution, float sampleTime);
    void begin();
    void countPulse();
    float getRPM();

    // New static ISR handler declaration
    static void IRAM_ATTR isrHandler(void *arg);

private:
    int pin;
    int pulsesPerRevolution;
    float sampleTime;
    volatile unsigned long pulseCount;
};

#endif // SENSOR_H
