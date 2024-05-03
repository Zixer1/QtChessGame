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
    
    int playerTurn = 0; // 0 for white, 1 for black
    std::array<Square*, 2> clickedSquares;
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

    void addClickedSquare(Square* square) {
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

    void switchPlayerTurn() {
		playerTurn = (playerTurn == 0) ? 1 : 0;
	}

    int getPlayerTurn() {
		return playerTurn;
	}

    int getClickedSquaresSize() {
        return clickedSquaresSize;
    }

    void* getFirstClickedSquare() {
        return clickedSquares[0];
    }

    Square* getSecondClickedSquare() {
		return clickedSquares[1];
	}

    bool isOccupied(data_model::Position pos) {
		return existingSquares[pos.getX()-1][pos.getX()-1] != nullptr;
	}
    bool isOccupiedByOpponent(Square* square, Square* otherSquare) {
        if (isOccupied(otherSquare->getPosition())) {
            if (square->getPiece()->getTypeValue() > 0) { // White piece

                if (otherSquare->getPiece()->getTypeValue() < 0) { // Black piece
                    return true;
                }

            }
            else if (square->getPiece()->getTypeValue() < 0) { // Black piece

                if (otherSquare->getPiece()->getTypeValue() > 0) { // White piece
                    return true;
                }
            }
            
        }
        return false;
	}

    Square* getSquare(int x, int y) {
        return existingSquares[x-1][y-1];
    }


    bool isChecked() {}

    std::array<data_model::Position*, 64> blackAllowedMoves(Square* square) {

    }
    std::array<data_model::Position*, 64> whiteAllowedMoves(Square* square) {

    }
    std::array<data_model::Position*, 64> kingAllowedMoves(Square* square){

    }

    std::array<data_model::Position*, 64> rookAllowedMoves(Square* square) {
        if (!square) {
            throw std::invalid_argument("Square cannot be null.");
        }

        data_model::Position currentPosition = square->getPosition();
        std::array<data_model::Position*, 64> validMoves{}; // Array to store up to 64 possible moves.
        size_t index = 0;

        // Directions the Rook can move: right (+x), left (-x), up (+y), down (-y)
        std::array<int, 2> directions[] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

        for (auto& direction : directions) {
            int step = 1; // Start with one step in the given direction.
            while (true) {
                int newX = currentPosition.getX() + direction[0] * step;
                int newY = currentPosition.getY() + direction[1] * step;

                // Check if the new position is within the board limits
                if (newX < 0 || newX >= 8 || newY < 0 || newY >= 8) {
                    break; // Break if the new position is out of the chessboard bounds.
                }

                data_model::Position* newPos = new data_model::Position(newX, newY); // Create new position dynamically.

                // Assuming a method exists to check if a position is occupied
                if (isOccupiedByOpponent(square, getSquare(newX, newY))) {
                    
                    validMoves[index++] = newPos; 
                    
                    break; 
                }

                validMoves[index++] = newPos; // Add valid position.
                step++; // Move to the next step in the same direction.
            }
        }

        return validMoves;
    }

    std::array<data_model::Position*, 64> knightAllowedMoves(Square* square) {

    }
    std::array<data_model::Position*, 64> bishopAllowedMoves(Square* square) {
        //TODO: Implement bishopAllowedMoves
    }
    std::array<data_model::Position*, 64> queenAllowedMoves(Square* square) {
        //TODO: Implement queenAllowedMoves
    }
    std::array<data_model::Position*, 64> pawnAllowedMoves(Square* square) {
        //TODO: Implement pawnAllowedMoves
    }
    
    std::array<std::array<Square*, 8>, 8> getAllowedMoves(Square* square) {
        if (!square) {
            throw std::invalid_argument("Square cannot be null.");
        }

        PieceType type = square->getPieceType();

        // Predefined empty array with all elements set to nullptr
        std::array<std::array<Square*, 8>, 8> emptyArray{};
        for (auto& row : emptyArray) {
            row.fill(nullptr);
        }
        
        switch (type) {
            /*
        case PieceType::WhiteKing:
        case PieceType::BlackKing:
            return kingAllowedMoves(square);

        case PieceType::WhiteQueen:
        case PieceType::BlackQueen:
            return queenAllowedMoves(square);

        case PieceType::WhiteRook:
        case PieceType::BlackRook:
            return rookAllowedMoves(square);

        case PieceType::WhiteBishop:
        case PieceType::BlackBishop:
            return bishopAllowedMoves(square);

        case PieceType::WhiteKnight:
        case PieceType::BlackKnight:
            return knightAllowedMoves(square);

        case PieceType::WhitePawn:
        case PieceType::BlackPawn:
            return pawnAllowedMoves(square);
            */
        default:
            // Return the predefined empty array when the piece is null or type is unknown
            return emptyArray;
        }
    }



};

#endif /* CHESSBOARD_H */


