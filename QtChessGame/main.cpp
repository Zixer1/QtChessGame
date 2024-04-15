// main.cpp: The entry point of the application that sets up the game and manages the main loop.
#include "QtChessGame.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtChessGame w;
    w.show();
    return a.exec();
}
