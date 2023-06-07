#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsItem>
#include <QPainter>

#include <utility>
#include <cmath>


/*
 * Para tener en cuenta las colisiones con el piso del jugador, se tiene el bool onFall que debe
 * permanecer en 0 cuando el jugador está sobre alguna plataforma y en 1 si está cayendo (cuando salta
 * o cae de alguna plataforma. Este bool se modifica de acuerdo a las colisiones de la hitbox del player
 * Cuando este bool está en false, no hay aceleración vertical hacia abajo.
 */

class player : public QGraphicsItem
{
public:
    player(float, float); // El constructor recibe la posición inicial del jugador

    QRectF boundingRect() const; // Forma del objeto (forma rectángular)
    void paint(QPainter *painter,
       const QStyleOptionGraphicsItem *option, QWidget *widget); // Para pintar los objetos en pantalla

    void actForce(std::pair<float, float>); // Input: fuerza aplicada al jugador. Modela el movimiento.

    // GET AND SET METHODS
    void setOnfall(bool);
    bool getOnfall();

    std::pair<float, float> getPos();
    std::pair<float, float> getVel();

    void setVelX(float);
    void setVelY(float);
    void setPosX(float);
    void setPosY(float);

    char getCurrentWeapon();
    int getHealth();
    void setHealth(int);

    void setCooldownDisparo(bool);
    bool getCooldownDisparo();

    char getPickUp();
    void setPickUp(char);


private:
    // ESTOS SON LOS PARÁMETROS QUE AFECTAN EL MOVIMIENTO DEL JUGADOR
    bool onFall; // Ver comentario arriba
    const float masa = 5; // masa del jugador
    const float dt = 0.5; // cambio de tiempo en cada actualización
    // Este es el tamaño del jugador. Se usa en boundingRect() y paint() (ver player.cpp)
    // Hay varias partes del código que deben ser modificadas si cambia estos valores :(
    QRectF hitbox = QRectF(-10,-25,20,50);

    int vida; // La vida del jugador está entre 0 y 500

    bool cooldownDisparo;

    char pickUpActivado; // N: no pickUp, V: vida: A: aumentar velocidad

protected:
    /* Protected significa que las clases derivadas de player (proyectil) van a poder
     * acceder a las variables o funciones miembro específicadas bajo esta keyword
     */

    std::pair<float, float> pos; // posición, velocidad, aceleración
    std::pair<float, float> vel;
    std::pair<float, float> acc;

    // Actualizar la posición, velocidad
    void actPos();
    void actVel();

    /* Este char describe el arma que tiene equipada el jugador. Las posibles opciones son
     * D: Desert Eagle
     * En el constructor se establese que el arma inicial es la Desert Eagle.
     */
    char arma;
};

#endif // PLAYER_H
