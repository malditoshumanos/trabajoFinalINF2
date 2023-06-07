#include "mainwindow.h"

#include <QApplication>

// sprites tomados de https://itch.io/ y https://craftpix.net/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
