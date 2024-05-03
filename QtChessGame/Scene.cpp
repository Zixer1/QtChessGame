#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsItem>
#include <QLabel>
#include <QGraphicsTextItem>
#include <QFont>
#include <QImage>

#include "Scene.h"

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




void gui::Scene::displayChessBoard(int newChessBoardSize) {
	chessBoardSize = newChessBoardSize;
	if (getCurrentScene() != 2) {
		qDebug() << "Error: Scene is not set to the game scene.";
		throw std::out_of_range("Invalid Scene");
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
		throw std::out_of_range("Invalid Scene");
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
void gui::Scene::loadAndDisplayChessPiece(const QString &imagePath, const std::array<int, 3> &pixelSizes, bool underPieceLimit) {
    QImage chessPiece;
    if (!chessPiece.load(imagePath)) {
        qDebug() << "Failed to load chess board image from " << imagePath;
		throw std::invalid_argument("Failed to load image");
        return;
    }
	else if(underPieceLimit) {
		chessPiece = chessPiece.scaled(pixelSizes[2], pixelSizes[2], Qt::KeepAspectRatio);
		QGraphicsPixmapItem* chessPieceItem = new QGraphicsPixmapItem(QPixmap::fromImage(chessPiece));
		chessPieceItem->setPos(pixelSizes[0], pixelSizes[1]);
		scene->addItem(chessPieceItem); // Adding the chess piece to the scene
	}
	else {
		qDebug() << "Error: Too many of the same piece on the board";
		throw std::out_of_range("Too many kings are being spawned");
	}
}


void gui::Scene::displayChessPiece(Square squareToPlace) {
	if (getCurrentScene() != 2) {
		qDebug() << "Error: Scene is not set to the game scene.";
		return;
	}

	std::array<int, 3> PixelSizes = squareToPlace.getPosition().getPixelPositionFromChessPosition();
	QString basePath = "images/PlayingWindow_images/";
	QString piecePath;
	bool underPieceLimit{ true };

	switch (squareToPlace.getPieceType()) {
	case PieceType::Null:
		qDebug() << "No piece on this square";
		break;
	case PieceType::WhitePawn:
		qDebug() << "White Pawn";
		piecePath = basePath + "white_pieces/white-pawn.png";
		break;
	case PieceType::WhiteKnight:
		qDebug() << "White Knight";
		piecePath = basePath + "white_pieces/white-knight.png";
		break;
	case PieceType::WhiteBishop:
		qDebug() << "White Bishop";
		piecePath = basePath + "white_pieces/white-bishop.png";
		break;
	case PieceType::WhiteRook:
		qDebug() << "White Rook";
		piecePath = basePath + "white_pieces/white-rook.png";
		break;
	case PieceType::WhiteQueen:
		qDebug() << "White Queen";
		piecePath = basePath + "white_pieces/white-queen.png";
		break;
	case PieceType::WhiteKing:
		qDebug() << "Attempt to spawn White King";
		incrementWhiteKingCounter();
		underPieceLimit = allowedToPlaceKing(PieceType::WhiteKing);
		piecePath = basePath + "white_pieces/white-king.png";
		break;
	case PieceType::BlackPawn:
		qDebug() << "Black Pawn";
		piecePath = basePath + "black_pieces/black-pawn.png";
		break;
	case PieceType::BlackKnight:
		qDebug() << "Black Knight";
		piecePath = basePath + "black_pieces/black-knight.png";
		break;
	case PieceType::BlackBishop:
		qDebug() << "Black Bishop";
		piecePath = basePath + "black_pieces/black-bishop.png";
		break;
	case PieceType::BlackRook:
		qDebug() << "Black Rook";
		piecePath = basePath + "black_pieces/black-rook.png";
		break;
	case PieceType::BlackQueen:
		qDebug() << "Black Queen";
		piecePath = basePath + "black_pieces/black-queen.png";
		break;
	case PieceType::BlackKing:
		qDebug() << "Attempt to spawn Black King";
		incrementBlackKingCounter();
		underPieceLimit = allowedToPlaceKing(PieceType::BlackKing);
		piecePath = basePath + "black_pieces/black-king.png";
		break;
	default:
		qDebug() << "Unknown piece type";
		return;  // Exit the function if the piece type is unknown
	}
	if (!piecePath.isEmpty()) {
		loadAndDisplayChessPiece(piecePath, PixelSizes, underPieceLimit);
	}
}


void gui::Scene::setSelfAsScene() {
		setScene(scene);
	}
