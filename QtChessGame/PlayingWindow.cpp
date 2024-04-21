// PlayingWindow.cpp: Manages the in-game user interface, including board rendering and user interactions.
#include "PlayingWindow.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QImage>
#include <QBrush>
#include <QLabel>
#include <iostream>
#include <fstream>

PlayingWindow::PlayingWindow(QWidget* parent) {
    // Chess board size in pixels, adjust here if needed
    int chessBoardSize{ 800 };

    // Window size in pixels, adjust here if needed
    int windowWidth{ chessBoardSize + 300 };
    int windowHeight{ chessBoardSize };

    // Chess logo size in pixels, adjust here if needed
    int chessLogoSize{ 400 };

    //Setting up the Basic Visual elements: Window Width and Height, scroll bars off, not able to resize.
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, windowWidth, windowHeight);
    setFixedSize(windowWidth, windowHeight);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Setting up the chess board GUI
    QImage chessBoard;
    if (!chessBoard.load("C:/Users/Alex/source/repos/QtChessGame/QtChessGame/images/PlayingWindow_images/ChessBoards/chessboard1.png")) {
        qDebug() << "Failed to load chess board image.";
    }
    else {

        // Scale the chess board image to the specified dimensions
        chessBoard = chessBoard.scaled(chessBoardSize, chessBoardSize, Qt::KeepAspectRatio);

        QGraphicsPixmapItem* chessBoardItem = new QGraphicsPixmapItem(QPixmap::fromImage(chessBoard));
        scene->addItem(chessBoardItem); // Adding chess board as a child of the scene
    }

    // Load the logo
    QImage chessLogo;
    if (!chessLogo.load("C:/Users/Alex/source/repos/QtChessGame/QtChessGame/images/PlayingWindow_images/ChessLogoFinal.png")) {
        qDebug() << "Failed to load chess board image.";
    }
    else {

        chessLogo = chessLogo.scaled(chessLogoSize, chessLogoSize, Qt::KeepAspectRatio);

        QGraphicsPixmapItem* chessLogoItem = new QGraphicsPixmapItem(QPixmap::fromImage(chessLogo));
        chessLogoItem->setPos((chessBoardSize +(windowWidth - chessBoardSize) / 2) - chessLogoSize /2, -25);
        scene->addItem(chessLogoItem); // Adding chess board as a child of the scene
    }

    // Setting up the border between the chess board and the score/pieces left
    QGraphicsRectItem* rect = new QGraphicsRectItem();
    rect->setRect(0, 0, chessBoardSize, chessBoardSize);
    rect->setPen(QPen(Qt::black, 5)); // Make the rectangle thicker
    scene->addItem(rect); // Adding rectangle as a child of the scene

    setScene(scene);
    show();
}




