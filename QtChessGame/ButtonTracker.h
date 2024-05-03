#pragma once
#ifndef BUTTONTRACKER_H
#define BUTTONTRACKER_H

#include <map>
#include <stdexcept>

class ButtonTracker {
private:
    std::map<int, void*> clickedSquares;

public:
    
    // Add a method to add a clicked square to the map

    ButtonTracker() {
		clickedSquares = std::map<int, void*>();
	}

    void addClickedSquare(void* square) {
        if (static_cast<int>(clickedSquares.size()) + 1 > 2) {
            throw::std::runtime_error("Only two squares can be clicked at a time");
        }
        clickedSquares[static_cast<int>(clickedSquares.size()) + 1] = square;
    }

    void resetClickedSquares() {
        clickedSquares.clear();
    }

    int getClickedSquaresSize() {
        return static_cast<int>(clickedSquares.size());
    }

    void* getFirstClickedSquare() {
        return clickedSquares[0];
    }
};
extern ButtonTracker* buttonTracker;

#endif /* BUTTONTRACKER_H */

