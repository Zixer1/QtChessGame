// ChessBoard.cpp: Manages the chessboard's state, including piece locations and move validation, check kingpos, etc.
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QDebug>

#include "ChessBoard.h"
#include "Square.h"


ChessBoard::ChessBoard(gui::Scene* mainSceneOut, QWidget* parent) : QGraphicsView(parent) {
    squareCount = 0;
    mainScene = mainSceneOut;
    scene = mainSceneOut->scene;
    clickedSquares = {nullptr, nullptr};
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            if ((x == 0 && y == 0) || (x == 7 && y == 0)) {
                Square* createSquare = new Square(data_model::Position(x+1, y+1), Piece(PieceType::BlackRook), scene);
                createSquare->setChessBoardOwner(this);
                mainScene->gui::Scene::displayChessPiece(createSquare);
                // Keep track of the square
                existingSquares[x][y] = createSquare; // Assign the pointer to existingSquares
                squareCount += 1;
            }
            if ((x == 0 && y == 7) || (x == 7 && y == 7)) {
                Square* createSquare = new Square(data_model::Position(x + 1, y + 1), Piece(PieceType::WhiteRook), scene);
                createSquare->setChessBoardOwner(this);
                mainScene->gui::Scene::displayChessPiece(createSquare);
                // Keep track of the square
                existingSquares[x][y] = createSquare; // Assign the pointer to existingSquares
                squareCount += 1;
            }
            if ((x == 1 && y == 0) || (x == 6 && y == 0)) {
				Square* createSquare = new Square(data_model::Position(x + 1, y + 1), Piece(PieceType::BlackKnight), scene);
				createSquare->setChessBoardOwner(this);
				mainScene->gui::Scene::displayChessPiece(createSquare);
				// Keep track of the square
				existingSquares[x][y] = createSquare; // Assign the pointer to existingSquares
				squareCount += 1;
			}
            if ((x == 1 && y == 7) || (x == 6 && y == 7)) {
                Square* createSquare = new Square(data_model::Position(x + 1, y + 1), Piece(PieceType::WhiteKnight), scene);
                createSquare->setChessBoardOwner(this);
                mainScene->gui::Scene::displayChessPiece(createSquare);
                // Keep track of the square
                existingSquares[x][y] = createSquare; // Assign the pointer to existingSquares
                squareCount += 1;
            }
            if ((x == 4 && y == 0)) {
                Square* createSquare = new Square(data_model::Position(x + 1, y + 1), Piece(PieceType::BlackKing), scene);
                createSquare->setChessBoardOwner(this);
                mainScene->gui::Scene::displayChessPiece(createSquare);
                // Keep track of the square
                existingSquares[x][y] = createSquare; // Assign the pointer to existingSquares
                squareCount += 1;
            }
            if ((x == 4 && y == 7)) {
                Square* createSquare = new Square(data_model::Position(x + 1, y + 1), Piece(PieceType::WhiteKing), scene);
                createSquare->setChessBoardOwner(this);
                mainScene->gui::Scene::displayChessPiece(createSquare);
                // Keep track of the square
                existingSquares[x][y] = createSquare; // Assign the pointer to existingSquares
                squareCount += 1;
            }
            /*
            if ((x == 2 && y == 0) || (x == 5 && y == 0)) {
				Square* createSquare = new Square(data_model::Position(x + 1, y + 1), Piece(PieceType::BlackBishop), scene);
				createSquare->setChessBoardOwner(this);
				mainScene->gui::Scene::displayChessPiece(createSquare);
				// Keep track of the square
				existingSquares[x][y] = createSquare; // Assign the pointer to existingSquares
				squareCount += 1;
			}
            if ((x == 2 && y == 7) || (x == 5 && y == 7)) {
				Square* createSquare = new Square(data_model::Position(x + 1, y + 1), Piece(PieceType::WhiteBishop), scene);
				createSquare->setChessBoardOwner(this);
				mainScene->gui::Scene::displayChessPiece(createSquare);
				// Keep track of the square
				existingSquares[x][y] = createSquare; // Assign the pointer to existingSquares
				squareCount += 1;
			}
            if ((x == 3 && y == 0)) {
				Square* createSquare = new Square(data_model::Position(x + 1, y + 1), Piece(PieceType::BlackQueen), scene);
				createSquare->setChessBoardOwner(this);
				mainScene->gui::Scene::displayChessPiece(createSquare);
				// Keep track of the square
				existingSquares[x][y] = createSquare; // Assign the pointer to existingSquares
				squareCount += 1;
			}
            if ((x == 3 && y == 7)) {
                Square* createSquare = new Square(data_model::Position(x + 1, y + 1), Piece(PieceType::WhiteQueen), scene);
                createSquare->setChessBoardOwner(this);
                mainScene->gui::Scene::displayChessPiece(createSquare);
                // Keep track of the square
                existingSquares[x][y] = createSquare; // Assign the pointer to existingSquares
                squareCount += 1;
            }
            if (y==1) {
				Square* createSquare = new Square(data_model::Position(x + 1, y + 1), Piece(PieceType::BlackPawn), scene);
				createSquare->setChessBoardOwner(this);
				mainScene->gui::Scene::displayChessPiece(createSquare);
				// Keep track of the square
				existingSquares[x][y] = createSquare; // Assign the pointer to existingSquares
				squareCount += 1;
			}
            if (y == 6) {
                Square* createSquare = new Square(data_model::Position(x + 1, y + 1), Piece(PieceType::WhitePawn), scene);
                createSquare->setChessBoardOwner(this);
                mainScene->gui::Scene::displayChessPiece(createSquare);
                // Keep track of the square
                existingSquares[x][y] = createSquare; // Assign the pointer to existingSquares
                squareCount += 1;
            }
            */
            
        }   
    }
}
ChessBoard::~ChessBoard() {
	
}


// Methods for initializing the board, updating the board state, and checking for valid moves.
