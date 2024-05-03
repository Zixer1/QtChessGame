#include "Square.h"
#include "ChessBoard.h" // Include the header file for ChessBoard
#include "Position.h" // Include the header file for Position



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

        partOfBoard->addClickedSquare(this);
        qDebug() << "Button clicked!" << piece.toString() << " at " << position.getX() << " " << position.getY();
        button->setStyleSheet("background-color: transparent; border: 5px solid red;");
        isClicked = true;
    }
    else {
        qDebug() << "partOfBoard pointer is null";
    }

    
}
