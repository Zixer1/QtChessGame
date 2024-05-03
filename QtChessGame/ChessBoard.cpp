// ChessBoard.cpp: Manages the chessboard's state, including piece locations and move validation, check kingpos, etc.
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QDebug>

#include "ChessBoard.h"

ChessBoard::ChessBoard(QGraphicsScene* sceneOut, QWidget* parent) : QGraphicsView(parent) {
    squareCount = 0;
    scene = sceneOut;

    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            Square* createSquare = new Square(data_model::Position(x + 1, y + 1), Piece(PieceType::Null), sceneOut);
            // Keep track of the square
            existingSquares[x][y] = createSquare; // Assign the pointer to existingSquares
            squareCount += 1;
        }
    }
}
ChessBoard::~ChessBoard() {
	
}


// Methods for initializing the board, updating the board state, and checking for valid moves.
