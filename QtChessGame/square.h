#ifndef SQUARE_H
#define SQUARE_H

#include "Position.h"
#include "PieceType.h"

class Square {
private:
    Position position;  // Position of the square
    PieceType pieceType; // Type of piece inside the square

public:
    // Constructor with default values
    Square() : position(Position('x', 0)), pieceType(PieceType::Null) {}

    // Constructor with specified position and piece type
    Square(Position pos, PieceType type) : position(pos), pieceType(type) {}


    // Method to get the position of the square
    Position getPosition() const {
        return position;
    }

    // Method to set the piece type of the square
    void setPieceType(PieceType type) {
        pieceType = type;
    }

    // Method to get the piece type of the square
    PieceType getPieceType() const {
        return pieceType;
    }

};

#endif /* SQUARE_H */
