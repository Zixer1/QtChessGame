#ifndef SQUARE_H
#define SQUARE_H
#include <array>
#include <QPushButton>

#include "Position.h"
#include "Piece.h"


class Square : public QPushButton {
    Q_OBJECT

private:
    data_model::Position position;
    // TODO Change this to PieceType to have a more segregated code
    Piece piece;

    // TODO implement isPlaced into Scene.cpp displayChessPiece 
    bool isPlaced = false;
public:
    Square(QWidget* parent = nullptr);

    Square(data_model::Position pos, Piece type, QWidget* parent = nullptr);
    
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

    void isPiecePlacedTrue() {
        isPlaced = true;
    }

    void isPiecePlacedFalse() {
        isPlaced = false;
	}

signals:
    // Add signals here if needed

public slots:
    // Add slots here if needed
};
#endif /* SQUARE_H */
