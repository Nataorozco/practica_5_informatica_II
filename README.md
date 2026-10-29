# Práctica 5 - Informática II

Universidad de Antioquia, Facultad de Ingeniería.

## Estructura

- `parte1_simulacion/`: simulación de colisiones múltiples (C++, sin GUI). Genera un archivo de texto con posiciones y colisiones.
- `parte2_juego/`: juego de estrategia por turnos (Qt Widgets + Graphics View Framework).
- `docs/`: diagramas de clases y notas de diseño.
- `tools/`: scripts para graficar la salida de la Parte 1.

## Compilar

Cada parte es un proyecto CMake independiente. Se pueden abrir desde Qt Creator (`File > Open File or Project > CMakeLists.txt`) o por terminal:

```bash
cmake -S parte1_simulacion -B build/parte1
cmake --build build/parte1
./build/parte1/simulacion
```

## Avance

Commits pequeños y frecuentes, porque la práctica exige evidencia de avance continuo en el repositorio.
