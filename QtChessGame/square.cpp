#include "Square.h"
#include "ChessBoard.h" // Include the header file for ChessBoard
#include "Position.h" // Include the header file for Position
#include <thread>
#include <chrono>


Square::Square(data_model::Position pos, Piece type, QGraphicsScene* scene, QWidget* parent)
    : QPushButton(parent), position(pos), piece(type), button(nullptr)
{
    std::array<int, 3> pixelPos = pos.getPixelPositionFromChessPosition();
    qDebug() << "Adding button at position x: " << pixelPos[0] << ", and y: " << pixelPos[1] << ", with size: " << pixelPos[2];
    button = new QPushButton();
    button->setStyleSheet("background-color: transparent; border: none;");
    button->setMinimumSize(pixelPos[2], pixelPos[2]); // Set minimum size of the button (width, height)
    QGraphicsProxyWidget* proxy = scene->addWidget(button);
    proxy->setPos(pixelPos[0], pixelPos[1]);

    QObject::connect(button, &QPushButton::clicked, [&]() {
        buttonClicked();
        });
}



Square::~Square() {

}

void Square::buttonClicked() {
    if (partOfBoard != nullptr) {

        if (partOfBoard->getClickedSquaresSize() == 0) {
            qDebug() << "Click no.1";

            if (this->getPiece()->getTypeValue() == 2 || this->getPiece()->getTypeValue() == -2) { // Clicked on the rook
            partOfBoard->setClickedAllowedMoves(partOfBoard->knightAllowedMoves(this));
            partOfBoard->getMainScene()->displayAllowedMoves(partOfBoard->getClickedAllowedMoves());
            }
            if (this->getPiece()->getTypeValue() == 5 || this->getPiece()->getTypeValue() == -5) { // Clicked on the rook
                partOfBoard->setClickedAllowedMoves(partOfBoard->rookAllowedMoves(this));
                partOfBoard->getMainScene()->displayAllowedMoves(partOfBoard->getClickedAllowedMoves());
            }
            if (this->getPiece()->getTypeValue() == 1000 || this->getPiece()->getTypeValue() == -1000) { // Clicked on the rook
                partOfBoard->setClickedAllowedMoves(partOfBoard->kingAllowedMoves(this));
                partOfBoard->getMainScene()->displayAllowedMoves(partOfBoard->getClickedAllowedMoves());
            }
            partOfBoard->addClickedSquare(this);
            button->setStyleSheet("background-color: transparent; border: 5px solid red;");
            }

        else if (partOfBoard->getClickedSquaresSize() == 1) {
            qDebug() << "Click no.2";
            if (partOfBoard->getFirstClickedSquare()->getPieceType() == PieceType::Null) {
                
                if (this->getPiece()->getTypeValue() == 2 || this->getPiece()->getTypeValue() == -2) { // Clicked on the rook
                    partOfBoard->setClickedAllowedMoves(partOfBoard->knightAllowedMoves(this));
                    partOfBoard->getMainScene()->displayAllowedMoves(partOfBoard->getClickedAllowedMoves());
                }
                if (this->getPiece()->getTypeValue() == 5 || this->getPiece()->getTypeValue() == -5) { // Clicked on the rook
                    partOfBoard->setClickedAllowedMoves(partOfBoard->rookAllowedMoves(this));
                    partOfBoard->getMainScene()->displayAllowedMoves(partOfBoard->getClickedAllowedMoves());
                }
                if (this->getPiece()->getTypeValue() == 1000 || this->getPiece()->getTypeValue() == -1000) { // Clicked on the rook
                    partOfBoard->setClickedAllowedMoves(partOfBoard->kingAllowedMoves(this));
                    partOfBoard->getMainScene()->displayAllowedMoves(partOfBoard->getClickedAllowedMoves());
                }
                else {
                    partOfBoard->getMainScene()->hideAllowedMoves();
                }
                partOfBoard->getFirstClickedSquare()->getButton()->setStyleSheet("background-color: transparent; border: transparent;");
                partOfBoard->resetClickedSquares();
                partOfBoard->addClickedSquare(this);
                button->setStyleSheet("background-color: transparent; border: 5px solid red;");
                
                
            }
            else if ((partOfBoard->isOccupiedByOpponent(partOfBoard->getFirstClickedSquare(), this)) || this->getPieceType() == PieceType::Null) { // Clicked on nothing
                for (const auto& pos : partOfBoard->getClickedAllowedMoves()) {
                    if ((pos != nullptr && *pos == this->getPosition()) ) {

                       

                        partOfBoard->getFirstClickedSquare()->switchStatesIsClicked();
                        partOfBoard->getFirstClickedSquare()->getButton()->setStyleSheet("background-color: transparent; border: transparent;");

                        partOfBoard->getMainScene()->hideChessPiece(this);
                        partOfBoard->getMainScene()->hideChessPiece(partOfBoard->getFirstClickedSquare());
                        setPiece(partOfBoard->getFirstClickedSquare()->getPiece());
                        partOfBoard->getFirstClickedSquare()->removePiece();
                        partOfBoard->getMainScene()->displayChessPiece(this);
                        button->setStyleSheet("background-color: transparent; border: transparent;");
                        partOfBoard->getMainScene()->hideAllowedMoves();
                        partOfBoard->resetClickedSquares();
                        isClicked = false;
                    }
                }
            
                
            }
            else {

                partOfBoard->getFirstClickedSquare()->switchStatesIsClicked();
                partOfBoard->getFirstClickedSquare()->getButton()->setStyleSheet("background-color: transparent; border: transparent;");
                button->setStyleSheet("background-color: transparent; border: transparent;");
                partOfBoard->getMainScene()->hideAllowedMoves();
                partOfBoard->resetClickedSquares();
                isClicked = false;
                
                
            }
		}
		else {
			qDebug() << "Clicked squares size is not 0 or 1";
		}
    
        
        qDebug() << "Button clicked!" << piece.toString() << " at " << position.getX() << " " << position.getY();
        
    }
    else {
        qDebug() << "partOfBoard pointer is null";
    }

    
}
