// Position.h
#ifndef POSITION_H
#define POSITION_H

#include <stdexcept>
#include <array>
#include <QMainWindow>



namespace data_model {
	class Position;

class Position {

private:
	int x;
	int y;
public:


    // constructors :
    Position();
    Position(int x, int  y);
    ~Position();

    // Overload operators
    bool operator==(const Position& other) const;
    bool operator!=(const Position& other) const;

    //Methods
    int getX() const;
    int getY() const;
    std::array<int, 2> getPosition() const;

    // For Pawn promotion
    bool isLastRow() const;

    // For Pawns 2 steps move
    bool isSecondToLastRow() const;

    // For checking if the a new position is beyond the limits of the board
    bool isBeyondLimits(int add_X, int add_y);

    void movePosition(int x, int y);
};
}
#endif // POSITION_H
