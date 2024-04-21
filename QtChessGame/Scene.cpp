#include "Scene.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsItem>
using namespace gui;

Scene::Scene(QWidget* parent) : QGraphicsView(parent) {
	// Constructor code here
	scene = new QGraphicsScene();
	setScene(scene);
	setSceneRect(0, 0, 800, 800);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setRenderHint(QPainter::Antialiasing);
	setRenderHint(QPainter::TextAntialiasing);
	setRenderHint(QPainter::SmoothPixmapTransform);
	setCacheMode(QGraphicsView::CacheBackground);
	setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
	setWindowTitle("Chess Game");
	setFixedSize(800, 800);
	setStyleSheet("background-color: white;");
	currentScene = 0;
}

// testing constructor
Scene::Scene(int sceneSelector, int testSceneSizeX = 0, int testSceneSizeY = 0, QWidget* parent) : QGraphicsView(parent) {
	// Constructor code here
	switch(sceneSelector) {
		case 0:
			// Main menu
			break;
		case 1:
			// Game
				// Chess board size in pixels, adjust here if needed
			int chessBoardSize{ 800 };

			// Window size in pixels, adjust here if needed
			int windowWidth{ chessBoardSize + 300 };
			int windowHeight{ chessBoardSize };

			scene = new QGraphicsScene();
			scene->setSceneRect(0, 0, windowWidth, windowHeight);
			setFixedSize(windowWidth, windowHeight);
			setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
			setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

			setScene(scene);
			show();
			break;
		case 2:
			// Game over
			break;
		default:
			// Default to main menu
			break;
	}
}

void Scene::setSelfAsScene() {
	setScene(scene);
}