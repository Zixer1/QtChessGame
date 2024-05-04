#ifndef SQUARE_H
#define SQUARE_H
#include <array>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsProxyWidget>
#include "Position.h"
#include "Piece.h"
 

// Forward declaration
class ChessBoard;

class Square : public QPushButton {
    Q_OBJECT

private:
    data_model::Position position;
    // TODO Change this to PieceType to have a more segregated code
    Piece piece;
    QPushButton* button;
    // TODO implement isPlaced into Scene.cpp displayChessPiece 
    bool isPlaced = false;
    bool isClicked = false;
    ChessBoard* partOfBoard = nullptr;
public:

    Square(data_model::Position pos, Piece type, QGraphicsScene* scene = nullptr, QWidget* parent = nullptr);
    
    ~Square();

    Piece* getPiece() {
		return &piece;
	}

    PieceType getPieceType() const {
        return piece.getPieceType();
    }

    QPushButton* getButton() {
        return button;
        }

    bool isPiecePlaced() const {
		return isPlaced;
	}
    
    data_model::Position getPosition() const {
		return position;
	}

    bool getIsClicked() const {
		return isClicked;
	}

    void switchStatesIsClicked() {
        if (isClicked) {
			isClicked = false;
		} else {
			isClicked = true;
        
        }
    }
    void setPiece(Piece* newPiece) {
		piece = *newPiece;
	}
    void removePiece() {
        piece = Piece();
        }
    void isPiecePlacedTrue() {
        isPlaced = true;
    }

    void isPiecePlacedFalse() {
        isPlaced = false;
	}

    void setChessBoardOwner(ChessBoard* board) {
		partOfBoard = board;
	}

    Square& operator=(const Square& other) {
        if (this != &other) {
            // Perform member-wise assignment
            // For example:
            position = other.position;
            piece = other.piece;
            // Assign other members as needed
        }
        return *this;
    }

signals:
    // Add signals here if needed

private slots:
    void buttonClicked();
};

#endif /* SQUARE_H */
