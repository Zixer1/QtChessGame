#pragma once
// QtChessGame.h: Header for the main chess game management.
#ifndef QTCHESSGAME_H
#define QTCHESSGAME_H
#include <QtWidgets/QMainWindow>
#include "ui_QtChessGame.h"

class QtChessGame : public QMainWindow
{
    Q_OBJECT

public:
    QtChessGame(QWidget *parent = nullptr);
    ~QtChessGame();

private:
    Ui::QtChessGameClass ui;
};
#endif // QTCHESSGAME_H
