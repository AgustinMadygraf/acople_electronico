#ifndef ENCODER_MANAGER_H
#define ENCODER_MANAGER_H

class EncoderManager {
private:
    const int pulsosPorRevolucion;
    const float circunferencia;
    const int pinPrincipal;
    const int pinSecundario;
    volatile long* contadorPrincipal;
    volatile long* contadorSecundario;
    long ultimoContadorSecundario;

public:
    EncoderManager(int pinPrin, int pinSec, int ppr, float circ);
    ~EncoderManager();
    
    void begin();
    float calcularRPM(long pulsos) const;
    float calcularDiferenciaMM(long diferenciaPulsos) const;
    void leerContadores(long& pulsosPrincipales, long& pulsosSecundarios);
    
    static void ISR_encoderPrincipal();
    static void ISR_encoderSecundario();
};

#endif
