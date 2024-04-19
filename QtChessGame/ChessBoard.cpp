// ChessBoard.cpp: Manages the chessboard's state, including piece locations and move validation.
#include "ChessBoard.h"
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QDebug>

ChessBoard::ChessBoard(int size, QWidget* parent) : QGraphicsView(parent) {
    // Chess board size in pixels
    int chessBoardSize = size;

    // Load the chess board image
    QImage chessBoard;
    if (!chessBoard.load("C:/Users/Alex/source/repos/QtChessGame/QtChessGame/images/PlayingWindow_images/ChessBoards/chessboard1.png")) {
        qDebug() << "Failed to load chess board image.";
    }
    else {
        // Scale the chess board image to the specified dimensions
        chessBoard = chessBoard.scaled(chessBoardSize, chessBoardSize, Qt::KeepAspectRatio);

        QGraphicsPixmapItem* chessBoardItem = new QGraphicsPixmapItem(QPixmap::fromImage(chessBoard));
        scene()->addItem(chessBoardItem); // Adding chess board as a child of the scene
    }
}


// Methods for initializing the board, updating the board state, and checking for valid moves.
