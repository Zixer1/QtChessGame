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

void data_model::Position::movePosition(int outX, int outY) {
	x = outX;
	y = outY;
}

std::array<int, 3> data_model::Position::getPixelPositionFromChessPosition(int sizeOfChessBoard) {

	// Convert chess position to pixel position
	std::array<int, 3> pixelPosition = { 0, 0, 0 };
	if (x == 0 || y == 0) {
		qDebug() << "Error: Invalid chess position trying to get placed.";
		throw std::out_of_range("Invalid chess position");
	}

	pixelPosition[0] = (x * (sizeOfChessBoard / 8)) - sizeOfChessBoard / 8;
	pixelPosition[1] = (y * (sizeOfChessBoard / 8)) - sizeOfChessBoard / 8;
	pixelPosition[2] = sizeOfChessBoard / 8;
	return pixelPosition;
}