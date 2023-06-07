#include "propsLife.h"
#include <QFont>
#include <QDebug>

propsLife::propsLife(int w_, int h_, int x, int y, int vida) : props(w_, h_, x, y)
{
    cantidadDeVida = vida;
    //setPlainText(QString("Score: ")+ QString::number(cantidadDeVida)); // Mostrar el texto
    //setDefaultTextColor(Qt::white); // Definir el color del texto
    //setFont(QFont("Comic Sans MS",14)); // Definir tipo de letra y tamaño
}

void propsLife::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    props::paint(painter, option, widget); // Llamar al método paint de la clase base

    // Agregar aquí el código adicional para dibujar la cantidad de vida, por ejemplo:
    //painter->setPen(Qt::black); // Establecer el color de la pluma en negro
    //painter->setFont(QFont("Arial", 10)); // Establecer la fuente del texto
    //painter->drawText(boundingRect().topLeft() + QPointF(5, 15), QString("Vida: %1").arg(cantidadDeVida)); // Dibujar el texto con la cantidad de vida en la esquina superior izquierda del rectángulo del prop
}

int propsLife::getLife()
{
    return this->cantidadDeVida;
}

void propsLife::decreaseLife(int damageDealt)
{
    cantidadDeVida -= damageDealt; // Disminuir la vida en 1
    //qDebug() << "Vida restante:" << cantidadDeVida;
    //setPlainText(QString("Life: ") + QString::number(cantidadDeVida));  // actualiza el texto de la puntuación
}

