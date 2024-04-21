// Position.cpp

#include <array>
#include <iostream>
#include <QDebug>

#include "Position.h"

data_model::Position::Position() : x(0), y(0) {}

data_model::Position::Position(int x, int y) {
    if (x < 0 || x > 8 || y < 0 || y > 8) {
        qDebug() << "Error: Tried to create a Position that is out of bound, you are trying to create a position ("<< x << "," << y << "), when it must be between 0 and 8 inclusive";
        throw std::out_of_range("Position must be between 0 and 8 inclusive");
        // In case the error is manually skipped, set the position to an invalid value
        Position::x = 0;
        Position::y = 0;
    }
    else {
        Position::x = x;
        Position::y = y;
	}
}

data_model::Position::~Position() {

}
// Overloaded equality operator.
bool data_model::Position::operator==(const Position& other) const {
    return x == other.x && y == other.y;
}

// Overloaded inequality operator.
bool data_model::Position::operator!=(const Position& other) const {
    return x != other.x && y != other.y;
}

// Additional functionality implementation as needed.

int data_model::Position::getX() const {
    return x;
}

int data_model::Position::getY() const {
    return y;
}

std::array<int, 2> data_model::Position::getPosition() const {
	return {x, y};
}

// Usefull for movement management
bool data_model::Position::isLastRow() const {
	return y == 8 || y == 1;
}

bool data_model::Position::isSecondToLastRow() const {
	return y == 7 || y == 2;
}

bool data_model::Position::isBeyondLimits(int add_X, int add_Y) {
	return x + add_X < 1 || x + add_X > 8 || y + add_Y < 1 || y + add_Y > 8;
}

void data_model::Position::movePosition(int x, int y) {
	Position::x = x;
	Position::y = y;
}