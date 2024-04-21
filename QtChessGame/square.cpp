#include "Square.h"
#include "ChessBoard.h" // Include the header file for ChessBoard
#include "Position.h" // Include the header file for Position



Square::Square(QWidget* parent) {


}

Square::Square(data_model::Position pos, Piece type, QWidget* parent) {
    position = pos;
    piece = type;

}

Square::~Square() {
    
}