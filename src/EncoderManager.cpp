#include "EncoderManager.h"

// Static member variables
static volatile long _contadorPrincipal = 0;
static volatile long _contadorSecundario = 0;

// ISR implementations - Note the IRAM_ATTR is in the header only
void EncoderManager::ISR_encoderPrincipal() {
    _contadorPrincipal++;
}

void EncoderManager::ISR_encoderSecundario() {
    _contadorSecundario++;
}

// Constructor and other methods
EncoderManager::EncoderManager(int pinPrin, int pinSec, int ppr, float circ)
    : pinPrincipal(pinPrin), pinSecundario(pinSec), 
      pulsosPorRevolucion(ppr), circunferencia(circ),
      contadorPrincipal(&_contadorPrincipal), 
      contadorSecundario(&_contadorSecundario),
      ultimoContadorSecundario(0) {}

// ...existing code for other methods...
