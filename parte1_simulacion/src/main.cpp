#include <iostream>
#include"particle.h"

int main()
{
    // Particle(id, x, y, vx, vy, masa, radio)
    Particle p(1, 10.0, 10.0, 12.0, 7.0, 1.0, 1.5);

    // 100 pasos de 0.01 s = 1 s de movimiento
    for (int i = 0; i < 100; ++i)
        p.mover(0.01);

    std::cout << "x = " << p.x() << ", y = " << p.y() << '\n';
    return 0;
}
