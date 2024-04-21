// Position.cpp
#include "Position.h"
#include <array>
#include <iostream>
#include <QDebug>

Position::Position() : x(0), y(0) {}

Position::Position(int x, int y) {
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

Position::~Position() {

}
// Overloaded equality operator.
bool Position::operator==(const Position& other) const {
    return x == other.x && y == other.y;
}

// Overloaded inequality operator.
bool Position::operator!=(const Position& other) const {
    return x != other.x && y != other.y;
}

// Additional functionality implementation as needed.

int Position::getX() const {
    return x;
}

int Position::getY() const {
    return y;
}

std::array<int, 2> Position::getPosition() const {
	return {x, y};
}

// Usefull for movement management
bool Position::isLastRow() const {
	return y == 8 || y == 1;
}

bool Position::isSecondToLastRow() const {
	return y == 7 || y == 2;
}

bool Position::isBeyondLimits(int add_X, int add_Y) {
	return x + add_X < 1 || x + add_X > 8 || y + add_Y < 1 || y + add_Y > 8;
}