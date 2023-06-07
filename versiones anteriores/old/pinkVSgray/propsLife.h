#ifndef PROPSLIFE_H
#define PROPSLIFE_H

#include "props.h"
#include <QGraphicsTextItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>

class propsLife : public props
{
private:
    int cantidadDeVida; // Atributo adicional específico de propsLife

public:
    //Score(QGraphicsItem *parent = nullptr); // Constructor para dar valor inicial de 0
    propsLife(int w_, int h_, int x, int y, int vida); // Constructor que recibe los parámetros de props y la cantidad de vida

    // Sobrescribir el método paint
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    int getLife();
    void decreaseLife(int); // Método para disminuir la vida
};

#endif // PROPSLIFE_H
