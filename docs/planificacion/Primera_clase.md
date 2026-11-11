# 01 · Clase Particle

## Qué representa

Hoy 10 de noviembre cree mi primera clase particle: 
Una particula circular que se mueve por la caja. Es la pieza base de la simulacion. las paredes, los obstaculos y las otras particulas actuan sobre ella.

## Atributos

id_ = identifica a la particula en los archivos de salida
x_, y_ = posicion del centro
vx_,vy_= comónentes de velocidad
masa_= se usa en la energia cinetica y en la fusion
radio_ = las particulas son circulares; hace falta para detectar choques
activa_ = true mientras existe; pasa a false caundo se fusiona con otra

| Atributo | Para qué sirve |
|---|---|
| `id_` | Identifica a la partícula en los archivos de salida |
| `x_`, `y_` | Posición del centro |
| `vx_`, `vy_` | Componentes de la velocidad |
| `masa_` | Se usa en la energía cinética y en la fusión |
| `radio_` | Las partículas son circulares; hace falta para detectar choques |
| `activa_` | `true` mientras existe; pasa a `false` cuando se fusiona con otra |

## Métodos

### `mover(dt)`
delta de tiempo:
x_ += vx_    *  dt;
y_ += vy_   *dt;

```cpp
x_ += vx_ * dt;
y_ += vy_ * dt;
```

ESta es la ecuacion del # 1 pdf, x= x0 + vx.t , aplicada en tiempo discreto; se avanza un intervalo pequeño dt a partir del estado actual. Sin gravedad, la ecaucion 2 queda igual que la 1.
### `energiaCinetica()`

Devuelve `½·m·|v|²` sirve para comprobar los rebotes en pared conservan la energia.
## Cómo se probó
particula en (10, 10) con velocidad (12, 7), 100 pasos de dt = 0.01 (1s). A mano: x = 22, y = 17. El programa imprimio x = 22, y = 17
Partícula en `(10, 10)` con velocidad `(12, 7)`, 100 pasos de `dt = 0.01` (1 s). A mano: `x = 22`, `y = 17`. El programa imprimió `x = 22, y = 17`.

## Preguntas clave

¿por que tiempo discreto?
porque en cada paso se puede detectar colisiones y cambiar la velocidad.
¿por que atributos privados?
encapsulamiento
¿que pasa si delta de tiempo es mas grande?
Una particula rapida puede atravesar un obstaculo sin que se detecte.

