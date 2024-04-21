#include "Square.h"
#include "ChessBoard.h" // Include the header file for ChessBoard
#include "Position.h" // Include the header file for Position

int Square::squareCount = 0; // Initialize squareCount

Square::Square(ChessBoard* parentBoard, QWidget* parent) {
    if (squareCount >= 64) {
        throw std::runtime_error("Cannot create more than 64 squares");
    }

    position = Position();
    piece = Piece();
    this->parentBoard = parentBoard;
	squareCount += 1;

}

Square::Square(Position pos, Piece type, ChessBoard* parentBoard, QWidget* parent) {
    if (squareCount >= 64) {
        throw std::runtime_error("Cannot create more than 64 squares");
    }

}

Square::~Square() {
    
    squareCount--;
    // Other cleanup code...
}