// ChessBoard.cpp: Manages the chessboard's state, including piece locations and move validation, check kingpos, etc.
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QDebug>

#include "ChessBoard.h"

ChessBoard::ChessBoard(QWidget* parent) : QGraphicsView(parent) {

    }
ChessBoard::~ChessBoard() {
	
}


// Methods for initializing the board, updating the board state, and checking for valid moves.
