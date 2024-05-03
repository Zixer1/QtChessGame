#ifndef SQUARE_H
#define SQUARE_H
#include <array>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsProxyWidget>
#include "Position.h"
#include "Piece.h"
#include "ChessBoard.h"
 

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

    PieceType getPieceType() const {
        return piece.getPieceType();
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
    void buttonClicked() {
         qDebug() << "Button clicked!" << piece.toString() << " at " << position.getX() << " " << position.getY();
         button->setStyleSheet("background-color: rgba(255, 0, 0, 128); border: 1px solid red;");
         isClicked = true;
        

    }
};

#endif /* SQUARE_H */
