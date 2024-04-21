#include <QtWidgets/QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QApplication>
#include <QPixmap> // Include QPixmap header for handling images
#include "Scene.h"
#include <QDebug>
#include <array>

/* Test 0: Displaying the chess board and logo, and getting pixel position from chess position in the debug console for 800x800 board
 Expected Output:
 0, 0
 100, 100
 700, 700
 ERROR and -10000, -10000

 Test 1: Displaying the chess board and logo, and getting pixel position from chess position in the debug console for 1000x1000 board
  Expected Output:
 0, 0
 125, 125
 875, 875
 ERROR and -10000, -10000

 Test 2: Seeing if the errors are properly thrown for each get of pixel position from chess position before displaying the board and logo in the debug console for 800x800 board
 Should give 4 errors related to the Pixel position



void testPixToPos(gui::Scene* mainScene, int test){
        
        // Change between 0, 1, 2 to test different scenarios

        
    if (test == 0) {
        std::array<int, 3> pixelPosition;
        mainScene = new gui::Scene(2);

        qDebug() << "Intitializing the Chess Board";
        mainScene->gui::Scene::displayChessBoard(800);
        mainScene->gui::Scene::displayChessLogo(400);
        pixelPosition = mainScene->gui::Scene::getPixelPositionFromChessPosition(data_model::Position(1, 1));
        qDebug() << "Pixel Position: " << pixelPosition[0] << ", " << pixelPosition[1];
        pixelPosition = mainScene->gui::Scene::getPixelPositionFromChessPosition(data_model::Position(2, 2));
        qDebug() << "Pixel Position: " << pixelPosition[0] << ", " << pixelPosition[1];
        pixelPosition = mainScene->gui::Scene::getPixelPositionFromChessPosition(data_model::Position(8, 8));
        qDebug() << "Pixel Position: " << pixelPosition[0] << ", " << pixelPosition[1];



        // Should give an error
        pixelPosition = mainScene->gui::Scene::getPixelPositionFromChessPosition(data_model::Position(1, 1));
        qDebug() << "Pixel Position: " << pixelPosition[0] << ", " << pixelPosition[1];
    }

    if (test == 1) {
        std::array<int, 3> pixelPosition;
        mainScene = new gui::Scene(2);

        qDebug() << "Intitializing the Chess Board";
        mainScene->gui::Scene::displayChessBoard(1000);
        mainScene->gui::Scene::displayChessLogo(400);
        pixelPosition = mainScene->gui::Scene::getPixelPositionFromChessPosition(data_model::Position(1, 1));
        qDebug() << "Pixel Position: " << pixelPosition[0] << ", " << pixelPosition[1];
        pixelPosition = mainScene->gui::Scene::getPixelPositionFromChessPosition(data_model::Position(2, 2));
        qDebug() << "Pixel Position: " << pixelPosition[0] << ", " << pixelPosition[1];
        pixelPosition = mainScene->gui::Scene::getPixelPositionFromChessPosition(data_model::Position(8, 8));
        qDebug() << "Pixel Position: " << pixelPosition[0] << ", " << pixelPosition[1];



        // Should give an error
        pixelPosition = mainScene->gui::Scene::getPixelPositionFromChessPosition(data_model::Position(1, 1));
        qDebug() << "Pixel Position: " << pixelPosition[0] << ", " << pixelPosition[1];
    }

    if (test == 2) {
        std::array<int, 3> pixelPosition;
        mainScene = new gui::Scene(1);

        pixelPosition = mainScene->gui::Scene::getPixelPositionFromChessPosition(data_model::Position(1, 1));
        qDebug() << "Pixel Position: " << pixelPosition[0] << ", " << pixelPosition[1];
        pixelPosition = mainScene->gui::Scene::getPixelPositionFromChessPosition(data_model::Position(2, 2));
        qDebug() << "Pixel Position: " << pixelPosition[0] << ", " << pixelPosition[1];
        pixelPosition = mainScene->gui::Scene::getPixelPositionFromChessPosition(data_model::Position(8, 8));
        qDebug() << "Pixel Position: " << pixelPosition[0] << ", " << pixelPosition[1];
        pixelPosition = mainScene->gui::Scene::getPixelPositionFromChessPosition(data_model::Position(1, 1));
        qDebug() << "Pixel Position: " << pixelPosition[0] << ", " << pixelPosition[1];
        qDebug() << "Intitializing the Chess Board";
        mainScene->gui::Scene::displayChessBoard(800);
        mainScene->gui::Scene::displayChessLogo(400);
    }


}
 */