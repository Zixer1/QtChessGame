#pragma once
// Piece.h: Base class for all chess pieces.
#ifndef PIECE_H
#define PIECE_H


#include "PieceType.h"
#include "Position.h"

class Piece {
protected:
    PieceType pieceType;
    Position position;
    bool checksWhiteKing;
    bool checksBlackKing;
public:
    Piece();
    Piece(PieceType type);
    // General methods for all pieces

    // Getters and setters
    PieceType getPieceType() const {
		return pieceType;
	}
    PieceType setPieceType(PieceType type) {
        pieceType = type;
    }

    Position getPosition() const {
		return position;
	}

};

#endif // PIECE_H