#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGame())); // Conectar la señal del timeout del timer con el slot updateGame
    connect(this, SIGNAL(collision(player*&,QGraphicsRectItem*&)), this, SLOT(collisionDetected(player*&,QGraphicsRectItem*&)));
    timer->start(10); // Iniciar el timer con un timeout de 10ms

    // LAS COORDENADAS VISIBLES SON ENTRE (-500, 500) Y (500, 500)
    scene = new QGraphicsScene(-500, -500, 1000, 1000);
    ui->graphicsView->setScene(scene);

    //CREAR JUGADORES
    player1 = new player(0, -26);
    scene->addItem(player1);

    //CREAR MAPA
    rectangle = new QGraphicsRectItem(0, 0, 20, 900); // pared izquierda
    rectangle->setPos(-450, -450);
    rectangulosMapa.push_back(rectangle);

    rectangle = new QGraphicsRectItem(0, 0, 20, 900); // pared derecha
    rectangle->setPos(450, -450);
    rectangulosMapa.push_back(rectangle);

    rectangle = new QGraphicsRectItem(0, 0, 900, 20); //piso
    rectangle->setPos(-450, 0);
    rectangulosMapa.push_back(rectangle);

    rectangle = new QGraphicsRectItem(0, 0, 900, 20); //techo
    rectangle->setPos(-450, -300);
    rectangulosMapa.push_back(rectangle);

    rectangle = new QGraphicsRectItem(0, 0, 200, 20); //plataforma mitad del mapa
    rectangle->setPos(-100, -200);
    rectangulosMapa.push_back(rectangle);

    foreach(QGraphicsRectItem* rect, rectangulosMapa) {
        scene->addItem(rect);
    }
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
     * presionen los botones para moverse en estas direcciones (y no se choque con una pared).
     *
     * Los saltos se modelan dándo una velocidad inicial hacia arriba en y (float viSalto).
     *
     *
     * Recuerde que el eje y aumenta hacia abajo (disminuye hacia arriba).
     */

    //TODO: usar un vector con jugadores para reusar el código cuando se añadan más
    // Fuerza total sobre el jugador 1
    float p1forceX = 0;
    float p1forceY = 0;


    /*
     * PARÁMETROS QUE DESCRIBEN EL MOVIMIENTO
     */
    float fuerzaHorizontal = 4; // Magnitud de fuerza que exprimenta el jugador al moverse en x
    float friccionHorizontal = 7.5; // Magnitud de la fricción del piso
    float viSalto = -40; // Velocidad inicial vertical hacia arriba de cada salto
    float gravity = 10; // Fuerza de la gravedad



    /*
     * CALCULAR MOVIMIENTO EN X
     */
    std::pair<float, float> velPlayer = player1->getVel(); // Obtener velocidad del jugador
    if(p1MovIz && p1MovDer){
        p1forceX = 0;
    } else if(p1MovIz){
        p1forceX = -1 * fuerzaHorizontal;
        /* Si el jugador se quiere mover hacia la izquierda pero tiene velocidad hacia la derecha,
         * se agrega la fuerza de fricción hacia la izquierda que existiría normalmente al tener
         * velocidad horizontal hacia la derecha.
         * Esto se aplica en dirección contraria (ver siguiente bloque else if).
         */
        if(velPlayer.first > 0) p1forceX += -1*friccionHorizontal;
    } else if(p1MovDer){
        p1forceX = fuerzaHorizontal;
        if(velPlayer.first < 0) p1forceX += friccionHorizontal;
    }
    // Si el jugador no está experimentando ninguna fuerza horizontal, se frena
    if(p1forceX == 0){
        // Si la velocidad en x es considerable se aplica fuerza de fricción
        if(std::abs(velPlayer.first) > 1.5){
            if(velPlayer.first > 0) p1forceX += -1 * friccionHorizontal;
            else if (velPlayer.first < 0) p1forceX = friccionHorizontal;

        } else if(std::abs(velPlayer.first) <= 1.5) player1->setVelX(0); // Se para al jugador
    }



    /*
     * CALCULAR MOVIMIENTO EN Y
     */
    if(!player1->getOnfall() && p1jump){
    // Si el jugador no está en el aire y se presiona el botón de salto, el jugador salta
        player1->setVelY(viSalto);
        player1->setOnfall(true);
    }

    if(player1->getOnfall()){
        p1forceY = gravity;
    }else if (!player1->getOnfall()){
        p1forceY = 0;
    }



    /*
     * DETECTAR COLISIONES
     */
    foreach(QGraphicsRectItem* rect, rectangulosMapa) {
        if(player1->collidesWithItem(rect)) emit collision(player1, rect);
    }



    /*
     * ACTUALIZAR MOVIMIENTO DE LOS JUGADORES
     */
    player1->actForce(std::make_pair(p1forceX, p1forceY));
    player1->setPos(player1->getPos().first, player1->getPos().second);
    // debug
    std::cout << "pos: " <<  player1->getPos().first <<", " <<  player1->getPos().second;
    std::cout << " // vel: " <<  player1->getVel().first <<", " <<  player1->getVel().second << std::endl;
}





