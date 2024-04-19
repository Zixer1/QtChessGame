#pragma once
// ChessBoard.h: Header for managing the state of the chessboard.
#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "Piece.h"
#include <QGraphicsView>

class ChessBoard : public QGraphicsView {
public:
    ChessBoard(int size, QWidget* parent = nullptr);
};

#endif /* CHESSBOARD_H */


