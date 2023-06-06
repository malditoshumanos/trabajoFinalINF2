#include "player.h"

#include <stdio.h>

// La variable onFall comienza en falso
player::player(float xInicial, float yInicial)
{
    this->pos.first = xInicial;
    this->pos.second = yInicial;
    this->setPos(pos.first, pos.second);
    this->onFall = false;    
}

QRectF player::boundingRect() const
{
    return hitbox; // Rectángulo que modela la hitbox
}

void player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Para crear un círculo azul
    painter->setBrush(Qt::darkBlue);
    painter->drawRect(hitbox);
}






void player::actPos()
{
    // x = xi + vi*t + (1/2)*a*(t**2)
    this->pos.first += (this->vel.first * dt) + ( (0.5)*(this->acc.first)*( std::pow(dt, 2)) );
    this->pos.second += (this->vel.second * dt) + ( (0.5)*(this->acc.second)*( std::pow(dt, 2) ) );
}

void player::actVel()
{
    this->vel.first += this->dt * this->acc.first;
    this->vel.second += this->dt * this->acc.second;
}

void player::actForce(std::pair<float, float> newAcc)
{
    this->acc.first = newAcc.first / this->masa;
    this->acc.second = newAcc.second / this->masa;

    /* Note que se debe actualizar la posición antes que la velocidad
     * para que el valor de la velociddad
     * inicial al calcular esta, sea el correcto.
     */
    this->actPos(); // La posición en la escena del objeto se actualiza en la clase mainwindow.cpp
    this->actVel();
}






// Get and set methods for the onFall variable
void player::setOnfall(bool newOnFall)
{
    this->onFall = newOnFall;
}

bool player::getOnfall(){return this->onFall;}

std::pair<float, float> player::getPos()
{
    return this->pos;
}

std::pair<float, float> player::getVel()
{
    return this->vel;
}

void player::setVelX(float newVelX)
{
    this->vel.first = newVelX;
}

void player::setVelY(float newVelY)
{
    this->vel.second = newVelY;
}

void player::setPosX(float newPosX)
{
    this->pos.first = newPosX;
}

void player::setPosY(float newPosY)
{
    this->pos.second = newPosY;
}
