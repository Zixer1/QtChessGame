#include <QDebug>
#include "Position.h"


void testPosition() {
    // Create a Position object with no parameters
    Position pos1 = Position();
    qDebug() << "Position with no parameters: (" << pos1.getX() << ", " << pos1.getY() << ")";

    // Create a Position object with two parameters (0, 0)
    Position pos2 = Position(0, 0);
    qDebug() << "Position with parameters (0, 0): (" << pos2.getX() << ", " << pos2.getY() << ")";
    qDebug() << "Is position (0, 0) in the last row? " << pos2.isLastRow();
    qDebug() << "Is pos1 and pos2 equal? " << (pos1 == pos2);


    // Create a Position object with two parameters (1, 1)
    Position pos3 = Position(1, 1);
    qDebug() << "Position with parameters (1, 1): (" << pos3.getX() << ", " << pos3.getY() << ")";
    qDebug() << "Is position (1, 1) in the last row? " << pos3.isLastRow();
    qDebug() << "Is position (2, 2) the scond to last row? " << pos3.isSecondToLastRow();

    // Create a Position object with two parameters (2, 2)
    Position pos7 = Position(2, 2);
    qDebug() << "Position with parameters (2, 2): (" << pos7.getX() << ", " << pos7.getY() << ")";
    qDebug() << "Is position (2, 2) in the last row? " << pos7.isLastRow();
    qDebug() << "Is position (2, 2) the scond to last row? " << pos7.isSecondToLastRow();
    qDebug() << "Is position (2, 2) + (2,2) beyond limits? " << pos7.isBeyondLimits(2, 2);
    qDebug() << "Is pos3 and pos7 the same? " << (pos3 == pos7);
    qDebug() << "Is pos3 and pos7 different? " << (pos3 != pos7);
    
    // Create a Position object with two parameters (1, 8) 
    Position pos6 = Position(1, 8);
    qDebug() << "Is position (1, 8) in the last row? " << pos6.isLastRow();
    qDebug() << "Is position (1, 8) + (8,1) beyond limits? " << pos6.isBeyondLimits(8, 1);

    // SHOULD GIVE YOU A RUNTIME ERROR, forcing their creation will make a (0,0) pos:
    // 
    // Try creating a Position object with two parameters (10, -1)
    Position pos4 = Position(10, -1);
    qDebug() << "Position with parameters (10, -1): (" << pos4.getX() << ", " << pos4.getY() << ")";
    //
    // Try creating a Position object with two parameters (-1, 10)
    Position pos5 = Position(-1, 10);
    qDebug() << "Position with parameters (-1, 10): (" << pos5.getX() << ", " << pos5.getY() << ")";

}