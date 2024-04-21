#ifndef PIECETYPE_H
#define PIECETYPE_H

#include <iostream>

enum class PieceType {
    Null = 0,    // Default value is Null
    WhitePawn = 1,
    WhiteKnight = 2,
    WhiteBishop = 3,
    WhiteRook = 5,
    WhiteQueen = 9,
    WhiteKing = 1000, // A very large positive number for White King
    BlackPawn = -1,
    BlackKnight = -2,
    BlackBishop = -3,
    BlackRook = -5,
    BlackQueen = -9,
    BlackKing = -1000, // A very large negative number for Black King
};

// Overload the << operator for PieceType enum class
inline std::ostream& operator<<(std::ostream& os, const PieceType& pieceType) {
    switch (pieceType) {
    case PieceType::Null:        return os << "Null";
    case PieceType::WhitePawn:   return os << "White Pawn";
    case PieceType::WhiteKnight: return os << "White Knight";
    case PieceType::WhiteBishop: return os << "White Bishop";
    case PieceType::WhiteRook:   return os << "White Rook";
    case PieceType::WhiteQueen:  return os << "White Queen";
    case PieceType::WhiteKing:   return os << "White King";
    case PieceType::BlackPawn:   return os << "Black Pawn";
    case PieceType::BlackKnight: return os << "Black Knight";
    case PieceType::BlackBishop: return os << "Black Bishop";
    case PieceType::BlackRook:   return os << "Black Rook";
    case PieceType::BlackQueen:  return os << "Black Queen";
    case PieceType::BlackKing:   return os << "Black King";
    default:                      return os << "Unknown PieceType";
    }
}

#endif /* PIECETYPE_H */
