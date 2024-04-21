// Scene.h: Header for managing the graphical display of the chess game.
#ifndef DISPLAY_H
#define DISPLAY_H

#include <QGraphicsView>
#include <QWidget>

namespace gui {
    // Class Scene inherits from QGraphicsView to handle the visual representation.
    class Scene : public QGraphicsView {
    private:
        
        int currentScene; //3 possible scenes: 0 main menu, 1 game, 2 game over

    public:
        QGraphicsScene* scene;   // Scene for rendering graphical items
        Scene(QWidget* parent = nullptr);
        // In case of testing, we can set the scene
        Scene(int scene,int testSceneSizeX = 0, int testSceneSizeY = 0, QWidget* parent = nullptr);

        // Destructor
        ~Scene();

        // Methods
        void setSelfAsScene();

    };
}
#endif /* DISPLAY_H */
