#pragma once

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
