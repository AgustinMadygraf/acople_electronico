#include <Arduino.h>

// Definición de pines
const int sensorMaestroPin = 34;  // Sensor inductivo maestro
const int sensorEsclavoPin = 35;  // Sensor inductivo esclavo
const int pwmEsclavoPin = 25;     // Salida PWM para el motor esclavo

// Parámetros del sistema
const int pulsosPorVuelta = 10;  // Ajustar según el sensor inductivo
const float tiempoMuestreo = 100.0; // Tiempo de muestreo en ms

// Variables de velocidad
volatile unsigned long contadorMaestro = 0;
volatile unsigned long contadorEsclavo = 0;
unsigned long tiempoAnterior = 0;

// Variables PID
float Kp = 2.0, Ki = 0.5, Kd = 0.1; // Ajustar según necesidades
float errorPrevio = 0, errorIntegral = 0;
int pwmSalida = 0;

// ISR para contar pulsos de los sensores
void IRAM_ATTR contarPulsosMaestro() {
    contadorMaestro++;
}

void IRAM_ATTR contarPulsosEsclavo() {
    contadorEsclavo++;
}

// Función para calcular la velocidad en RPM
float calcularRPM(unsigned long pulsos) {
    return (pulsos * (60000.0 / tiempoMuestreo)) / pulsosPorVuelta;
}

// Control PID para ajustar el PWM del motor esclavo
int calcularPID(float setpoint, float medicion) {
    float error = setpoint - medicion;
    errorIntegral += error * (tiempoMuestreo / 1000.0);
    float errorDerivativo = (error - errorPrevio) / (tiempoMuestreo / 1000.0);

    int salida = Kp * error + Ki * errorIntegral + Kd * errorDerivativo;
    salida = constrain(salida, 0, 255); // Limitar entre 0 y 255

    errorPrevio = error;
    return salida;
}

void setup() {
    Serial.begin(115200);
    
    pinMode(sensorMaestroPin, INPUT_PULLUP);
    pinMode(sensorEsclavoPin, INPUT_PULLUP);
    pinMode(pwmEsclavoPin, OUTPUT);

    attachInterrupt(digitalPinToInterrupt(sensorMaestroPin), contarPulsosMaestro, RISING);
    attachInterrupt(digitalPinToInterrupt(sensorEsclavoPin), contarPulsosEsclavo, RISING);

    ledcSetup(0, 1000, 8);  // Configuración del PWM (Canal 0, 1 kHz, 8 bits)
    ledcAttachPin(pwmEsclavoPin, 0);
}

void loop() {
    unsigned long tiempoActual = millis();
    
    if (tiempoActual - tiempoAnterior >= tiempoMuestreo) {
        tiempoAnterior = tiempoActual;

        // Deshabilitar interrupciones temporalmente para lectura segura
        noInterrupts();
        unsigned long pulsosMaestro = contadorMaestro;
        contadorMaestro = 0;
        unsigned long pulsosEsclavo = contadorEsclavo;
        contadorEsclavo = 0;
        interrupts();

        // Calcular velocidades en RPM
        float rpmMaestro = calcularRPM(pulsosMaestro);
        float rpmEsclavo = calcularRPM(pulsosEsclavo);

        // Calcular el control PID
        pwmSalida = calcularPID(rpmMaestro, rpmEsclavo);

        // Aplicar PWM al motor esclavo
        ledcWrite(0, pwmSalida);

        // Mostrar datos en el monitor serie
        Serial.print("RPM Maestro: ");
        Serial.print(rpmMaestro);
        Serial.print(" | RPM Esclavo: ");
        Serial.print(rpmEsclavo);
        Serial.print(" | PWM Esclavo: ");
        Serial.println(pwmSalida);
    }
}
