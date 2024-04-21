#ifndef SQUARE_H
#define SQUARE_H

#include <QPushButton>
#include "Position.h"
#include "Piece.h"
#include "ChessBoard.h"
#include <array>

class Square : public QPushButton {
    Q_OBJECT

private:
    Position position;
    Piece piece;
    ChessBoard* parentBoard; // Pointer to the parent ChessBoard
    static int squareCount; // Static member to keep track of Square objects
    static std::array<Position, 64> existingPositions; // Static member to hold existing positions
    static int existingPositionsCount; // Static member to keep track of the number of existing positions

public:
    Square(ChessBoard* parentBoard = nullptr, QWidget* parent = nullptr);

    Square(Position pos, Piece type, ChessBoard* parentBoard = nullptr, QWidget* parent = nullptr);
    
    ~Square();

    PieceType getPieceType() const {
        return piece.getPieceType();
    }

    static std::array<Position, 64> getExistingPositions() {
        return existingPositions;
    }

    

    static int getExistingPositionsCount() {
        return existingPositionsCount;
    }

signals:
    // Add signals here if needed

public slots:
    // Add slots here if needed
};
#endif /* SQUARE_H */
