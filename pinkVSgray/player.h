#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsItem>
#include <QPainter>

#include <utility>
#include <cmath>


/*
 * Para tener en cuenta las colisiones con el piso del jugador, se tiene el bool onFall que debe
 * permanecer en 0 cuando el jugador está sobre alguna plataforma y en 1 si está cayendo (cuando salta
 * o cae de alguna plataforma. Este bool se modifica de acuerdo a las colisiones de la hitbox del player
 * Cuando este bool está en false, no hay aceleración vertical hacia abajo.
 *
 */

class player : public QGraphicsItem
{
public:
    player(float, float); // El constructor recibe la posición inicial del jugador

    QRectF boundingRect() const; // Forma del objeto (forma rectángular)
    void paint(QPainter *painter,
       const QStyleOptionGraphicsItem *option, QWidget *widget); // Para pintar los objetos en pantalla

    void actForce(std::pair<float, float>); // Input: fuerza aplicada al jugador. Modela el movimiento.
    void setOnfall(bool);
    bool getOnfall();

    std::pair<float, float> getPos();
    std::pair<float, float> getVel();

    void setVelX(float);
    void setVelY(float);
    void setPosX(float);
    void setPosY(float);


private:
    // AQUÍ SE MODIFICAN LOS PARÁMETROS QUE AFECTAN EL COMPORTAMIENTO DEL JUGADOR
    bool onFall; // Ver comentario arriba
    const float masa = 5; // masa del jugador
    const float dt = 0.5; // cambio de tiempo en cada actualización
    QRectF hitbox = QRectF(-10,-25,20,50); // Para usar en boundingRect() y paint() (ver player.cpp)

    std::pair<float, float> pos; // posición, velocidad, aceleración
    std::pair<float, float> vel;
    std::pair<float, float> acc;

    // Note que siempre se cambia el movimiento del jugador dándole aceleración
    void actPos(); // Actualizar la posición, velocidad, aceleración
    void actVel();

};

#endif // PLAYER_H
