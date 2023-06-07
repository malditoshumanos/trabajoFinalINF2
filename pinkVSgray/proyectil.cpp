#include "proyectil.h"

#include <iostream>

proyectil::proyectil(float xi, float yi, bool direccion, char arma) : player(xi, yi)
{
    this->dir = direccion;
    this->arma = arma;

    // El tamaño del proyectil está determinado por el tipo de arma
    if(this->arma == 'D'){
        this->radio = 5;
        this->damage = 100;
    }
}


QRectF proyectil::boundingRect() const
{
    return QRectF(-radio, -radio, 2 * radio, 2 * radio);
}

void proyectil::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::red);
    painter->drawEllipse(QPointF(0, 0), radio, radio);
}

std::pair<float, float> proyectil::actualizarMov()
{
    switch (arma){
        case 'D':{
            float velProyectil = 7; // Velocidad horizontal del proyectil

            // El proyectil de la DE se mueve con velocidad constante horizontalmente.
            this->acc.first = 0;
            this->acc.second = 0;
            this->vel.first = ( (-1*!dir) + (1*dir) ) * velProyectil;
            this->vel.second = 0;

            this->actPos();
            break;
        }

    }
}

int proyectil::getDamage()
{
    return this->damage;
}

void proyectil::makeDamageZero()
{
    this->damage = 0;
}
