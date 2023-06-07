#include "pickUps.h"

pickUps::pickUps(int w_, int h_, int x, int y,  char idPickUp) : props(w_, h_, x, y)
{
    /* Este ID determina el efecto que tendrá el pickup.
     * V: restaurar vida por completo (la vida completa es de 500)
     * A: aumento de velocidad
     * J: jetpack
     * M: metralleta
     * I: invencible
     */
    IDpickUp = idPickUp;
}


void pickUps::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    props::paint(painter, option, widget); // Llamar al método paint de la clase base

    // Agregar aquí el código adicional para dibujar la cantidad de vida, por ejemplo:
    //painter->setPen(Qt::black); // Establecer el color de la pluma en negro
    //painter->setFont(QFont("Arial", 10)); // Establecer la fuente del texto
    //painter->drawText(boundingRect().topLeft() + QPointF(5, 15), QString("Vida: %1").arg(cantidadDeVida)); // Dibujar el texto con la cantidad de vida en la esquina superior izquierda del rectángulo del prop
}

char pickUps::getId()
{
    return IDpickUp;
}
