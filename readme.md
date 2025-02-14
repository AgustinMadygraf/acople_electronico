# Proyecto Acople Electronico

Este proyecto implementa un sistema modular para:
- Lectura de encoders
- Control PID
- Gestión del PWM

## Estructura del Proyecto

- **/main/**  
  - *main.ino*: Archivo principal del sistema.
- **/src/**  
  - *EncoderManager.h / EncoderManager.cpp*: Gestión y lectura de encoders.  
  - *PIDController.h / PIDController.cpp*: Implementación del algoritmo PID.  
  - *PWMManager.h / PWMManager.cpp*: (Pendiente) Gestión del PWM.
- **/docs/**  
  - Documentación de la arquitectura y diagramas del sistema.
- **/tests/**  
  - Pruebas unitarias para cada módulo.

## Instrucciones

1. Configura el hardware de acuerdo a la documentación del ESP32.
2. Tunea los parámetros PID en *PIDController.cpp* según sea necesario.
3. Realiza pruebas unitarias ubicadas en la carpeta **/tests/** para validar el funcionamiento de cada módulo.
4. Consulta *todo.md* para más información sobre las tareas y planes de refactorización.

