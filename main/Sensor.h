#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

/**
 * @class Sensor
 * @brief Reads sensor pulses and calculates RPM.
 *
 * The Sensor class encapsulates the functionality needed to count pulses,
 * attach interrupts, and compute revolutions per minute (RPM) based on the pulses.
 */
class Sensor {
public:
    /**
     * @brief Constructs a sensor with the specified settings.
     *
     * @param pin Digital pin connected to the sensor.
     * @param pulsesPerRevolution Number of pulses per one revolution.
     * @param sampleTime Sampling time in milliseconds.
     */
    Sensor(int pin, int pulsesPerRevolution, float sampleTime);
    
    /**
     * @brief Initializes the sensor pin and attaches interrupt.
     */
    void begin();
    
    /**
     * @brief Increments the pulse count.
     */
    void countPulse();
    
    /**
     * @brief Calculates and returns the RPM.
     *
     * Resets the internal pulse count.
     *
     * @return float The computed RPM.
     */
    float getRPM();

    /**
     * @brief Static ISR handler for interrupt processing.
     *
     * Attaches to the sensor pin interrupt and casts the argument to a Sensor instance.
     * Calls countPulse() to update the internal pulse count.
     *
     * @param arg Pointer to the Sensor instance.
     */
    static void IRAM_ATTR isrHandler(void *arg);

private:
    int pin;
    int pulsesPerRevolution;
    float sampleTime;
    volatile unsigned long pulseCount;
};

#endif // SENSOR_H
