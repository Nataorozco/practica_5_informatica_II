#include "simulation.h"

#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>

//constructor agrega particulas, energia total y un paso de tiempo

Simulation::Simulation(const Box &caja, double dt)
    :caja_(caja), dt_(dt), tiempo_(0.0)
{

}

void Simulation::agregarParticula(const Particle &p)
{
    particulas_.push_back(p);
}

double Simulation::energiaTotal() const
{
    double e = 0.0;
    for (const Particle &p : particulas_)
        if (p.activa())
            e += p.energiaCinetica();
    return e;
}

void Simulation::paso()
{
    tiempo_ += dt_;

    for (Particle &p : particulas_) {
        if (!p. activa())
            continue;

        //1. avanzar la particula en un intervalo dt
        p.mover(dt_);

        //2. collision con las paredes (elastica)

        std::string pared;
        if (caja_.rebotar(p, pared)) {
            eventos_.push_back({tiempo_, Collision::PARED, p.id(), -1,
                                p.x(), p.y(), pared});
        }

    }
}

void Simulation::ejecutar(double tFinal, const std::string &carpetaSalida)
{
    std::filesystem::create_directories(carpetaSalida);

    std::ofstream tray(carpetaSalida + "/trayectorias.txt");
    if (!tray) {
        std::cerr << "No se pudo crear trayectorias.txt\n";
        return;
    }
    tray << std::fixed << std::setprecision(4);
    tray << "# t id x y\n";

    // Estado inicial (t = 0)
    for (const Particle &p : particulas_)
        tray << tiempo_<< ' ' << p.id() << ' ' << p.x() << ' ' << p.y() << '\n';

    while (tiempo_ < tFinal) {
        paso();
        for (const Particle &p : particulas_) {
            if (p.activa())
                tray << tiempo_<< ' ' << p.id() << ' '
                     << p.x() << ' ' << p.y() << '\n';
        }
    }

    std::ofstream ev(carpetaSalida + "/eventos.txt");
    if (!ev) {
        std::cerr << "No se pudo crear eventos.txt\n";
        return;
    }
    ev << std::fixed << std::setprecision(4);
    ev << "# t tipo idA idB x y detalle\n";
    for (const Collision &c : eventos_) {
        ev << c.t << ' ' << Collision::nombreTipo(c.tipo) << ' '
           << c.idA << ' ' << c.idB << ' ' << c.x << ' ' << c.y << ' '
           << (c.detalle.empty() ? "-" : c.detalle) << '\n';
    }
}

