#include "Sensor.h"

Sensor::Sensor(int pin, int pulsesPerRevolution, float sampleTime)
    : pin(pin), pulsesPerRevolution(pulsesPerRevolution), sampleTime(sampleTime), pulseCount(0) {}

void Sensor::begin() {
    pinMode(pin, INPUT_PULLUP);
    // Use attachInterruptArg to pass 'this' as argument
    attachInterruptArg(digitalPinToInterrupt(pin), Sensor::isrHandler, this, RISING);
}

void Sensor::countPulse() {
    pulseCount++;
}

float Sensor::getRPM() {
    noInterrupts();
    unsigned long pulses = pulseCount;
    pulseCount = 0;
    interrupts();
    return (pulses * (60000.0 / sampleTime)) / pulsesPerRevolution;
}

// New static ISR handler implementation
void IRAM_ATTR Sensor::isrHandler(void *arg) {
    Sensor* sensor = static_cast<Sensor*>(arg);
    sensor->countPulse();
}
