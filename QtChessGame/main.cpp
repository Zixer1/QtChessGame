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

#include "Scene.h"
#include "Square.h"
#include "Position.h"
#include "Piece.h"
#include "PieceType.h"
#include "TempMove.h"

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
        mainScene->gui::Scene::displayChessPiece(Square(data_model::Position(1, 1), Piece(PieceType::BlackKing)));
        mainScene->gui::Scene::displayChessPiece(Square(data_model::Position(2, 2), Piece(PieceType::WhiteKing)));
        // After 5 seconds, the two more kings will try to get added
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

    //3. Test temporary position, only practical test, no display of the pieces moving yet:
    Square test_square{ data_model::Position(4, 4), Piece(PieceType::WhiteKing) };
    data_model::Position test_square_position = test_square.getPosition();
    qDebug() << "Before moving the piece: " << test_square_position.getX() << ", " << test_square_position.getY();
    try {
        {
            data_model::TempMove tempPos(test_square_position, 7, 7); // Temporarily moves to (7, 7)
            qDebug() << "Position is now: " << test_square_position.getX() << ", " << test_square_position.getY();
        } // Position automatically resets to (4, 4) here
    }
    catch (const std::out_of_range& e) {
        qDebug() << e.what();
    }
    qDebug() << "After moving the piece: " << test_square_position.getX() << ", " << test_square_position.getY();




    // There are obviously memory leaks since we have no current way to end the game so:
    // TODO: Implement a way to end the game and delete the scene
    // TODO: Fix the classes to be passed by reference instead of being copied
    

    
    mainScene->show();

    return a.exec();
}
