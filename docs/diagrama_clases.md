# Diagrama de clases · Parte 1

Se agregan clases a medida que se implementan. Estado actual: `Particle` implementada; el resto es el diseño previsto.

```mermaid
classDiagram
    class Particle {
        -int id_
        -double x_
        -double y_
        -double vx_
        -double vy_
        -double masa_
        -double radio_
        -bool activa_
        +mover(double dt) void
        +energiaCinetica() double
        +setPosicion(double x, double y) void
        +setVelocidad(double vx, double vy) void
        +desactivar() void
    }
    class Box {
        -double ancho_
        -double alto_
        +rebotar(Particle p, string pared) bool
    }
    class Obstacle {
        -double x_
        -double y_
        -double lado_
        +rebotar(Particle p, double e, string lado) bool
    }
    class Collision {
        +double t
        +Tipo tipo
        +int idA
        +int idB
        +double x
        +double y
        +string detalle
    }
    class Simulation {
        -Box caja_
        -double dt_
        -double tiempo_
        -double e_
        -vector~Particle~ particulas_
        -vector~Obstacle~ obstaculos_
        -vector~Collision~ eventos_
        +agregarParticula(Particle p) void
        +ejecutar(double tFinal, string carpeta) void
        +energiaTotal() double
        -paso() void
    }
    Simulation "1" *-- "1" Box : contiene
    Simulation "1" *-- "n" Particle : simula
    Simulation "1" *-- "4" Obstacle : contiene
    Simulation "1" *-- "n" Collision : registra
    Box ..> Particle : actúa sobre
    Obstacle ..> Particle : actúa sobre
    Collision ..> Particle : referencia por id
```

## Relaciones

- **Composición (`*--`):** `Simulation` es dueña de la caja, las partículas, los obstáculos y el registro de colisiones.
- **Dependencia (`..>`):** `Box` y `Obstacle` no guardan partículas; reciben una, la corrigen y devuelven si hubo choque.# Diagrama de clases

Pendiente de diseñar. Se actualiza a medida que avance la Parte 1.
