#ifndef PROYECTIL_H
#define PROYECTIL_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPointF>

#include <utility>

#include "player.h"
class proyectil : public player
{
public:
    // El constructor toma coordenadas iniciales, el valor del bool dir y el valor del char
    proyectil(float, float, bool, char);

    QRectF boundingRect() const;
    void paint(QPainter *painter,
       const QStyleOptionGraphicsItem *option, QWidget *widget);

    /* CUANDO SE CREA UN PROYECTIL, ESTE MISMO SE ENCARGA DE CALCULAR SU POSICIÓN BASÁNDOSE EN
     * LOS PARÁMETROS DADOS AL CONSTRUCTOR (para saber la posición inicial y la dirección).
     * CADA QUE SE LLAMA ESTE MÉTODO, ESTE RETORNA LA NUEVA POSICIÓN DEL PROYECTIL EN CUESTIÓN.
     */
    std::pair<float, float> actualizarMov();

    int getDamage();
    void makeDamageZero();

private:
    bool dir; // Este bool es true si el proyectil va hacia la derecha y false si va hacia la izquierda
    float radio; // Radio del proyectil. En general se modelan como círculos.
    // dir y radio se definen en el constructor

    int damage; // Daño que causa el proyectil

    // Overload member variables
    const float masa = 2; // masa del proyectil
    const float dt = 0.5; // cambio de tiempo en cada actualización
    // Este es el tamaño del proyectil. Se usa en boundingRect() y paint() (ver player.cpp)
    QRectF hitbox = QRectF(-radio, -radio, 2 * radio, 2 * radio);
};

#endif // PROYECTIL_H
