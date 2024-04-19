#include "Square.h"
#include "ChessBoard.h" // Include the header file for ChessBoard

Square::Square(ChessBoard* parentBoard, QWidget* parent)
    : QPushButton(parent), position(Position()), pieceType(PieceType::Null), parentBoard(parentBoard) {}

Square::Square(Position pos, PieceType type, ChessBoard* parentBoard, QWidget* parent)
    : QPushButton(parent), position(pos), pieceType(type), parentBoard(parentBoard) {}


Position Square::getPosition() const {
    return position;
}

void Square::setPieceType(PieceType type) {
    pieceType = type;
}

PieceType Square::getPieceType() const {
    return pieceType;
}
 
