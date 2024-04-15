#pragma once
// Position.h: Header file for the Position class, which represents a position on a chessboard using file and rank.
#ifndef POSITION_H
#define POSITION_H

class Position {
public:
    char x; // Represents the file on the chessboard, 'a' to 'h'.
    int y;  // Represents the rank on the chessboard, 1 to 8.

    // constructors :
    Position(); 
    Position(char x, int y); 

    // Overload operators
    bool operator==(const Position& other) const;
    bool operator!=(const Position& other) const;
    bool operator<(const Position& other) const;


};

#endif // POSITION_H
