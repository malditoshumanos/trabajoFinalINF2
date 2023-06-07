#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer> // Para actualizar el estado del juego cada cierto tiempo
#include <QKeyEvent> // Para manejar los eventos relacionados con presionar y soltar teclas
#include <QPointF>
#include <QGraphicsLineItem>

#include <vector>
#include <memory>
#include <random>


#include "player.h"
#include "proyectil.h"
#include "props.h"
#include "propsLife.h"
#include "pickUps.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void updateGame();    

    // Colisión entre jugador y elementos del mapa
    void collisionDetected(player*  player, props*  rectItem);

    // Método para implementar el cooldown timer de las armas
    void cooldownEndedP1();
    void cooldownEndedP2();

    // Método para modelar el sistema de vida del jugador
    void disparoRecibido(player* playerAct, int damage);

    // Método para modelar el daño hecho a los props destructibles
    void propDisparoRecibido(propsLife *propAct, int damage);

    // Método para modelar recoger pickups
    void recogioPickUp(player* playerAct, char pickUpId, int player1or2);

    // Método para modelar la duración de los pickups
    void pickUpEndedP1();
    void pickUpEndedP2();

    void spawnPickUp();

signals:

    // Método para modelar recoger pickups
    void colisionPickUp(player* playerAct, char pickUpId, int player1or2);

    // Colisión entre jugador y elementos del mapa
    void collision(player*  player, props*  rectItem);

    // Método para modelar el sistema de vida del jugador
    void colisionProyectil(player* playerAct, int damage);

    // Método para modelar el daño hecho a los props destructibles
    void colisionDisparoProp(propsLife* propAct, int damage);



private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;

    // Jugadores
    player* playerAdd;
    std::vector<player*> jugadores;

    QTimer *timer; // Timer para actualizar el juego
    //Timers para manejar el cooldown
    QTimer *addCooldownTimer;
    std::vector<QTimer*> cooldownTimers;

    // Timers para manejar el tiempo del pickup
    QTimer *addPickUpTimer;
    std::vector<QTimer*> pickUpTimers;

    // Timers para spawnear los pickups
    QTimer *spawnPickUpTimer;


    // Eventos(metodos) de presionar y soltar teclas
    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);
    std::vector<bool> pMovIz = {false, false};
    std::vector<bool> pMovDer = {false, false};
    std::vector<bool> pJump = {false, false};
    std::vector<bool> pCrouch = {false, false};
    std::vector<bool> pShooting = {false, false};
    std::vector<bool> pDirDisparo = {false, false};
    // Consodere inicializar estas variables en el constructor

    // Lineas para chequear si el jugador está en el aire
    std::vector<QGraphicsLineItem*> verticalLines;
    QGraphicsLineItem* line;


    // En este vector se guardan los elementos que conforman el mapa
    std::vector<props*> propsMapa;
    std::vector<propsLife*> propsMapaDestructibles;

    // En este vector se guardan los proyectiles que hay en pantalla
    std::vector<std::unique_ptr<proyectil>> proyectilVector;

    // En este vector se guardan los pickUps en el mapa
    std::vector<pickUps*> mapPickUps;

    // elegir pickup aleatoriamente
    char getRandomChar();


};
#endif // MAINWINDOW_H
