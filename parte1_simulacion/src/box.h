#ifndef BOX_H
#define BOX_H

#include <string>
#include "particle.h"

// caja rectangular con esquina inferior izquierda en (0,0)
// sus paredes producen rebotes perfectamente elasticos.
class Box
{
public:
    Box(double ancho, double alto);

    // si la particula cruza una pared, invierte la componente perpendicular
    // de la velocidad y la devuelve al interior. Retorna true si hubo choque.
    bool rebotar(Particle &p, std::string &pared) const;

    double ancho() const { return ancho_;}
    double alto() const { return alto_;}

private:
    double ancho_;
    double alto_;
};
#endif // BOX_H
