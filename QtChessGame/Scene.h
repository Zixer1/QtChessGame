// Scene.h: Header for managing the graphical display of the chess game.
#ifndef DISPLAY_H
#define DISPLAY_H

#include <QGraphicsView>
#include <QWidget>
#include "PieceType.h"
#include "Square.h"
#include "Position.h"
#include <array>
namespace gui {
    // Class Scene inherits from QGraphicsView to handle the visual representation.
    class Scene : public QGraphicsView {
    private:

        int currentScene; //4 possible scenes: 0 not initialized, 1 start, 2 game, 3 end
        int chessBoardSize = 800;
        int windowSizeY = chessBoardSize;
        int windowSizeAddX = 300;
        int windowSizeX = chessBoardSize + windowSizeAddX;
        int chessPieceSize = chessBoardSize / 8;

        // TODO move the piece counter to chessboard.h
        int whiteKingCounter = 0;
        int blackKingCounter = 0;
        std::map<QPair<int, int>, QGraphicsPixmapItem*> itemMap;
        std::map<QPair<int, int>, QGraphicsEllipseItem*> itemMapAllowedMoves;


    public:
        QGraphicsScene* scene;   // Scene for rendering graphical items
        Scene();
        // In case of testing, we can set the scene
        Scene(int sceneSelector, int testSceneSizeX = 800, int testSceneSizeExtraY = 800);

        // Destructor
        ~Scene();

        // Methods
        
        bool allowedToPlaceKing(PieceType pieceType) {
            return whiteKingCounter < 2 && pieceType == PieceType::WhiteKing || blackKingCounter < 2 && pieceType == PieceType::BlackKing;
        }

        void incrementWhiteKingCounter() {
  
            ++whiteKingCounter;
        }

        void incrementBlackKingCounter() {
          
            ++blackKingCounter;
        }

        int getCurrentScene();
        int getChessBoardSize();
        void setChessBoardSize(int newChessBoardSize) {
            chessBoardSize = newChessBoardSize;
        }

        int getWindowSizeX();
        // Returns the pixel position for a given chess position, as well as the size of the ChessPiece

        void displayChessBoard(int newChessBoardSize = 800);
        void displayChessLogo(int chessLogoSize = 400);
        //Helper function to display a piece on the board
        // Return or store QGraphicsPixmapItem somewhere from the helper function so that i later can hide the piece from the board as needed
        QGraphicsPixmapItem* loadAndDisplayChessPiece(const QString& imagePath, const std::array<int, 3>& pixelSizes, bool underPieceLimit);

        // Edit this in the future to take a Piece and a Sqare
        void displayChessPiece(Square* squareToPlacePiece);
        void hideChessPiece(Square* squareToRemove);

        void displayAllowedMoves(std::array<data_model::Position*, 64> allowedMoves);
        void hideAllowedMoves();

        void setSelfAsScene();

    };
}
#endif /* DISPLAY_H */
