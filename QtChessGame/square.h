#ifndef SQUARE_H
#define SQUARE_H

#include <QPushButton>
#include "Position.h"
#include "Piece.h"
#include <array>

class Square : public QPushButton {
    Q_OBJECT

private:
    data_model::Position position;
    Piece piece;

public:
    Square(QWidget* parent = nullptr);

    Square(data_model::Position pos, Piece type, QWidget* parent = nullptr);
    
    ~Square();

    PieceType getPieceType() const {
        return piece.getPieceType();
    }


signals:
    // Add signals here if needed

public slots:
    // Add slots here if needed
};
#endif /* SQUARE_H */
