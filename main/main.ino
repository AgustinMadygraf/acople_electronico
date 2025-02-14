#include "src/EncoderManager.h"

// Configuración de pines y constantes
const int encoderPrincipalPin = 34;
const int encoderSecundarioPin = 35;
const int pulsosPorRevolucion = 1024;
const float circunferencia = 370.0;

// Crear instancia del gestor de encoders
EncoderManager encoderManager(
    encoderPrincipalPin,
    encoderSecundarioPin,
    pulsosPorRevolucion,
    circunferencia
);

// Variables para la gestión del tiempo
unsigned long tiempoAnterior = 0;
const unsigned long intervalo = 1000;

void setup() {
    Serial.begin(115200);
    encoderManager.begin();
}

void loop() {
    unsigned long tiempoActual = millis();
    
    if (tiempoActual - tiempoAnterior >= intervalo) {
        tiempoAnterior = tiempoActual;
        
        long pulsosPrincipales, pulsosSecundarios;
        encoderManager.leerContadores(pulsosPrincipales, pulsosSecundarios);
        
        float rpm = encoderManager.calcularRPM(pulsosPrincipales);
        float diferencia_mm = encoderManager.calcularDiferenciaMM(pulsosSecundarios);
        
        Serial.print("Velocidad (RPM): ");
        Serial.print(rpm);
        Serial.print("    Diferencia de Posición (mm): ");
        Serial.println(diferencia_mm);
    }
}
