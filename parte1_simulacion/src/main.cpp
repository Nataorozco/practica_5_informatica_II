#include <iostream>
#include"particle.h"
#include<string>
#include "box.h"
#include "collision.h"
#include "simulation.h"

int main(int argc, char *argv[])
{
    const std::string carpetaSalida = (argc > 1) ? argv[1] : "salida";

    const double dt = 0.01;      //intervalo de tiempo (s)
    const double tFinal = 30.0; // duracion de la simulacion

    Simulation sim(Box(100.0, 60.0), dt);

    //particle(id, x, y,vx, vy, masa, radio)
    sim.agregarParticula(Particle(1, 10.0, 10.0, 12.0, 7.0, 1.0, 1.5));
    sim.agregarParticula(Particle(2, 80.0, 15.0, -10.0, 9.0, 2.0, 2.0));
    sim.agregarParticula(Particle(3, 30.0, 45.0, 8.0, -11.0, 1.5, 1.8));
    sim.agregarParticula(Particle(4, 70.0, 50.0, -14.0, -6.0, 0.5, 1.2));
    sim.agregarParticula(Particle(5, 50.0, 30.0, 6.0, 13.0, 1.0, 1.5));

    const double energiaInicial = sim.energiaTotal();
    sim.ejecutar(tFinal, carpetaSalida);
    const double energiaFinal = sim.energiaTotal();

    std::cout << "Simulacion terminada. archivos en: "  << carpetaSalida << '\n'
              << "Colisiones registradas: "  << sim.eventos().size() << '\n'
              << "Energia cinetica inicial: "  << energiaInicial << '\n'
              << "Energia cinetica final: "  << energiaFinal << '\n';

        return 0;
}