void MainWindow::collisionDetected(player* & player, QGraphicsRectItem* & rectItem)
{
    /* Este método se llama cuando una colisión entre el jugador y un elemento del mapa
     * es detectada. Le quita la velocidad al jugador en dirección al objeto y deja
     * al jugador a una distancia de 1 pixel del objeto en cuestión.
     */

    /* COMENTARIO PARA SEBAS CUANDO EMPIECE A PROGRAMAR MAÑANA:
     * TODOOOOOOOOOOOOOOOOOOOOO:
     * HAY MERO BUG QUE CREO QUE ES CAUSADO PORQUE CUANDO SE ESTÁ YENDO MUY RÁPIDO EN X
     * (Y HAY UN CHOQUE CON UNA PARED HORIZONTAL)
     * Y AL MISMO TIEMPO SE ESTÁ EN MEDIO DE UN SALTO, COMO SE ALCANZA A METER DENTRO DEL OBJETO
     * UN SEGUNDO, EL PROGRAMA PIENSA QUE ESTÁ "DEBAJO" DEL BLOQUE Y TOMA ESTO COMO UNA
     * COLISIÓN EN Y
     *
     * MENTIRAS JAJA YA LO ARREGLÉ... PERO CON LA LÍNEA DE CÓDIGO MÁS LARGA Y COCHINA DEL MUNDO...
     * DIVIDA ESO EN VARIOS BOOLS PARA HACERLO MÁS FÁCIL DE LEER POR FAVOR Y GRACIAS :)
     *
     * TODOOOOOOOOOO2: ARREGLAR EL HECHO DE QUE EL MK SE QUEDA EN EL AIRE LUEGO DE ESTAR
     * PARADO EN UNA PLATAFORMA
     */

    //Tipo de colisión
    char collisionType = 'N'; // Valores posibles: N: no específicado, Y: en Y, X: en X

    // Dimensiones del jugador
    float playerHeight = 50;
    float playerWidth = 20;

    std::cout << "Collision detected!" << std::endl;
    std::cout << rectItem->pos().x() << ", " << rectItem->pos().y() << " ...rectanglepos" << std::endl;
    QRectF boundRect = rectItem->boundingRect();
    std::cout << boundRect.width() << ", " << boundRect.height() << " ...rectangledimensions" << std::endl;

    // Hallar la distancia entre el centro del rectángulo y sus extremos
    float radioY = (boundRect.height()-1)/2; // boundRect.height() retorna el verdadero ancho + 1
    float radioX = (boundRect.width()-1)/2;
    // Hallar el centro del rectángulo con el que colisiona el jugador
    float centerRectX = rectItem->pos().x() + radioX;
    float centerRectY = rectItem->pos().y() + radioY;
    std::cout << centerRectX << ", " << centerRectY << "... rectangle center" << std::endl;

    // COLISIONES EN Y
    if(player->getOnfall() && ( player->getPos().first < centerRectX + radioX && player->getPos().first > centerRectX - radioX ) && ( player1->getPos().second > centerRectY + radioY || player1->getPos().second < centerRectY - radioY)){
    // Si el jugador está cayendo y está debajo del rectángulo...

        if(std::abs(player->getPos().second - centerRectY) < radioY + (playerHeight/2) ){
        //Si hay colisión vertical...
            collisionType = 'Y';

            if(player->getPos().second < centerRectY){
            // Si el jugador está por encima del rectángulo...
                player->setPosY( centerRectY - radioY - 1 - (playerHeight / 2) );
                player->setVelY(-1); // ESTO DEBERÍA SER 0 PERO QT APARENTEMENTE LE SUMA 1 PORQUE SÍ
                player->setOnfall(false);

            }else if(player->getPos().second > centerRectY){
            // Si el jugador está por debajo del rectángulo
                player->setPosY( centerRectY + radioY + 1 + (playerHeight/2) );
                player->setVelY(0);
                // Note que onFall sigue siendo true (el jugador sigue cayendo)
            }else{
            // Si el jugador está en la misma posición en Y que el rectángulo
                std::cout << "ERRORRRRRRRRRRRRRRRRRRRR EN collisionDetected()" << std::endl;
            }
        }
    }

    // COLISIONES EN X
    if(std::abs(player->getPos().first - centerRectX) < radioX + (playerWidth/2) && collisionType != 'Y' ){
    //Si hay colisión horizontal...

        if(player->getPos().first < centerRectX){
        //Si el jugador está a la izquierda del rectángulo...
            player->setPosX(centerRectX - radioX - 1 - (playerWidth/2));
            player->setVelX(0);
        } else if(player->getPos().first > centerRectX){
        //Si el jugador está a la derecha del rectángulo...
            player->setPosX(centerRectX + radioX +1 + (playerWidth/2));
            player->setVelX(0);
        } else{
            // Si el jugador está en la misma posición en X que el rectángulo
                std::cout << "ERRORRRRRRRRRRRRRRRRRRRR EN collisionDetected()" << std::endl;
        }
    }

    player1->setPos(player1->getPos().first, player1->getPos().second);
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_A) // Si la tecla presionada es la A
    {
        p1MovIz = true;
    }
    else if(ev->key()==Qt::Key_D)
    {
        p1MovDer= true;
    }
    else if(ev->key()==Qt::Key_W)
    {
        p1jump = true;
    }
    else if(ev->key()==Qt::Key_S)
    {
        p1crouch = true;
    }
}
void MainWindow::keyReleaseEvent(QKeyEvent *ev){

    if(ev->key()==Qt::Key_A) // Si la tecla presionada es la A
    {
        p1MovIz = false;
    }
    else if(ev->key()==Qt::Key_D)
    {
        p1MovDer= false;
    }
    else if(ev->key()==Qt::Key_W)
    {
        p1jump = false;
    }
    else if(ev->key()==Qt::Key_S)
    {
        p1crouch = false;
    }
}
