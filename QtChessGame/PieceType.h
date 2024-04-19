#pragma once
// PieceType.h
#ifndef PIECETYPE_H
#define PIECETYPE_H

#include <iostream>

enum class PieceType {
    Null = 0,   // Default value is Null
    Pawn,
    Knight,
    Bishop,
    Rook,
    Queen,
    King
};

// Overload the << operator for PieceType enum class
inline std::ostream& operator<<(std::ostream& os, const PieceType& pieceType) {
    switch (pieceType) {
    case PieceType::Null:   return os << "Null";
    case PieceType::Pawn:   return os << "Pawn";
    case PieceType::Knight: return os << "Knight";
    case PieceType::Bishop: return os << "Bishop";
    case PieceType::Rook:   return os << "Rook";
    case PieceType::Queen:  return os << "Queen";
    case PieceType::King:   return os << "King";
    default:                return os << "Unknown PieceType";
    }
}

#endif /* PIECETYPE_H */

