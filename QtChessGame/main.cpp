// main.cpp: The entry point of the application that sets up the game and manages the main loop.
/*
Main File, for the project overall:
File   main.cpp
Author Alexandre Sakr and Houssam Bousbia
Date   15 April 2024
*/
#include <QtWidgets/QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QApplication>
#include <QPixmap> // Include QPixmap header for handling images
#include <QDebug>
#include <array>
#include <QTimer>
#include <QGraphicsProxyWidget>


#include "Scene.h"
#include "Square.h"
#include "Position.h"
#include "Piece.h"
#include "PieceType.h"
#include "TempMove.h"
#include "ChessBoard.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    // Since Scene is in the gui namespace, make sure to use it
    gui::Scene* mainScene;
    
    //1. namespaces : data_model, gui

    //2. No more than two kings at once showcase:
    // Assuming you want to start with the main menu scene, for example
    mainScene = new gui::Scene(2); // 0 could represent the main menu
    if (mainScene->gui::Scene::getCurrentScene() == 2) {
        qDebug() << "Intitializing the Chess Board";
        mainScene->gui::Scene::displayChessBoard(800);
        mainScene->gui::Scene::displayChessLogo(400);
        ChessBoard board{ mainScene};


        /*
        Square square1{data_model::Position(1, 1), Piece(PieceType::Null), mainScene->scene};
        Square square2{data_model::Position(2, 2), Piece(PieceType::WhitePawn), mainScene->scene};
        */



        // Create a QGraphicsView to display the scene
        


        /*
        Test placing Pieces on the board:
        mainScene->gui::Scene::displayChessPiece(Square(data_model::Position(1, 1), Piece(PieceType::BlackPawn)));
        Edit the Position(1, 1) to place the piece at the desired position
        Edit the Piece(PieceType::BlackPawn) to place the desired piece
        */
    }

    // There are obviously memory leaks since we have no current way to end the game so:
    // TODO: Implement a way to end the game and delete the scene
    // TODO: Fix the classes to be passed by reference instead of being copied
    

    
    mainScene->show();

    return a.exec();
}
