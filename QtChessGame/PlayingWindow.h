#pragma once
// PlayingWindow.h: Header for the game UI during play.
#ifndef PLAYINGWINDOW_H
#define PLAYINGWINDOW_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>


    class PlayingWindow : public QGraphicsView {
    public:
        QGraphicsScene* scene;

        PlayingWindow(QWidget* parent = 0);

        

    };


#endif // PLAYINGWINDOW_H
