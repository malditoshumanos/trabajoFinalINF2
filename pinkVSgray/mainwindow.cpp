#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //TIMERS, SEÑALES

    // Conectar la señal del timeout del timer con el slot updateGame
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGame()));
    timer->start(10); // Iniciar el timer con un timeout de 10ms

    // Conectar la señal y el slot de detección de colisiones en el mapa
    connect(this, SIGNAL(collision(player*,props*)), this, SLOT(collisionDetected(player*,props*)));

    // Señales y slots del cooldown de las armas
    addCooldownTimer = new QTimer();
    cooldownTimers.push_back(addCooldownTimer);
    addCooldownTimer = new QTimer();
    cooldownTimers.push_back(addCooldownTimer);
    connect(cooldownTimers[0], SIGNAL(timeout()), this, SLOT(cooldownEndedP1()));
    connect(cooldownTimers[1], SIGNAL(timeout()), this, SLOT(cooldownEndedP2()));

    // Señal y slot de detección de disparos recibidos por un jugador
    connect(this, SIGNAL(colisionProyectil(player*,int)), this, SLOT(disparoRecibido(player*,int)));

    // Señal y slot de detección de disparos recibidos por un prop
    connect(this, SIGNAL(colisionDisparoProp(propsLife*,int)), this, SLOT(propDisparoRecibido(propsLife*,int)));

    // Señal y slot de recoger pickUps
    connect(this, SIGNAL(colisionPickUp(player*,char, int)), this, SLOT(recogioPickUp(player*,char, int)));

    // Señal y slot del timer de los pickups
    addPickUpTimer = new QTimer();
    pickUpTimers.push_back(addPickUpTimer);
    addPickUpTimer = new QTimer();
    pickUpTimers.push_back(addPickUpTimer);
    connect(pickUpTimers[0], SIGNAL(timeout()), this, SLOT(pickUpEndedP1()));
    connect(pickUpTimers[1], SIGNAL(timeout()), this, SLOT(pickUpEndedP2()));

    // señal y slot de spawnear pickups
    spawnPickUpTimer = new QTimer();
    connect(spawnPickUpTimer, SIGNAL(timeout()), this, SLOT(spawnPickUp()));
    spawnPickUpTimer->start(5000);




    // LAS COORDENADAS VISIBLES SON ENTRE (-500, 500) Y (500, 500)
    scene = new QGraphicsScene(-500, -500, 1000, 1000);
    ui->graphicsView->setScene(scene);
    scene->setBackgroundBrush(QBrush(QImage(":/images/back.png")));
    //scene->setBackgroundBrush(QBrush(Qt::white));

    //CREAR JUGADORES
    //TODO: CUANDO LA POS EN X INICIAL NO ES 0, LAS LINEAS VERT SALEN CORRIDAS
    playerAdd = new player(0, -26);
    jugadores.push_back(playerAdd);

    playerAdd = new player(0, -26);
    jugadores.push_back(playerAdd);

    foreach (player* currentPlayer, jugadores) {
        scene->addItem(currentPlayer);
    }

    //CREAR MAPA
    props* propToAdd;

    propToAdd = new props(20, 1700, 0, 0); // pared izquierda
    propToAdd->setPos(-800, -600);
    propsMapa.push_back(propToAdd);

    propToAdd = new props(20, 1700, 0, 0); // pared derecha
    propToAdd->setPos(780, -600);
    propsMapa.push_back(propToAdd);

    propToAdd = new props(650, 40, 0, 0); // piso izq
    propToAdd->setPos(-780, 415);
    propsMapa.push_back(propToAdd);

    propToAdd = new props(100, 40, 0, 0); // piso centro
    propToAdd->setPos(-50, 415);
    propsMapa.push_back(propToAdd);

    propToAdd = new props(650, 40, 0, 0); // piso der
    propToAdd->setPos(150, 415);
    propsMapa.push_back(propToAdd);


    propToAdd = new props(300, 40, 0, 0); // plataforma mitad - izq
    propToAdd->setPos(-450, 100);
    propsMapa.push_back(propToAdd);

    propToAdd = new props(300, 40, 0, 0); // plataforma mitad - der
    propToAdd->setPos(150, 100);
    propsMapa.push_back(propToAdd);

    propToAdd = new props(300, 40, 0, 0); // plataforma mitad - izq
    propToAdd->setPos(-780, -200);
    propsMapa.push_back(propToAdd);

    propToAdd = new props(300, 40, 0, 0); // plataforma mitad - der
    propToAdd->setPos(480, -200);
    propsMapa.push_back(propToAdd);


    propToAdd = new props(1200, 40, 0, 0); // plataforma techo
    propToAdd->setPos(-600, -400);
    propsMapa.push_back(propToAdd);

    propToAdd = new props(2000, 20, 0, 0); // techo
    propToAdd->setPos(-780, -564);
    propsMapa.push_back(propToAdd);


    for (props* propAct : propsMapa) {
        scene->addItem(propAct);
    }

    //Props Destructibles
    propsLife* propDestructAdd;

    propDestructAdd = new propsLife(60, 60, 0, 0, 200);
    propDestructAdd->setPos(200, 355);
    propsMapaDestructibles.push_back(propDestructAdd);

    propDestructAdd = new propsLife(60, 60, 0, 0, 200);
    propDestructAdd->setPos(450, 355);
    propsMapaDestructibles.push_back(propDestructAdd);


    propDestructAdd = new propsLife(60, 60, 0, 0, 200);
    propDestructAdd->setPos(-400, 355);
    propsMapaDestructibles.push_back(propDestructAdd);


    propDestructAdd = new propsLife(60, 60, 0, 0, 200);
    propDestructAdd->setPos(-600, 355);
    propsMapaDestructibles.push_back(propDestructAdd);


    propDestructAdd = new propsLife(60, 60, 0, 0, 200);
    propDestructAdd->setPos(-400, 45);
    propsMapaDestructibles.push_back(propDestructAdd);


    propDestructAdd = new propsLife(60, 60, 0, 0, 200);
    propDestructAdd->setPos(250, 45);
    propsMapaDestructibles.push_back(propDestructAdd);

    propDestructAdd = new propsLife(60, 60, 0, 0, 200);
    propDestructAdd->setPos(-400, -460);
    propsMapaDestructibles.push_back(propDestructAdd);


    propDestructAdd = new propsLife(60, 60, 0, 0, 200);
    propDestructAdd->setPos(90, -460);
    propsMapaDestructibles.push_back(propDestructAdd);

    propDestructAdd = new propsLife(60, 60, 0, 0, 200);
    propDestructAdd->setPos(-30, -460);
    propsMapaDestructibles.push_back(propDestructAdd);

    propDestructAdd = new propsLife(60, 60, 0, 0, 200);
    propDestructAdd->setPos(350, -460);
    propsMapaDestructibles.push_back(propDestructAdd);


    for (propsLife* propAct : propsMapaDestructibles) {
        scene->addItem(propAct);
    }

    // Añadir pickUps
    /*
    pickUps* pickUpAdd;

    pickUpAdd = new pickUps(30, 30, 0, 0, 'I');
    pickUpAdd->setPos(-100, -30);
    mapPickUps.push_back(pickUpAdd);

    for (pickUps*  pickUpAct: mapPickUps) {
        scene->addItem(pickUpAct);
    }*/


    // Crear lineas verticales para chequear si el jugador está en el aire
    foreach (player* player1, jugadores) {
        line = new QGraphicsLineItem(player1->getPos().first, player1->getPos().second, player1->getPos().first  , (player1->getPos().second + 25 + 3));
        //std::cout << "VEAAAA: " << player1->getPos().first;
        verticalLines.push_back(line);
        scene->addItem(verticalLines.back());
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

    for(int i = 0; i < 2; i++){
        player* playerAct = jugadores[i];
        char pickUpPlayer = playerAct->getPickUp();

        // Fuerza total sobre el jugador 1
        float p1forceX = 0;
        float p1forceY = 0;

        //Implementación de la invencibilidad
        if(pickUpPlayer == 'I') playerAct->setHealth(500);


        /*
         * PARÁMETROS QUE DESCRIBEN EL MOVIMIENTO DEL JUGADOR
         */
        float fuerzaHorizontal = 4; // Magnitud de fuerza que exprimenta el jugador al moverse en x
        if(pickUpPlayer == 'A') fuerzaHorizontal = 12; // Si hay aumento de velocidad
        float friccionHorizontal = 7.5; // Magnitud de la fricción del piso
        float viSalto = -40; // Velocidad inicial vertical hacia arriba de cada salto
        float gravity = 10; // Fuerza de la gravedad



        /*
         * CALCULAR MOVIMIENTO EN X
         */
        std::pair<float, float> velPlayer = playerAct->getVel(); // Obtener velocidad del jugador
        if(pMovIz[i] && pMovDer[i]){
            p1forceX = 0;
        } else if(pMovIz[i]){
            p1forceX = -1 * fuerzaHorizontal;
            /* Si el jugador se quiere mover hacia la izquierda pero tiene velocidad hacia la derecha,
             * se agrega la fuerza de fricción hacia la izquierda que existiría normalmente al tener
             * velocidad horizontal hacia la derecha.
             * Esto se aplica en dirección contraria (ver siguiente bloque else if).
             */
            if(velPlayer.first > 0) p1forceX += -1*friccionHorizontal;
        } else if(pMovDer[i]){
            p1forceX = fuerzaHorizontal;
            if(velPlayer.first < 0) p1forceX += friccionHorizontal;
        }
        // Si el jugador no está experimentando ninguna fuerza horizontal, se frena
        if(p1forceX == 0){
            // Si la velocidad en x es considerable se aplica fuerza de fricción
            if(std::abs(velPlayer.first) > 1.5){
                if(velPlayer.first > 0) p1forceX += -1 * friccionHorizontal;
                else if (velPlayer.first < 0) p1forceX = friccionHorizontal;

            } else if(std::abs(velPlayer.first) <= 1.5) playerAct->setVelX(0); // Se para al jugador
        }



        /*
         * CALCULAR MOVIMIENTO EN Y
         */

        // Determinar si el jugador está parado sobre una plataforma
        if(!playerAct->getOnfall()){
            bool playerEnElAire = true;
            verticalLines[i]->setPos(playerAct->getPos().first, (playerAct->getPos().second + 50 + 3));
            for(int iRect = 0; iRect < propsMapa.size(); iRect++){
                if( verticalLines[i]->collidesWithItem(propsMapa[iRect]) ){
                    playerEnElAire = false;
                    break;
                }
            }
            for(int iRect = 0; iRect < propsMapaDestructibles.size(); iRect++){
                if( verticalLines[i]->collidesWithItem(propsMapaDestructibles[iRect]) ){
                    playerEnElAire = false;
                    break;
                }
            }
            playerAct->setOnfall(playerEnElAire);

        }


        if(!playerAct->getOnfall() && pJump[i]){
        // Si el jugador no está en el aire y se presiona el botón de salto, el jugador salta
            playerAct->setVelY(viSalto);
            playerAct->setOnfall(true);
        }


        if(playerAct->getOnfall()){
            p1forceY = gravity;
        }else if (!playerAct->getOnfall()){
            p1forceY = 0;
        }




        /*
         * DETECTAR COLISIONES ENTRE JUGADOR y ELEMENTOS DEL MAPA y PROYECTILES
         */
        // Colisión jugador-prop indestructible
        foreach(props* rect, propsMapa) {
            if(playerAct->collidesWithItem(rect)) emit collision(playerAct, rect);
        }
        for (propsLife* propAct : propsMapaDestructibles) {
            if(playerAct->collidesWithItem(propAct)) emit collision(playerAct, propAct);
        }

        // Colisión jugador - proyectil y prop destructible - proyectil
        for (const auto& proyectilPtr : proyectilVector) {
            if(playerAct->collidesWithItem(proyectilPtr.get())){
                int damageDealt = proyectilPtr->getDamage();

                // Si el disparo conecta, la bala ya no se considera
                proyectilPtr->makeDamageZero();
                //scene->removeItem(proyectilPtr.get());
                emit colisionProyectil(playerAct, damageDealt);
            }

            /* Colisión proyectil - prop destructible
             * Si un prop destructible es destruído, este debe quitarse del vector que contiene
             * todos los props de este tipo para que deje de ser considerado en las colisiones.
             */
            int contPropsDestruc = 0;
            int propToErase = -7;
            for (propsLife* propAct : propsMapaDestructibles) {
                if(propAct->collidesWithItem(proyectilPtr.get())){
                    int damageAlProp = proyectilPtr->getDamage();
                    proyectilPtr->makeDamageZero();
                    emit colisionDisparoProp(propAct, damageAlProp);
                }
                if(propAct->getLife()<=0) propToErase = contPropsDestruc;
                contPropsDestruc++;
            }
            if(propToErase != -7) propsMapaDestructibles.erase(propsMapaDestructibles.begin() + propToErase - 1);
        }

        // Colisión jugador-pickUp
        int contPickUp = 0;
        int pickUpRecogido = -7;
        for (pickUps* pickUpAct : mapPickUps) {
            if(playerAct->collidesWithItem(pickUpAct)){
                char pickUpId = pickUpAct->getId();
                emit colisionPickUp(playerAct, pickUpId, i);
                scene->removeItem(pickUpAct);
                pickUpRecogido = contPickUp;
            }
            contPickUp++;
        }
        if(pickUpRecogido != -7) mapPickUps.erase(mapPickUps.begin() + pickUpRecogido -1);



        /*
         * ACTUALIZAR MOVIMIENTO DE LOS JUGADORES
         */

        // Implementación del jetpack
        if(pickUpPlayer == 'J' && pJump[i]){
            playerAct->setVelY(-9);
            playerAct->setOnfall(true);
        }

        playerAct->actForce(std::make_pair(p1forceX, p1forceY));
        playerAct->setPos(playerAct->getPos().first, playerAct->getPos().second);
        // debug
        //std::cout << "pos: " <<  player1->getPos().first <<", " <<  player1->getPos().second;
        //std::cout << " // vel: " <<  player1->getVel().first <<", " <<  player1->getVel().second << std::endl;



        /* DISPAROS
         */

        // Disparar
        // Implementación de la metralleta
        if(pickUpPlayer == 'M'){
            playerAct->setCooldownDisparo(false);
        }

        if(pShooting[i] && !playerAct->getCooldownDisparo()){
            std::cout << "DISPARANDOOOOOOOOOO" << std::endl;
            float xPlayer = playerAct->getPos().first;
            float yPlayer = playerAct->getPos().second;
            std::cout << yPlayer << std::endl;
            float playerWidth = 20;

            //Añadir proyectil a la escena
            std::unique_ptr<proyectil> ptr = std::make_unique<proyectil>( (xPlayer + ( (-1*!pDirDisparo[i]) + (1*pDirDisparo[i]) )*(playerWidth/2)), yPlayer, pDirDisparo[i], playerAct->getCurrentWeapon());
            proyectilVector.push_back(std::move(ptr));
            scene->addItem(proyectilVector.back().get());

            playerAct->setCooldownDisparo(true);
            cooldownTimers[i]->start(300);
        }
        // Actualizar movimiento de los proyectiles
        for (const auto& proyectilPtr : proyectilVector) {
            proyectilPtr->actualizarMov();
            proyectilPtr->setPos(proyectilPtr->getPos().first, proyectilPtr->getPos().second);
        }

    }

}





