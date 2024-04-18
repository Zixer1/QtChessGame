#include "Square.h"

// Constructor with default values
Square::Square() : position(Position()), pieceType(PieceType::Null) {}

// Constructor with specified position and piece type
Square::Square(Position pos, PieceType type) : position(pos), pieceType(type) {}

// Method to get the position of the square
Position Square::getPosition() const {
    return position;
}

// Method to set the piece type of the square
void Square::setPieceType(PieceType type) {
    pieceType = type;
}

// Method to get the piece type of the square
PieceType Square::getPieceType() const {
    return pieceType;
}

