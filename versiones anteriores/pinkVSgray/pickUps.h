#ifndef PICKUPS_H
#define PICKUPS_H

#include "props.h"

class pickUps : public props
{
private:
    char IDpickUp; // Atributo IDpickUp de tipo string

public:
    // Constructor recibe ancho w_, altura h_, coordenadas x e y, y el id del pickup
    pickUps(int w_, int h_, int x, int y, char idPickUp);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override; // Sobrescribir el método paint

    char getId();
};

#endif // PICKUPS_H



