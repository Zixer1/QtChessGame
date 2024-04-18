// Position.cpp: Implementation file for the Position class.
#include "Position.h"

// Default constructor that initializes the position to an invalid state.
Position::Position() : x('x'), y(0) {}

// Parameterized constructor for setting the position.
Position::Position(char x, int y) : x(x), y(y) {}

// Overloaded equality operator.
bool Position::operator==(const Position& other) const {
    return x == other.x && y == other.y;
}

// Overloaded inequality operator.
bool Position::operator!=(const Position& other) const {
    return !(*this == other);
}

// Overloaded less than operator for sorting purposes, if needed.
bool Position::operator<(const Position& other) const {
    return (x < other.x) || (x == other.x && y < other.y);
}

// Additional functionality implementation as needed.

char Position::getX() const {
    return x;
}

int Position::getY() const {
    return y;
}