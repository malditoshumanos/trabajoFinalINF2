#include "player.h"

#include <stdio.h>

// La variable onFall comienza en falso
player::player(float xInicial, float yInicial)
{
    this->pos.first = xInicial;
    this->pos.second = yInicial;
    this->setPos(pos.first, pos.second);
    this->onFall = false;    
    this->arma = 'D'; // El arma inicial es la Desert Eagle
    this->vida = 500; // El jugador inicia con vida máxima
    this->cooldownDisparo = false; // El cooldown está desactivado al spawnear al jugador
    this->pickUpActivado = 'N'; // Spawnea sin pickUp


    // SPRITES
    // crear un objeto QTimer
    timerPlayer = new QTimer();
    rows = 0;
    columns = 0;
    pixmapPlayer = new QPixmap(":/images/Pink.png");

    //dimensiones imagen
    width = 32;
    high = 32;
    // activa el temporizador timer2 con un intervalo de 100 milisegundos.
    timerPlayer->start(100);
    // se conecta la señal timeout del temporizador a la ranura Actualizacion2 de la clase moneda.
    connect(timerPlayer, &QTimer::timeout, this,&player::updateSprPlayer);
}

QRectF player::boundingRect() const
{
    return hitbox; // Rectángulo que modela la hitbox
}

void player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Para crear un círculo azul
    //painter->setBrush(Qt::darkBlue);
    painter->drawPixmap(-width/2, -high/2,*pixmapPlayer,columns,rows,width,high);
    setScale(0.9);
    //painter->drawRect(hitbox);
}

void player::updateSprPlayer() //  se invoca cada vez que se produce una señal de tiempo (timeout) del temporizador
{
    columns += 32;
    if(columns >= 192){
        columns = 0;
    }

    rows += 32;
    if(rows >= 32){
        rows =0;
    }
    this->update(-width/2,-high/2,width,high);  // actualización del área de dibujo de la moneda.

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

char player::getCurrentWeapon()
{
    return arma;
}

int player::getHealth()
{
    return vida;
}

void player::setHealth(int newVida)
{
    this->vida = newVida;
}

void player::setCooldownDisparo(bool newCooldown)
{
    this->cooldownDisparo = newCooldown;
}

bool player::getCooldownDisparo()
{
    return this->cooldownDisparo;
}

char player::getPickUp()
{
    return this->pickUpActivado;
}

void player::setPickUp(char newPickUp)
{
    this->pickUpActivado = newPickUp;
}
