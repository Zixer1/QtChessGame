#pragma once
// ChessBoard.h: Header for managing the state of the chessboard.
#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "Piece.h"
#include <QGraphicsView>
#include <array>
#include "Position.h"
#include "Square.h"
class ChessBoard : public QGraphicsView {
private:
    static int squareCount; // Static member to keep track of Square objects
    static std::array<Square, 64> existingSquarePositions; // Static member to hold existing positions
    QGraphicsScene scene;

public:
    ChessBoard(QWidget* parent = nullptr);

    ~ChessBoard();

    // Methods

    

};

#endif /* CHESSBOARD_H */


