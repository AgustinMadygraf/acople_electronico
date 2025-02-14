/**
 * @file main.ino
 * @brief Main program to manage sensor readings, PID control, and logging.
 * 
 * This file initializes sensors, a PID controller, and uses a Logger to output debug information.
 */

#include <Arduino.h>
#include "Sensor.h"
#include "PIDController.h"
#include "Logger.h" // added Logger include

// Definición de pines
const int sensorMaestroPin = 34;  // Sensor inductivo maestro
const int sensorEsclavoPin = 35;  // Sensor inductivo esclavo
const int pwmEsclavoPin = 25;     // Salida PWM para el motor esclavo

// Parámetros del sistema
const int pulsosPorVuelta = 10;  // Ajustar según el sensor inductivo
const float tiempoMuestreo = 100.0; // Tiempo de muestreo en ms

// Variables de velocidad
unsigned long tiempoAnterior = 0;

// Instancias de sensores y PIDController
Sensor sensorMaestro(sensorMaestroPin, pulsosPorVuelta, tiempoMuestreo);
Sensor sensorEsclavo(sensorEsclavoPin, pulsosPorVuelta, tiempoMuestreo);
PIDController pid(2.0, 0.5, 0.1, tiempoMuestreo); // nuevo objeto PID

void setup() {
    // Inicializa Logger para depuración
    Logger::begin(LOG_DEBUG);
    
    sensorMaestro.begin();
    sensorEsclavo.begin();
    pinMode(pwmEsclavoPin, OUTPUT);

    ledcSetup(0, 1000, 8);  // Configuración del PWM (Canal 0, 1 kHz, 8 bits)
    ledcAttachPin(pwmEsclavoPin, 0);
}

void loop() {
    unsigned long tiempoActual = millis();
    
    if (tiempoActual - tiempoAnterior >= tiempoMuestreo) {
        tiempoAnterior = tiempoActual;

        // Calcular velocidades en RPM
        float rpmMaestro = sensorMaestro.getRPM();
        float rpmEsclavo = sensorEsclavo.getRPM();

        // Calcular el control PID usando la nueva clase
        int pwmSalida = pid.compute(rpmMaestro, rpmEsclavo);

        // Aplicar PWM al motor esclavo
        ledcWrite(0, pwmSalida);

        // Crear mensaje de log y enviarlo
        char logMsg[128];
        sprintf(logMsg, "RPM Maestro: %.2f | RPM Esclavo: %.2f | PWM Esclavo: %d", rpmMaestro, rpmEsclavo, pwmSalida);
        Logger::log(LOG_INFO, logMsg);
    }
}
