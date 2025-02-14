#include "EncoderManager.h"
#include <Arduino.h>

static volatile long _contadorPrincipal = 0;
static volatile long _contadorSecundario = 0;

EncoderManager::EncoderManager(int pinPrin, int pinSec, int ppr, float circ)
    : pinPrincipal(pinPrin), pinSecundario(pinSec), 
      pulsosPorRevolucion(ppr), circunferencia(circ),
      contadorPrincipal(&_contadorPrincipal), 
      contadorSecundario(&_contadorSecundario),
      ultimoContadorSecundario(0) {}

EncoderManager::~EncoderManager() {}

void EncoderManager::begin() {
    pinMode(pinPrincipal, INPUT_PULLUP);
    pinMode(pinSecundario, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(pinPrincipal), ISR_encoderPrincipal, RISING);
    attachInterrupt(digitalPinToInterrupt(pinSecundario), ISR_encoderSecundario, RISING);
}

float EncoderManager::calcularRPM(long pulsos) const {
    return (pulsos * 60.0) / pulsosPorRevolucion;
}

float EncoderManager::calcularDiferenciaMM(long diferenciaPulsos) const {
    return diferenciaPulsos * (circunferencia / pulsosPorRevolucion);
}

void EncoderManager::leerContadores(long& pulsosPrincipales, long& pulsosSecundarios) {
    noInterrupts();
    pulsosPrincipales = *contadorPrincipal;
    *contadorPrincipal = 0;
    pulsosSecundarios = *contadorSecundario;
    interrupts();
}

void EncoderManager::ISR_encoderPrincipal() {
    _contadorPrincipal++;
}

void EncoderManager::ISR_encoderSecundario() {
    _contadorSecundario++;
}
