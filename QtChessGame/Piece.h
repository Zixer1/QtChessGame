#pragma once
// Piece.h: Base class for all chess pieces.
#ifndef PIECE_H
#define PIECE_H

#include <string>

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


    std::string toString() {
        switch (pieceType) {
        case PieceType::Null: return "Null";
        case PieceType::WhitePawn: return "White Pawn";
        case PieceType::WhiteKnight: return "White Knight";
        case PieceType::WhiteBishop: return "White Bishop";
        case PieceType::WhiteRook: return "White Rook";
        case PieceType::WhiteQueen: return "White Queen";
        case PieceType::WhiteKing: return "White King";
        case PieceType::BlackPawn: return "Black Pawn";
        case PieceType::BlackKnight: return "Black Knight";
        case PieceType::BlackBishop: return "Black Bishop";
        case PieceType::BlackRook: return "Black Rook";
        case PieceType::BlackQueen: return "Black Queen";
        case PieceType::BlackKing: return "Black King";
        default: return "Unknown";
        }
    }

    int getTypeValue() const {
        return static_cast<int>(pieceType);
    }

    // Getters and setters
    PieceType getPieceType() const {
		return pieceType;
	}
    PieceType setPieceType(PieceType type) {
        pieceType = type;
    }



};

#endif // PIECE_H