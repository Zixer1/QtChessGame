#ifndef SQUARE_H
#define SQUARE_H

#include <QPushButton>
#include "Position.h"
#include "PieceType.h"

class ChessBoard; // Forward declaration

class Square : public QPushButton {
    Q_OBJECT

private:
    Position position;
    PieceType pieceType;
    ChessBoard* parentBoard; // Pointer to the parent ChessBoard

public:
    Square(ChessBoard* parentBoard = nullptr, QWidget* parent = nullptr);

    Square(Position pos, PieceType type, ChessBoard* parentBoard = nullptr, QWidget* parent = nullptr);


    Position getPosition() const;

    void setPieceType(PieceType type);

    PieceType getPieceType() const;


signals:
    // Add signals here if needed

public slots:
    // Add slots here if needed
};

#endif /* SQUARE_H */
