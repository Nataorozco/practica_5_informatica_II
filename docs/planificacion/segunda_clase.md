# 02 · Clase Box

## Qué representa

Esta  clase representa la caja rectangular donde se mueven las particulas. Su esquina inferior izquierda esta en (0,0) y sus paredes producen rebotes perfectamente elasticos, como pide el enunciado.

## Atributos

ancho_ = posicion de la pared derecha (x= acho)
alto_ = posicion de la pared superior (y = alto)

| Atributo | Para qué sirve |
|---|---|
| `ancho_` | Posición de la pared derecha (`x = ancho_`) |
| `alto_` | Posición de la pared superior (`y = alto_`) |
La pared izquierda esta en x = 0 y la inferior en y = 0, por eso no necesitan atributos.
	

## Método `rebotar(p, pared)`

Aqui revisa si la particula cruzo alguna de las 4 paredes. Si lo hizo, corrige su posicion y su velocidad, y devuelve true. En pared deja el nombre de la pared golpeada (izquierda, derecha, abajo, arriba), que luego se guarda en el archivo de eventos.
### La física

En un rebote perfectamente elastico: 
-La componente de la velocidad perpendicular a la pared se invierte (vx = -vx) en paredes verticales, vy = -vy en horizontales.
-La componente paralela no cambia; 
-La rapidez se conserva, asi que la energia cinetica total tambien.

### Cómo se detecta el choque

 Las particulas son circulares, asi que toca la pared el borde, no el centro:

Pared = izquierda = condicion =  x - r < 0
pared = derecha = condicion = x + r > ancho
pared = inferior = condicion = y -r < 0
pared = superior = condicion = y + r > alto

| Pared | Condición |
|---|---|
| Izquierda | `x - r < 0` |
| Derecha | `x + r > ancho_` |
| Inferior | `y - r < 0` |
| Superior | `y + r > alto_` |

### Corrección de la posición

En el tiempo discreto, cuando se detecta el choque la particula ya se paso un poco de la pared. Se refleja la posicion respecto a la pared:
-izquierda x = 2 . r - x
-derecha x = 2 .(ancho_  - r) - x
-Analogo en y

Por ejemplo: con r = 2, si el centro quedo en x = 1.9, el borde esta 0.1 dentro de la pared. L a nueva posicion es 2.2 - 2.9 = 2.1, que es 0.1 hacia adentro del limite x = 2, tal como habria quedado en un rebote real.


### Por qué `else if` y `if`

porque izquierda y derecha van encadenadas con else if : una particula no puede cruzar las dos a la vez.
Abajo y arriba van en un if aparte: En una esquina la particula si pide cruzar una pared vertical y una horizontal en el mismo paso, y se deben corregir las dos.
### Por qué recibe `Particle &p`

Por referencia, para modificar la particula original y no una copia. El const al final del metodo indica que no cambia la caja.
## Cómo se probó

caja de 100x 60. Particula en (5, 30), velocidad (-10, 0), radio 2, 100 pasos de dt = 0.01 (1 s).

A mano: el borde llega a la pared cuando el centro esta en x = 2, tras recorrer 3 unidades. Le  quedan 7 por recorrer, ya hacia la derecha: x = 2 + 7 = 9, con vx = + 10.
La salida del programa es :

choque con pared izquierda en paso 31
x = 9, y = 30, vx = 10
## Preguntas clave

-¿Porque el rebote es elastico?
Porque solo se invierte una componente de la velocidad; la rapidez y la energia cinetica no cambian.
-¿Por que se usa  el radio en la condicion? porque la particula tiene tamaño: toca la pared con el borde, no con el centro.
-¿Para que se corrige la posicion? para que la particula no quede dentro de la pared, si se quedara adentro, en el paso siguiente podria detectarse otro choque con la misma pared.
-¿Que pasa en una esquina? se corrigen las dos paredes en el mismo paso, y se invierten vx y vy.
-¿Que es & en particula &p?  una referencia se modifica la particula original.
