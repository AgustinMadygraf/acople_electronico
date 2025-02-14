#ifndef IENCODER_H
#define IENCODER_H

class IEncoder {
public:
    virtual ~IEncoder() {}

    // Inicializa el sensor
    virtual void begin() = 0;

    // Lee los contadores del encoder
    virtual void leerContadores(long& pulsosPrincipales, long& pulsosSecundarios) = 0;

    // Calcula la velocidad en RPM a partir de los pulsos
    virtual float calcularRPM(long pulsos) const = 0;

    // Calcula la diferencia de posición en mm a partir de los pulsos
    virtual float calcularDiferenciaMM(long diferenciaPulsos) const = 0;
};

#endif // IENCODER_H
