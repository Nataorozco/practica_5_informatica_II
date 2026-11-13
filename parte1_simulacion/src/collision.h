#ifndef COLLISION_H
#define COLLISION_H
#include <string>

//Registro de colision: cuando, de que tipo, quien y donde.
struct collision
{
    enum Tipo { PARED, OBSTACULO, FUSION };

    double t;    //instante de la simulacion (s)
    Tipo tipo;
    int idA;     //particula involucrada
    int idB;     // -1 si no aplica (pared) o id de la otra particula
    double x, y;  // posicion de la particula A al chocar
    std::string detalle; //pared o lado del obstaculo golpeado

    static const char *nombreTipo(Tipo t)
    {
        switch (t) {
        case PARED:  return "PARED";
        case OBSTACULO: return "OBSTACULO";
        case FUSION:  return "FUSION";
        }
        return "?";
    }
};






#endif //COLLISION_H
