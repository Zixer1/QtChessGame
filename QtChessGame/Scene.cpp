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

		switch (sceneSelector) {

		case 1: {
				// TODO: Replace with actual main menu, and Buttons
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
			// TODO: Replace with actual end menu, and Buttons
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

std::array<int, 3> gui::Scene::getPixelPositionFromChessPosition(data_model::Position position) {
	if (getCurrentScene() != 2) {
		qDebug() << "Error: Scene is not set to the game scene.";
		throw std::out_of_range("Cannot get Pixel Position in a Screen that is not the Playing Screen");
		return { -10000,-10000 }; // returns a very high negative number in case of an error for it to display off screen
	}

	// Convert chess position to pixel position
	int sizeOfChessBoard = getChessBoardSize();
	std::array<int, 3> pixelPosition = { 0, 0, 0 };
	if (position.getX() == 0 || position.getY() == 0) {
		qDebug() << "Error: Invalid chess position trying to get placed.";
		throw std::out_of_range("Invalid chess position");
		return { -10000,-10000 }; // returns a very high negative number in case of an error for it to display off screen
	}

	pixelPosition[0] = (position.getX() * (sizeOfChessBoard/8)) - sizeOfChessBoard/8;
	pixelPosition[1] = (position.getY() * (sizeOfChessBoard/8)) - sizeOfChessBoard/8;
	pixelPosition[2] = sizeOfChessBoard/8;
	return pixelPosition;
}


void gui::Scene::displayChessBoard(int newChessBoardSize) {
	chessBoardSize = newChessBoardSize;
	if (getCurrentScene() != 2) {
		qDebug() << "Error: Scene is not set to the game scene.";
		return;
	}
	QImage chessBoard;
	if (!chessBoard.load("images/PlayingWindow_images/ChessBoards/chessboard1.png")) {
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
	if (getCurrentScene() != 2) {
		qDebug() << "Error: Scene is not set to the game scene.";
		return;
	}
	QImage chessLogo;
	if (!chessLogo.load("images/PlayingWindow_images/ChessLogoFinal.png")) {
		qDebug() << "Failed to load chess board image.";
	}
	else {

		chessLogo = chessLogo.scaled(chessLogoSize, chessLogoSize, Qt::KeepAspectRatio);

		QGraphicsPixmapItem* chessLogoItem = new QGraphicsPixmapItem(QPixmap::fromImage(chessLogo));
		chessLogoItem->setPos((chessBoardSize + (windowSizeX - chessBoardSize) / 2) - chessLogoSize / 2, -25);
		scene->addItem(chessLogoItem); // Adding chess board as a child of the scene
	}
}

// TODO: Implement the displayChessPiece method for each piece type and not just the King

void gui::Scene::displayChessPiece(Square squareToPlace) {
	if (getCurrentScene() != 2) {
		qDebug() << "Error: Scene is not set to the game scene.";
		return;
	}
	QImage chessPiece;
	std::array<int, 3> PixelSizes = getPixelPositionFromChessPosition(squareToPlace.getPosition());
	switch (squareToPlace.getPieceType()) {
		case PieceType::Null: {
			qDebug() << "No piece on this square";
			break;
		}
		case PieceType::WhitePawn: {
			qDebug() << "White Pawn";
			break;
		}
		case PieceType::WhiteKnight: {
			qDebug() << "White Knight" ;
			break;
		}
		case PieceType::WhiteBishop: {
			qDebug() << "White Bishop";
			break;
		}
		case PieceType::WhiteRook: {
			qDebug() << "White Rook";
			break;
		}
		case PieceType::WhiteQueen: {
			qDebug() << "White Queen";
			break;
		}
		case PieceType::WhiteKing: {
			qDebug() << "White King";
			
			if (!chessPiece.load("images/PlayingWindow_images/white_pieces/white-king.png")) {
				qDebug() << "Failed to load chess board image.";
			}
			else {

				chessPiece = chessPiece.scaled(PixelSizes[2], PixelSizes[2], Qt::KeepAspectRatio);

				QGraphicsPixmapItem* chessLogoItem = new QGraphicsPixmapItem(QPixmap::fromImage(chessPiece));
				chessLogoItem->setPos(PixelSizes[0], PixelSizes[1]);
				scene->addItem(chessLogoItem); // Adding chess board as a child of the scene
			}
			break;
		}
		case PieceType::BlackPawn: {
			qDebug() << "Black Pawn";
			break;
		}
		case PieceType::BlackKnight: {
			qDebug() << "Black Knight";
			break;
		}
		case PieceType::BlackBishop: {
			qDebug() << "Black Bishop";
			break;
		}
		case PieceType::BlackRook: {
			qDebug() << "Black Rook";
			break;
		}
		case PieceType::BlackQueen: {
			qDebug() << "Black Queen";
			break;
		}
		case PieceType::BlackKing: {
			qDebug() << "Black King";
			break;
		}
		default: {
			qDebug() << "Unknown piece";
			break;
		}
	}

}

void gui::Scene::setSelfAsScene() {
		setScene(scene);
	}
