#include "TempMove.h"


data_model::TempMove::TempMove(Position& pos, int newX, int newY)
    : originalPosition(pos), oldX(pos.getX()), oldY(pos.getY()) {
    if (pos.isBeyondLimits(newX - oldX, newY - oldY)) {
        qDebug() << "Error: New position is out of bounds.";
        throw std::out_of_range("New position must be within board limits");
    }
    originalPosition.movePosition(newX, newY);
}

data_model::TempMove::~TempMove() {
    originalPosition.movePosition(oldX, oldY);
    qDebug() << "Position reset to (" << oldX << ", " << oldY << ")";
}
