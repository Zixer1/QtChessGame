// Piece.cpp: The base class for all chess pieces, containing common attributes like position and color.
#include "Piece.h"

Piece::Piece() : pieceType(PieceType::Null) {
    using namespace data_model;
    // Constructor code here
    pieceType = PieceType::Null;
    position = Position();
}

Piece::Piece(PieceType type) : pieceType(type) {
    using namespace data_model;
	// Constructor code here
    pieceType = type;
	position = Position();
}

// General methods applicable to all pieces, such as move validation and capture.
