#include "player.h"

player::player(float xInicial, float yInicial)
{
    this->pos.first = xInicial;
    this->pos.second = yInicial;
    this->setPos(pos.first, pos.second);
}

QRectF player::boundingRect() const
{
    return QRectF(-10,-10,20,20); // Rectángulo que modela la hitbox
}

void player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Para crear un círculo azul
    painter->setBrush(Qt::darkBlue);
    painter->drawEllipse(boundingRect());
}






void player::actPos()
{
    // x = xi + vi*t + (1/2)*a*(t**2)
    this->pos.first += (this->vel.first * dt) + ( (0.5)*(this->acc.first)*(dt*dt) );
    this->pos.second += (this->vel.second * dt) + ( (0.5)*(this->acc.second)*(dt*dt) );
}

void player::actVel()
{
    this->vel.first = this->dt * this->acc.first;
    this->vel.second = this->dt * this->acc.second;
}

void player::actForce(std::pair<float, float> newAcc)
{
    this->acc.first = newAcc.first / this->masa;
    this->acc.second = newAcc.second / this->masa;

    this->actPos();
    this->actVel();
    this->setPos(this->pos.first, this->pos.second);
}






// Get and set methods for the onFall variable
void player::setOnfall(bool newOnFall)
{
    this->onFall = newOnFall;
}

bool player::getOnfall(){return this->onFall;}

std::pair<float, float> player::getVel()
{
    return this->vel;
}
