// QtChessGame.cpp: Central file for managing the chess game logic and states, like turns and checks/checkmates.

#include "QtChessGame.h"

QtChessGame::QtChessGame(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

QtChessGame::~QtChessGame()
{}

// Game management methods, such as switch turns, check for check/checkmate, and handle endgame.
