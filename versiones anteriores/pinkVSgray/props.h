#ifndef PROPS_H
#define PROPS_H

#include <QGraphicsItem>
#include <QPainter>

class props: public QGraphicsItem
{
    // Private:
    int w,h;         // Almacenar el ancho (w) y la altura (h) de prop
    int posx, posy;  // Almacenar las coordenadas x e y de la posición del prop

public:
    props(int w_, int h_, int x, int y); // Constructor recibe ancho w_, altura h_ y las coordenadas x e y de posición del prop
    QRectF boundingRect() const; // delimitador del prop en la escena

    // dibujar el prop en la escena usando un objeto QPainter.
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);


};

#endif // PROPS_H
