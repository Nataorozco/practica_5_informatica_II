#include <iostream>
#include"particle.h"
#include<string>
#include "box.h"

int main()
{
    Box caja(100.0, 60.0);
    // Particle(id, x, y, vx, vy, masa, radio): va hacia la pared izquierda
    Particle p(1, 5.0, 30.0, -10.0, 0.0, 1.0, 2.0);

    // 100 pasos de 0.01 s = 1 s de movimiento
    for (int i = 0; i < 100; ++i){
        p.mover(0.01);
        std::string pared;
    if (caja.rebotar(p, pared))
            std::cout << "choque con pared " << pared << " en paso " << i + 1 << '\n';
    }

    std::cout << "x = " << p.x() << ", y = " << p.y() << ", vx = " << p.vx() << '\n';
    return 0;
}
