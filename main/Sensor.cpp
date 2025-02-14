#include "Sensor.h"
#include "InterruptManager.h" // New include

Sensor::Sensor(int pin, int pulsesPerRevolution, float sampleTime)
    : pin(pin), pulsesPerRevolution(pulsesPerRevolution), sampleTime(sampleTime), pulseCount(0) {
    // Constructor: inicializa la configuración interna del sensor.
}

void Sensor::begin() {
    pinMode(pin, INPUT_PULLUP);
    // Use InterruptManager's ISR instead of Sensor's own.
}

void Sensor::countPulse() {
    pulseCount++;
    // Aumenta el contador de pulsos. Este método se llama desde la ISR.
}

float Sensor::getRPM() {
    // Se desactivan las interrupciones para una lectura atómica del contador.
    noInterrupts();
    unsigned long pulses = pulseCount;
    pulseCount = 0; // Reinicia el contador luego de la lectura.
    interrupts();
    // Calcula RPM: (pulsos * factor de conversión) / pulsos por revolución.
    return (pulses * (60000.0 / sampleTime)) / pulsesPerRevolution;
}

// Removed Sensor::isrHandler
