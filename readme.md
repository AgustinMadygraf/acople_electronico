# Control de Velocidad Maestro-Esclavo con ESP32

Este proyecto implementa un sistema de control de velocidad basado en un algoritmo PID utilizando un ESP32. Se controla la velocidad de un motor esclavo para que siga la velocidad de un motor maestro utilizando sensores inductivos.

## 📜 Descripción

El sistema mide la velocidad de dos motores utilizando sensores inductivos y ajusta el PWM del motor esclavo mediante un controlador PID. Esto permite sincronizar la velocidad del motor esclavo con la del maestro, asegurando un funcionamiento coordinado.

## 🛠️ Hardware Requerido

- **ESP32**
- **Sensores inductivos** (x2)
- **Motor maestro** (sin control directo en este código)
- **Motor esclavo** con control de velocidad por PWM
- **Fuente de alimentación adecuada**
- **Cables y conexiones**

## 🔧 Configuración de Pines

| Componente         | Pin ESP32 |
|--------------------|----------|
| Sensor Maestro    | GPIO 34  |
| Sensor Esclavo    | GPIO 35  |
| PWM Motor Esclavo | GPIO 25  |

## ⚙️ Parámetros del Sistema

- **Pulsos por vuelta**: 10 (ajustable según sensor inductivo)
- **Tiempo de muestreo**: 100 ms
- **Frecuencia PWM**: 1 kHz
- **Resolución PWM**: 8 bits (valores de 0 a 255)

## 📌 Código Explicado

1. **Interrupciones**: Se usan interrupciones para contar los pulsos de los sensores.
2. **Cálculo de RPM**: Se determina la velocidad de cada motor a partir del conteo de pulsos.
3. **Control PID**: Se usa un algoritmo PID para ajustar el PWM del motor esclavo en función de la diferencia de velocidad con el maestro.
4. **Salida PWM**: Se configura la salida PWM usando `ledcWrite()`.

## 🖥️ Ejecución

1. **Compilar y cargar el código en el ESP32**.
2. **Abrir el Monitor Serie** con una velocidad de `115200 baudios`.
3. **Observar la sincronización de velocidades entre el motor maestro y el motor esclavo**.

## 📊 Salida Esperada en Monitor Serie

```plaintext
RPM Maestro: 1200.00 | RPM Esclavo: 1180.00 | PWM Esclavo: 180
RPM Maestro: 1250.00 | RPM Esclavo: 1230.00 | PWM Esclavo: 190
...
```

## 📌 Posibles Mejoras

- **Ajuste fino de los coeficientes PID** (`Kp`, `Ki`, `Kd`) para una mejor respuesta.
- **Filtro digital** para reducir ruido en las mediciones de los sensores.
- **Interfaz gráfica** para visualización en tiempo real.

---

📌 **Autor:** Agustín  
📆 **Última actualización:** Febrero 2025  
📄 **Licencia:** MIT