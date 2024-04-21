#include "Scene.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsItem>
#include <QLabel>
#include <QGraphicsTextItem>
#include <QFont>
#include <QImage>

// Namespace is global to Scene.cpp only for defining the Position class methods


gui::Scene::Scene() {
		// Constructor code here
		scene = new QGraphicsScene();
		currentScene = 0;
		// Main menu
		
		

	}

	// testing constructor
gui::Scene::Scene(int sceneSelector, int testSceneSizeAddX, int testSceneSizeY)  {
		// Constructor code here
		// Game
		// Chess board size in pixels, adjust here if needed
		chessBoardSize = testSceneSizeY;
		windowSizeAddX = testSceneSizeAddX;
		scene = new QGraphicsScene();
		currentScene = 0;
		qreal x{};
		qreal y{};
		QFont font{};

		switch (sceneSelector) {

		case 1: {

				setSceneRect(0, 0, windowSizeX, windowSizeY);
				setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
				setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
				setRenderHint(QPainter::Antialiasing);
				setRenderHint(QPainter::TextAntialiasing);
				setRenderHint(QPainter::SmoothPixmapTransform);
				setCacheMode(QGraphicsView::CacheBackground);
				setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
				setWindowTitle("Chess Game");
				setFixedSize(windowSizeX, windowSizeY);
				setStyleSheet("background-color: white;");

				// Create and configure the text item
				QGraphicsTextItem* textItem = new QGraphicsTextItem("Start Screen");
				QFont font("Arial", 20, QFont::Bold);
				textItem->setFont(font);
				textItem->setDefaultTextColor(Qt::black);

				// Calculate position to center the text in the scene
				qreal x = windowSizeX / 2 - textItem->boundingRect().width() / 2;
				qreal y = windowSizeY / 2 - textItem->boundingRect().height() / 2;
				textItem->setPos(x, y);

				// Add the text item to the scene
				scene->addItem(textItem);

				setScene(scene);
				show();
				currentScene = 1;
				break;
			}
		case 2: {



			scene->setSceneRect(0, 0, windowSizeX, windowSizeY);
			setFixedSize(windowSizeX, windowSizeY);
			setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
			setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

			setScene(scene);
			show();
			currentScene = 2;
			break;
		}
		case 3: {
			setSceneRect(0, 0, windowSizeX, windowSizeY);
			setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
			setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
			setRenderHint(QPainter::Antialiasing);
			setRenderHint(QPainter::TextAntialiasing);
			setRenderHint(QPainter::SmoothPixmapTransform);
			setCacheMode(QGraphicsView::CacheBackground);
			setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
			setWindowTitle("Chess Game");
			setFixedSize(windowSizeX, windowSizeY);
			setStyleSheet("background-color: white;");

			// Create and configure the text item
			QGraphicsTextItem* textItem = new QGraphicsTextItem("End Screen");
			QFont font("Arial", 20, QFont::Bold);
			textItem->setFont(font);
			textItem->setDefaultTextColor(Qt::red);

			// Calculate position to center the text in the scene
			qreal x = windowSizeX / 2 - textItem->boundingRect().width() / 2;
			qreal y = windowSizeY / 2 - textItem->boundingRect().height() / 2;
			textItem->setPos(x, y);

			// Add the text item to the scene
			scene->addItem(textItem);

			setScene(scene);
			show();
			currentScene = 3;
			break;
		}
		default:
			// Default to main menu
			break;
		}
	}

gui::Scene::~Scene() {
		// Destructor code here
		delete scene;
	}

int gui::Scene::getCurrentScene() {
		return currentScene;
	}

int gui::Scene::getChessBoardSize() {
		return chessBoardSize;
	}

int gui::Scene::getWindowSizeX() {
		return windowSizeX;
	}

void gui::Scene::displayChessBoard(int newChessBoardSize) {
	QImage chessBoard;
	if (!chessBoard.load("C:/Users/Alex/source/repos/QtChessGame/QtChessGame/images/PlayingWindow_images/ChessBoards/chessboard1.png")) {
		qDebug() << "Failed to load chess board image.";
	}
	else {

		// Scale the chess board image to the specified dimensions
		chessBoard = chessBoard.scaled(chessBoardSize, chessBoardSize, Qt::KeepAspectRatio);

		QGraphicsPixmapItem* chessBoardItem = new QGraphicsPixmapItem(QPixmap::fromImage(chessBoard));
		scene->addItem(chessBoardItem); // Adding chess board as a child of the scene
	}

}

void gui::Scene::displayChessLogo(int chessLogoSize) {
	QImage chessLogo;
	if (!chessLogo.load("C:/Users/Alex/source/repos/QtChessGame/QtChessGame/images/PlayingWindow_images/ChessLogoFinal.png")) {
		qDebug() << "Failed to load chess board image.";
	}
	else {

		chessLogo = chessLogo.scaled(chessLogoSize, chessLogoSize, Qt::KeepAspectRatio);

		QGraphicsPixmapItem* chessLogoItem = new QGraphicsPixmapItem(QPixmap::fromImage(chessLogo));
		chessLogoItem->setPos((chessBoardSize + (windowSizeX - chessBoardSize) / 2) - chessLogoSize / 2, -25);
		scene->addItem(chessLogoItem); // Adding chess board as a child of the scene
	}
}

void gui::Scene::setSelfAsScene() {
		setScene(scene);
	}
