#include "props.h"

props::props(int w_, int h_, int x, int y) //  implementación del constructor de la clase paredes
{
    w = w_;
    h = h_;
    posx = x;
    posy = y;
}

QRectF props::boundingRect() const //  implementación de boudingRect() para delimitar con un rectangulo
{
    return QRectF( posx, posy,w,h); //El rectángulo se crea con coordenadas (posx, posy) y tamaño (w, h), área en la que se dibuja la pared
}

void props::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::darkBlue);
    //painter->drawRect(boundingRect());
    QPen pen(Qt::blue); // Crear un QPen con color azul
    pen.setWidth(4); // Establecer el ancho de línea a 3
    painter->setPen(pen); // Configurar el QPen en el QPainter
    painter->setBrush(Qt::white); // Deshabilitar el relleno
    qreal radius = 5.0; // Radio de curvatura de las esquinas
    painter->drawRoundedRect(boundingRect(), radius, radius); // Dibujar rectángulo con esquinas redondeadas

}
