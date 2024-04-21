// Scene.h: Header for managing the graphical display of the chess game.
#ifndef DISPLAY_H
#define DISPLAY_H

#include <QGraphicsView>
#include <QWidget>

namespace gui {
    // Class Scene inherits from QGraphicsView to handle the visual representation.
    class Scene : public QGraphicsView {
    private:
        
        int currentScene; //4 possible scenes: 0 not initialized, 1 start, 2 game, 3 end
        int chessBoardSize = 800;
        int windowSizeY = chessBoardSize;
        int windowSizeAddX = 300;
        int windowSizeX = chessBoardSize + windowSizeAddX;

    public:
        QGraphicsScene* scene;   // Scene for rendering graphical items
        Scene();
        // In case of testing, we can set the scene
        Scene(int sceneSelector, int testSceneSizeX = 800, int testSceneSizeExtraY = 800);

        // Destructor
        ~Scene();

        // Methods
        int getCurrentScene();
        int getChessBoardSize();
        int getWindowSizeX();

        void displayChessBoard(int newChessBoardSize = 800);

        void displayChessLogo(int chessLogoSize = 400);

        void setSelfAsScene();

    };
}
#endif /* DISPLAY_H */
