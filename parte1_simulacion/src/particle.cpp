#include "particle.h"

Particle::Particle(int id, double x, double y, double vx, double vy,
                   double masa, double radio)
    : id_(id), x_(x), y_(y), vx_(vx), vy_(vy),
      masa_(masa), radio_(radio), activa_(true)
{
}

void Particle::mover(double dt)
{
    x_ += vx_ * dt;
    y_ += vy_ * dt;
}

double Particle::energiaCinetica() const
{
    return 0.5 * masa_ * (vx_ * vx_ + vy_ * vy_);
}
