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
#include "Scene.h"
#include <QDebug>
#include <array>
#include "Square.h"
#include "Position.h"
#include "Piece.h"
#include "PieceType.h"
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Since Scene is in the gui namespace, make sure to use it
    gui::Scene* mainScene;



    // Assuming you want to start with the main menu scene, for example
    mainScene = new gui::Scene(2); // 0 could represent the main menu
    if (mainScene->gui::Scene::getCurrentScene() == 2) {
        qDebug() << "Intitializing the Chess Board";
        mainScene->gui::Scene::displayChessBoard(800);
        mainScene->gui::Scene::displayChessLogo(400);
        mainScene->gui::Scene::displayChessPiece(Square(data_model::Position(1, 1), Piece(PieceType::BlackKing)));
        mainScene->gui::Scene::displayChessPiece(Square(data_model::Position(2, 2), Piece(PieceType::WhiteKing)));
        QTimer::singleShot(5000, mainScene, [mainScene]() {
            mainScene->displayChessPiece(Square(data_model::Position(3, 3), Piece(PieceType::BlackKing)));
            mainScene->displayChessPiece(Square(data_model::Position(4, 4), Piece(PieceType::WhiteKing)));
            });
        /*
        Test placing Pieces on the board:
        mainScene->gui::Scene::displayChessPiece(Square(data_model::Position(1, 1), Piece(PieceType::BlackPawn)));
        Edit the Position(1, 1) to place the piece at the desired position
        Edit the Piece(PieceType::BlackPawn) to place the desired piece
        */
    }

    
    mainScene->show();

    return a.exec();
}
