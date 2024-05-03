#pragma once
// ChessBoard.h: Header for managing the state of the chessboard.
#ifndef CHESSBOARD_H
#define CHESSBOARD_H


#include <QGraphicsView>
#include <array>
#include <map>

#include "Position.h"
#include "Piece.h"
#include "Scene.h"


// Forward declarations
class Square;


class ChessBoard : public QGraphicsView {
private:
    // Use the info from the squares, to create a grid of pieces and be able to check things like the Pos of the king and later check for allowed moves
    int squareCount; // Static member to keep track of Square objects
    std::array<std::array<Square*, 8>, 8> existingSquares; // Static member to hold existing existing squares and what they contain
    gui::Scene* mainScene; // Scene for rendering graphical items
    QGraphicsScene* scene; // Scene for rendering graphical items
    
    std::array<void*, 2> clickedSquares;
    int clickedSquaresSize = 0;

public:
    ChessBoard(gui::Scene* mainScene = nullptr, QWidget* parent = nullptr);

    ~ChessBoard();

    // Methods
    void incrementSquareCount() {
		squareCount += 1;
	}

    int getSquareCount() {
        return squareCount;
    }


    void resetClickedSquares() {
        clickedSquares[0] = nullptr;
        clickedSquares[1] = nullptr;
        clickedSquaresSize = 0;
    }

    void addClickedSquare(void* square) {
        if (clickedSquares[0] == nullptr) {
			clickedSquares[0] = square;
            clickedSquaresSize += 1;
		}
		else if (clickedSquares[0] != nullptr && clickedSquares[1] == nullptr) {
			clickedSquares[1] = square;
            clickedSquaresSize += 1;
		}
        else {
            throw::std::runtime_error("Error: clickedSquares array is full or invalid.");
        }
    }

    int getClickedSquaresSize() {
        return clickedSquaresSize;
    }

    void* getFirstClickedSquare() {
        return clickedSquares[0];
    }

    void* getSecondClickedSquare() {
		return clickedSquares[1];
	}

    Square& getSquare(int x, int y) {
        return *existingSquares[x][y];
    }

    

};

#endif /* CHESSBOARD_H */


