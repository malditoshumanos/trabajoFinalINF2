#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer> // Para actualizar el estado del juego cada cierto tiempo
#include <QKeyEvent> // Para manejar los eventos relacionados con presionar y soltar teclas

#include "player.h"


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

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;

    // Jugadores
    player* player1;
    player* player2;

    QTimer *timer; // Timer para actualizar el juego

    // Eventos(metodos) de presionar y soltar teclas
    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);
    bool p1MovIz; // Player 1 moviéndose a la izquierda, la derecha, saltando o agachándose
    bool p1MovDer;
    bool p1jump;
    bool p1crouch;


};
#endif // MAINWINDOW_H
