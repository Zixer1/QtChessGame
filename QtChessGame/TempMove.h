#pragma once
#ifndef TEMPORARYPOSITION_H
#define TEMPORARYPOSITION_H

#include <QDebug>

#include "Position.h"

namespace data_model {

    class TempMove {
    public:
        TempMove(Position& pos, int newX, int newY);
        ~TempMove();

        TempMove(const TempMove&) = delete;
        TempMove& operator=(const TempMove&) = delete;

    private:
        Position& originalPosition;
        int oldX, oldY;
    };

}

#endif // TEMPORARYPOSITION_H
