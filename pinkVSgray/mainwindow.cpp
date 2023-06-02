#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGame())); // Conectar la señal del timeout del timer con el slot updateGame
    timer->start(25); // Iniciar el timer con un timeout de 33ms

    scene = new QGraphicsScene(-500, -500, 1000, 1000);
    ui->graphicsView->setScene(scene);

    player1 = new player(0.0, 0.0);
    scene->addItem(player1);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateGame()
{
    /*
     * En este método se encuentra la fuerza total que exprimenta cada uno de los jugadores
     * y se pasa esta fuerza al método actForce() de cada jugador para actualizar su posición.
     *
     * Note que el jugador acelera indefinidamente hacia la izquierda o la derecha mientras se
     */

    //TODO: usar un vector con jugadores para reusar el código cuando se añadan más
    // Fuerza total sobre el jugador 1
    float p1forceX;
    float p1forceY;

    float fuerzaHorizontal = 2; // Magnitud de fuerza que exprimenta el jugador al moverse en x
    float friccionHorizontal = 5; // Magnitud de la fricción del piso

    if(p1MovIz && p1MovDer){
        p1forceX = 0;
        p1forceY = 0;
    } else if(p1MovIz){
        p1forceX = -1 * fuerzaHorizontal;
    } else if(p1MovDer){
        p1forceX = fuerzaHorizontal;
    } else{
        // Si no se están presionando las teclas de movimiento en x, se frena al jugador
         std::pair<float, float> velPlayer = player1->getVel();
        if(velPlayer.first != 0){ // Si la velocidad en x no es igual a 0...
            if(velPlayer.first > 0){
                p1forceX = -1 * friccionHorizontal;
            } else if (velPlayer.second < 0){
                p1forceX = friccionHorizontal;
            }
        }
    }

    player1->actForce(std::make_pair(p1forceX, 0));
    //TODO: considerar colisiones horizontales con las paredes
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_A) // Si la tecla presionada es la A
    {
        p1MovIz = true;
    }
    else if(ev->key()==Qt::Key_S)
    {
        p1MovDer= true;
    }
    else if(ev->key()==Qt::Key_W)
    {
        p1jump = true;
    }
    else if(ev->key()==Qt::Key_D)
    {
        p1crouch = true;
    }
}
void MainWindow::keyReleaseEvent(QKeyEvent *ev){

    if(ev->key()==Qt::Key_A) // Si la tecla presionada es la A
    {
        p1MovIz = false;
    }
    else if(ev->key()==Qt::Key_S)
    {
        p1MovDer= false;
    }
    else if(ev->key()==Qt::Key_W)
    {
        p1jump = false;
    }
    else if(ev->key()==Qt::Key_D)
    {
        p1crouch = false;
    }
}
