#include "TempMove.h"

data_model::TempMove::TempMove(Position& pos, int newX, int newY)
    : setPosition(pos), oldPosition(pos) {
    if (pos.isBeyondLimits(newX - oldPosition.getX(), newY - oldPosition.getY())) {
        qDebug() << "Error: New position is out of bounds.";
        throw std::out_of_range("New position must be within board limits");
    }
    setPosition.movePosition(newX, newY);
}

data_model::TempMove::~TempMove() {
    setPosition.movePosition(oldPosition.getX(), oldPosition.getY());
    qDebug() << "Position reset to (" << oldPosition.getX() << ", " << oldPosition.getY() << ")";
}
