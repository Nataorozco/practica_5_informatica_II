# 04 · Clase Simulation

## Qué representa

Esta es la clase que une todas las demas y controla la simulacion en tiempo discreto : Tiene la caja de las particulas y el registro de colisiones, y avanza el tiempo en pasos de dt. EScribe los resultados en archivos de texto, como pide el enunciado.

ATRIBUTOS: Caja, dt, tiempo, particulas, eventos.
Para que sirven?
caja_: La box donde ocurre todo. Simulacion es su dueña (composicion).
dt_: Intervalo de tiempo de cada paso (0.01 s)
tiempo_: Reloj de la simulacion; empieza en 0 y sube dt_ en cada paso
Particulas_: std::vector particle  con las n particulas.
eventos_: std::vector collision con todas las colisiones registradas.
## Atributos

| Atributo      | Para qué sirve                                                     |
| ------------- | ------------------------------------------------------------------ |
| `caja_`       | La `Box` donde ocurre todo. `Simulation` es su dueña (composición) |
| `dt_`         | Intervalo de tiempo de cada paso (0.01 s)                          |
| `tiempo_`     | Reloj de la simulación; empieza en 0 y sube `dt_` en cada paso     |
| `particulas_` | `std::vector<Particle>` con las `n` partículas                     |
| `eventos_`    | `std::vector<Collision>` con las colisiones registradas            |

METODOS: Simulacion(caja, dt), agregarParticula(p), energiaTotal(), paso(), ejecutar(tFinal, carpeta), eventos().
Que hace cada una?
Simulacion(caja, dt): Constructor. Guarda la caja y el dt, y pone el reloj en 0.
agregarParticula(p): Añade una particula al vector con push_back.
energiaTotal(): Suma la energia cinetica de las particulas activas.
Paso(): Privado, avanza un intervalo de tiempo.
ejecutar(tFinal, carpeta): Bucle principal; escribe los archivos de salida. 
eventos(): Devuelve los eventos por referencia constante, solo lectura.
## Métodos

| Método | Qué hace |
|---|---|
| `Simulation(caja, dt)` | Constructor. Guarda la caja y el `dt`, y pone el reloj en 0 |
| `agregarParticula(p)` | Añade una partícula al vector con `push_back` |
| `energiaTotal()` | Suma la energía cinética de las partículas activas |
| `paso()` | Privado. Avanza un intervalo de tiempo (ver abajo) |
| `ejecutar(tFinal, carpeta)` | Bucle principal; escribe los archivos de salida |
| `eventos()` | Devuelve los eventos por referencia constante, solo lectura |

## Qué pasa en cada `paso()`

1. Sube el reloj: tiempo_ += dt_
2. Para cada particula activa:
3. La mueve con mover(dt_)
4. pregunta a la caja si choco con la pared
5. Si choco guarda una colision con el instante, el tipo PARED, la particula , la posicion y la pared golpeada.
## Qué pasa en `ejecutar()`

1. Crea la carpeta de salida y abre trayectorias.txt 
2. EScribe el estado inicial (t = 0)
3. Mientras tiempo_ < tFinal : hace un paso() y escribe la poscion de cada particula activa
4. Al terminar, escribe eventos.txt con una linea por colision.

## Archivos de salida

`trayectorias.txt`: una línea por partícula y por instante.

```
# t id x y
0.0100 1 10.1200 10.0700
```

`eventos.txt`: una línea por colisión.

```
# t tipo idA idB x y detalle
0.3100 PARED 1 -1 2.0000 30.0000 izquierda
```

Los campos van separados por un espacio. Si faltara alguno, las columnas se mezclarían y no se podría graficar.

## Decisiones de diseño

-Paso() es privado: un paso suelto no tiene sentido para quien usa la clase; solo ejecutar lo llama, en bucle.
-Const Box & y const particle&: se pasan por referencia constante para no copiar de mas y dejar claro que no se modifican.
-for (particle &p : particulas_) con &:  trabaja sobre la particula original del vector; sin el & el movimiento se haria una copia y se perderia.
-std::vector: crece solo y no hay que fijar de antemano el numeo de particulas ni de colisiones.
-Las trayectorias se escriben a archivo en cada paso y no se guardan en memoria, asi que el consumo de memoria no crece con el tiempo.
-Particulas inactivas: paso() las salta con continue. se usarian en la fusion.

## Cómo se probó

Caja de 100×60, 5 partículas, `dt = 0.01`, 30 s (3000 pasos):

```
Colisiones registradas: 38
Energia cinetica inicial: 576.75
Energia cinetica final:   576.75
```

La energia cinetica identica ala inicio y al final confirma que los rebotes en pared son elasticos.
Ademas, ninguna particula salio de la caja en ninguno de los pasos.
## Limitaciones actuales

Todavia no hay obstaculos ni fusion: las particulas se cruzan sin chocar entre si. ESo se agrega en las etapas siguientes.
## Preguntas de ayuda

¿como funciona la simulacion en tiempo discreto? Se avanza en tiempo en pasos de dt; en cada paso se actualiza el estado y se revisan las colisiones.
¿por que simulation contiene a box y particle? ES composicion: la simulacion es la dueña, y si desaparece, desaparecen con ella.
¿Para que sirve collision aqui? para registrar cada evento y poder escribirlo en eventos.txt.
¿Que pasa si dt es muy grande? una particula rapida puede atravesar una pared u obstaculo en un solo paso sin que se detecte.
¿como se comprueba que la simulacion es correcta? La energia cinetica se conserva con paredes elasticas, y ninguna particula sale de la caja.
