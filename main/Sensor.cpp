#include "Sensor.h"

Sensor::Sensor(int pin, int pulsesPerRevolution, float sampleTime)
    : pin(pin), pulsesPerRevolution(pulsesPerRevolution), sampleTime(sampleTime), pulseCount(0) {
    // Constructor: inicializa la configuración interna del sensor.
}

void Sensor::begin() {
    pinMode(pin, INPUT_PULLUP);
    // Configura el pin e integra la interrupción pasando la instancia actual.
    attachInterruptArg(digitalPinToInterrupt(pin), Sensor::isrHandler, this, RISING);
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

// ISR estática para manejar las interrupciones y delegar a countPulse().
void IRAM_ATTR Sensor::isrHandler(void *arg) {
    Sensor* sensor = static_cast<Sensor*>(arg);
    sensor->countPulse();
    // Nota: se evita realizar operaciones largas en la ISR.
}
