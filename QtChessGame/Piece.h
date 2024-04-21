#pragma once
// Piece.h: Base class for all chess pieces.
#ifndef PIECE_H
#define PIECE_H


#include "PieceType.h"
#include "Position.h"

class Piece {
protected:
    PieceType pieceType;
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



};

#endif // PIECE_H