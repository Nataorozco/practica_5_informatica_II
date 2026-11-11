#include "box.h"

Box::Box(double ancho, double alto)
    : ancho_(ancho), alto_(alto)
{

}

bool Box::rebotar(Particle &p, std::string &pared) const
{
    double x = p.x(), y = p.y();
    double vx = p.vx(), vy = p.vy();
    const double r = p.radio();
    bool choco = false;

    //pared izquierda (x = 0)
    if (x - r < 0.0) {
        x = 2.0 * r - x;
        vx = -vx;
        pared = "izquieda";
        choco = true;
    }
    // pared derecha  (x = ancho)
    else if (x + r > ancho_) {
        x = 2.0 * (ancho_ - r) -x;
        vx = -x;
        pared = "derecha";
        choco = true;
    }
    // pared inferior (y = 0)
    if (y - r < 0.0){
        y = 2.0 * r - y;
        vy = -vy;
        pared = "abajo";
        choco = true;
    }
    // pared superior (y = alto)
    else if (y + r > alto_) {
        y = 2.0 * (alto_ - r) - y;
        vy = -vy;
        pared = "arriba";
        choco = true;
    }
    if (choco) {
        p.setPosicion(x, y);
        p.setVelocidad(vx, vy);
    }
    return choco;
}
