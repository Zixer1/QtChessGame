#pragma once
// ChessBoard.h: Header for managing the state of the chessboard.
#ifndef CHESSBOARD_H
#define CHESSBOARD_H


#include <QGraphicsView>
#include <array>
#include <map>

#include "Position.h"
#include "Square.h"
#include "Piece.h"

// Forward declarations
class Square;


class ChessBoard : public QGraphicsView {
private:
    // Use the info from the squares, to create a grid of pieces and be able to check things like the Pos of the king and later check for allowed moves
    int squareCount; // Static member to keep track of Square objects
    std::array<std::array<Square*, 8>, 8> existingSquares; // Static member to hold existing existing squares and what they contain
    QGraphicsScene* scene; // Scene for rendering graphical items
    std::map<int, Square*> clickedSquares;

public:
    ChessBoard(QGraphicsScene* scene = nullptr, QWidget* parent = nullptr);

    ~ChessBoard();

    // Methods
    void incrementSquareCount() {
		squareCount += 1;
	}

    int getSquareCount() {
        return squareCount;
    }

    void addClickedSquare(Square* square) {
        if (static_cast<int>(clickedSquares.size()) + 1 > 2) {
            throw::std::runtime_error("Only two squares can be clicked at a time");
        }
        clickedSquares[static_cast<int>(clickedSquares.size()) + 1] = square;
    }

    void resetClickedSquares() {
        clickedSquares.clear();
    }

    int getClickedSquaresSize() {
        return static_cast<int>(clickedSquares.size());
    }

    Square* getFirstClickedSquare() {
        return clickedSquares[0];
    }

    Square& getSquare(int x, int y) {
        return *existingSquares[x][y];
    }

    

};

#endif /* CHESSBOARD_H */


