# 03 · Collision

## Qué representa

El registro de una colision. El enunciado pide guardar las colsiones junto con el instante en que  ocurrieron; cada collision es una linea de ese archivo de eventos.
## Por qué es una `struct`

solo guarda datos y no necesita esconderlos ni tener logica propia. En una struc todo es publico por defecto, y asi se accede directo a c.t, c.tipo, etc.

Solo guarda datos y no necesita esconderlos ni tener lógica propia. En una `struct` todo es público por defecto, y así se accede directo a `c.t`, `c.tipo`, etc.
## Campos

Campo = tiempo 
Para que sirve = instante de la simulacion en el que ocurrio 
Campo = tipo 
Para que sirve = PARED, OBSTACULO O FUSION (los tres tipos del enunciado)
Campo = IdA
Para que sirve  = particula involucrada
idB = otra particula, o -1 si no aplica (pared y obstaculo)
x, y = posicion de la particula, al chocar; sirve para marcar el choque en la grafica.
detalle = pared o lado del obsctaculo golpeado.

| Campo | Para qué sirve |
|---|---|
| `t` | Instante de la simulación en el que ocurrió |
| `tipo` | `PARED`, `OBSTACULO` o `FUSION` (los tres tipos del enunciado) |
| `idA` | Partícula involucrada |
| `idB` | Otra partícula, o `-1` si no aplica (pared y obstáculo) |
| `x`, `y` | Posición de la partícula al chocar; sirve para marcar el choque en la gráfica |
| `detalle` | Pared o lado del obstáculo golpeado |

## `enum Tipo`

Define los tres posibles. Evita errores de escritura: con textos sueltos se podria escribir "pared" y nadie avisaria; con un enum, el compilador no deja.

## `nombreTipo`

Metodo static que convierte el enum en el texto para escribirlo en eventos.txt. Es static porque  no depende de ningun registro en particular, asi que se llama se llama collsion::nombreTipo(...)

Metodo static que convierte el enum en text para escribirlo en eventos.txt. Es static porque no depende de ningun registro en particular, asi que llamo como collision::nombreTipo(...)

## Cómo se probó

se creo un registro a mano y se imprimio:

0.31 PARED 1 -1 2 30 izquierda 

Preguntas que aclaran.

¿Porque struc y no class ? solo agrupa datos, sin logica ni encapsulamiento.
¿Para que sirve el enum ? Para limitar los tipos a tres valores validos y que el compilar detecte errores.
¿Que significa idB = -1? Que no hay segunda particula en ese evento.
Que hace static? hace que la funcion pertenezca a la estructura, no a un objeto concreto.
