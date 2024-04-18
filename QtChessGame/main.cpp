// main.cpp: The entry point of the application that sets up the game and manages the main loop.
/*
Main File, for the project overall:
File   main.cpp
Author Alexandre Sakr and Houssam Bousbia
Date   15 April 2024
*/
#include "QtChessGame.h"
#include <QtWidgets/QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QApplication>
#include <QPixmap> // Include QPixmap header for handling images
#include "PlayingWindow.h"

PlayingWindow* playingWindow;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    playingWindow = new PlayingWindow();
    playingWindow->show();


    return a.exec();
}
