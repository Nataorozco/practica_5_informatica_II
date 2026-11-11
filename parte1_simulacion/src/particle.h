#ifndef PARTICLE_H
#define PARTICLE_H

// Partícula circular con posición, velocidad, masa y radio.
class Particle
{
public:
    Particle(int id, double x, double y, double vx, double vy,
             double masa, double radio);

    // Movimiento rectilíneo uniforme durante un intervalo dt:
    //   x = x + vx * dt,  y = y + vy * dt
    void mover(double dt);

    // Energía cinética: (1/2) * m * |v|^2
    double energiaCinetica() const;

    int id() const { return id_; }
    double x() const { return x_; }
    double y() const { return y_; }
    double vx() const { return vx_; }
    double vy() const { return vy_; }
    double masa() const { return masa_; }
    double radio() const { return radio_; }
    bool activa() const { return activa_; }

    void setPosicion(double x, double y) { x_ = x; y_ = y; }
    void setVelocidad(double vx, double vy) { vx_ = vx; vy_ = vy; }
    void desactivar() { activa_ = false; }

private:
    int id_;
    double x_, y_;
    double vx_, vy_;
    double masa_;
    double radio_;
    bool activa_;   // false cuando la partícula se fusionó con otra (etapa 3)
};

#endif // PARTICLE_H
