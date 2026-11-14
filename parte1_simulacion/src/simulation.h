#ifndef SIMULATION_H
#define SIMULATION_H

#include <string>
#include <vector>
#include "box.h"
#include "collision.h"
#include "particle.h"

// controla el bucle de tiempo discreto: en cada paso mueve las particulas,
// detecta collisiones y registra posiciones y eventos.
class Simulation
{
public:
    Simulation(const Box &caja, double dt);

    void agregarParticula(const Particle &p);

    //Avanza hasta tfinal y escribe trayectorias.txt y eventos.txt
    //en la carpeta indicada
    void ejecutar(double tFinal, const std::string &carpetaSalida);

    double energiaTotal() const;
    const std::vector<Collision> &eventos() const { return eventos_; }

private:
    void paso();

    Box caja_;
    double dt_;
    double tiempo_;
    std::vector<Particle> particulas_;
    std::vector<Collision> eventos_;

};


#endif // SIMULATION_H
