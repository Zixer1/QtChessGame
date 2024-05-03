// ChessBoard.cpp: Manages the chessboard's state, including piece locations and move validation, check kingpos, etc.
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QDebug>

#include "ChessBoard.h"

ChessBoard::ChessBoard(QWidget* parent) : QGraphicsView(parent) {
    int squareCount = 0;
    std::array<std::array<Square, 8>, 8> existingSquares;
    for (int x = 1; x <= 8; ++x) {
        for (int y = 1; y <= 8; ++y) {
            Square createSquare{ data_model::Position(x, y), Piece(PieceType::Null) };
            existingSquares[x - 1][y - 1] = createSquare;
            squareCount += 1;
        }
    }

    }
ChessBoard::~ChessBoard() {
	
}


// Methods for initializing the board, updating the board state, and checking for valid moves.
