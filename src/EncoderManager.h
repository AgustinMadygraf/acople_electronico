#ifndef ENCODER_MANAGER_H
#define ENCODER_MANAGER_H

#include <Arduino.h>

class EncoderManager {
private:
    const int pulsosPorRevolucion;
    const float circunferencia;
    const int pinPrincipal;
    const int pinSecundario;
    volatile long* contadorPrincipal;
    volatile long* contadorSecundario;
    long ultimoContadorSecundario;

    // Declare ISR functions as static and private
    static void IRAM_ATTR ISR_encoderPrincipal();
    static void IRAM_ATTR ISR_encoderSecundario();

public:
    EncoderManager(int pinPrin, int pinSec, int ppr, float circ);
    ~EncoderManager();
    
    void begin();
    float calcularRPM(long pulsos) const;
    float calcularDiferenciaMM(long diferenciaPulsos) const;
    void leerContadores(long& pulsosPrincipales, long& pulsosSecundarios);
};

#endif