void MainWindow::collisionDetected(player*  player, props*  rectItem)
{
    /* Este método se llama cuando una colisión entre el jugador y un elemento del mapa
     * es detectada. Le quita la velocidad al jugador en dirección al objeto y deja
     * al jugador a una distancia de 1 pixel del objeto en cuestión.
     */

    //Tipo de colisión
    char collisionType = 'N'; // Valores posibles: N: no específicado, Y: en Y, X: en X

    // Dimensiones del jugador
    float playerHeight = 100;
    float playerWidth = 40;

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
    //Chequear si el jugador está en X dentro de los límites del rectángulo
    bool isInRectInX = player->getPos().first < centerRectX + radioX && player->getPos().first > centerRectX - radioX;
    //Chequear si el jugador está encima o debajo del rectángulo (en Y)
    bool isOutRectInY = player->getPos().second > centerRectY + radioY || player->getPos().second < centerRectY - radioY;

    if(player->getOnfall() && isInRectInX && isOutRectInY){
    // Si el jugador está cayendo y tiene posición adecuada para colisión verical...

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

    player->setPos(player->getPos().first, player->getPos().second);
}

void MainWindow::cooldownEndedP1()
{
    jugadores[0]->setCooldownDisparo(false);
}

void MainWindow::cooldownEndedP2()
{
    jugadores[1]->setCooldownDisparo(false);
}

void MainWindow::disparoRecibido(player *playerAct, int damage)
{
    playerAct->setHealth( playerAct->getHealth() - damage );
    //std::cout << "newHealth: " << playerAct->getHealth() << std::endl;
    if(playerAct->getHealth() <= 0){
        scene->removeItem(playerAct);
    }
}

void MainWindow::propDisparoRecibido(propsLife *propAct, int damage)
{
    propAct->decreaseLife(damage);
    if(propAct->getLife() <= 0){
        scene->removeItem(propAct);
    }
}

void MainWindow::recogioPickUp(player *playerAct, char pickUpId, int player1or2)
{
    if(pickUpId == 'A' || pickUpId == 'J' || pickUpId == 'I'){
        playerAct->setPickUp(pickUpId);
        if(player1or2 == 0){
            pickUpTimers[0]->start(8000);
        } else if(player1or2 == 1){
            pickUpTimers[1]->start(8000);
        }
    } else if (pickUpId == 'V'){
        playerAct->setHealth(500);
    } else if(pickUpId == 'M'){
        playerAct->setPickUp(pickUpId);
        if(player1or2 == 0){
            pickUpTimers[0]->start(2500);
        } else if(player1or2 == 1){
            pickUpTimers[1]->start(2500);
        }
    }

}

void MainWindow::pickUpEndedP1()
{
    jugadores[0]->setPickUp('N');
    pickUpTimers[0]->stop();
}

void MainWindow::pickUpEndedP2()
{
    jugadores[1]->setPickUp('N');
    pickUpTimers[1]->stop();
}

void MainWindow::spawnPickUp()
{
    pickUps* pickUpAdd;

    pickUpAdd = new pickUps(30, 30, 0, 0, getRandomChar());
    pickUpAdd->setPos(-100, -30);
    mapPickUps.push_back(pickUpAdd);

    for (pickUps*  pickUpAct: mapPickUps) {
        scene->addItem(pickUpAct);
    }

}

char MainWindow::getRandomChar()
{
    // Create a random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // Define the set of characters
    const char charSet[] = {'V', 'A', 'J', 'M', 'I'};

    // Generate a random index within the range of the character set
    std::uniform_int_distribution<> distrib(0, sizeof(charSet) - 1);
    int randomIndex = distrib(gen);

    std::cout << "RANDOMLY CHOSEN CHAR: " << charSet[randomIndex] << std::endl;

    // Return the randomly chosen character
    return charSet[randomIndex];
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    // *************************JUGADOR 1 ************************************
    // SE CONTROLA CON: W A S D X
    if(ev->key()==Qt::Key_A) // Si la tecla presionada es la A
    {
        pMovIz[0] = true;
        pDirDisparo[0] = false;
    }
    else if(ev->key()==Qt::Key_D)
    {
        pMovDer[0] = true;
        pDirDisparo[0] = true;
    }
    else if(ev->key()==Qt::Key_W)
    {
        pJump[0] = true;
    }
    else if(ev->key()==Qt::Key_S)
    {
        pCrouch[0] = true;
    }

    if(ev->key()==Qt::Key_X){
        pShooting[0] = true;
    }

    // *************************JUGADOR 2 ************************************
    // SE CONTROLA CON: I J K L N
    if(ev->key()==Qt::Key_J)
    {
        pMovIz[1] = true;
        pDirDisparo[1] = false;
    }
    else if(ev->key()==Qt::Key_L)
    {
        pMovDer[1] = true;
        pDirDisparo[1] = true;
    }
    else if(ev->key()==Qt::Key_I)
    {
        pJump[1] = true;
    }
    else if(ev->key()==Qt::Key_K)
    {
        pCrouch[1] = true;
    }

    if(ev->key()==Qt::Key_N){
        pShooting[1] = true;
    }

}
void MainWindow::keyReleaseEvent(QKeyEvent *ev){
    // *************************JUGADOR 1 ************************************
    if(ev->key()==Qt::Key_A) // Si la tecla presionada es la A
    {
        pMovIz[0] = false;
    }
    else if(ev->key()==Qt::Key_D)
    {
        pMovDer[0] = false;
    }
    else if(ev->key()==Qt::Key_W)
    {
        pJump[0] = false;
    }
    else if(ev->key()==Qt::Key_S)
    {
        pCrouch[0] = false;
    }

    if(ev->key()==Qt::Key_X){
        pShooting[0] = false;
    }

    // *************************JUGADOR 2 ************************************
    if(ev->key()==Qt::Key_J)
    {
        pMovIz[1] = false;
    }
    else if(ev->key()==Qt::Key_L)
    {
        pMovDer[1] = false;
    }
    else if(ev->key()==Qt::Key_I)
    {
        pJump[1] = false;
    }
    else if(ev->key()==Qt::Key_K)
    {
        pCrouch[1] = false;
    }

    if(ev->key()==Qt::Key_N){
        pShooting[1] = false;
    }
}
