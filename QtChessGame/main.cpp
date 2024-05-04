// main.cpp: The entry point of the application that sets up the game and manages the main loop.
/*
Main File, for the project overall:
File   main.cpp
Author Alexandre Sakr and Houssam Bousbia
Date   15 April 2024
*/
#include <QtWidgets/QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QApplication>
#include <QPixmap> // Include QPixmap header for handling images
#include <QDebug>
#include <array>
#include <QTimer>
#include <QGraphicsProxyWidget>


#include "Scene.h"
#include "Square.h"
#include "Position.h"
#include "Piece.h"
#include "PieceType.h"
#include "TempMove.h"
#include "ChessBoard.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    // Since Scene is in the gui namespace, make sure to use it
    gui::Scene* mainScene;
    mainScene = new gui::Scene(2);

    // J'ai mon Main Menu et mon Game Scene, mais je sais pas pourquoi, quand je change de scene, le ChessBoard s'affiche de maniere inhabituelle
    if (mainScene->gui::Scene::getCurrentScene() == 2) {
        ChessBoard board{ mainScene };
    }
    /*
    Mod�le :
    Oui - Vous devez avoir un roi et deux autres pi�ces de types diff�rents, par exemple tour et cavalier.
    Oui - Votre programme devrait �tre con�u pour pouvoir facilement ajouter les autres types de pi�ces.
    Oui avec petites erreurs- Les pi�ces doivent savoir quels mouvements sont valides, sans tenir compte de la mise en �chec (dont la
    v�rification demande de regarder toutes les pi�ces du jeu et ce n�est donc peut-�tre pas � la pi�ce � faire cette
    v�rification), pour pouvoir faire un mouvement ou dire que le mouvement n�est pas valide.
    La v�rification s�il y a �chec : si une pi�ce peut atteindre le roi adverse et ne pas permettre un mouvement qui
    nous met nous-m�me en �chec.
    Moyen, oui mais avec des bugs a fixer - Des tests pr�liminaires pour v�rifier qu�on peut bien bouger les pi�ces seulement pour des mouvements valides.
    Interface graphique :
    Oui - Affichage de l��chiquier (grille de 8�8 cases) dans une fen�tre pour y mettre les pi�ces, en utilisant la
    biblioth�que Qt. Les pi�ces peuvent �tre des mots/lettres dans les cases.
    Oui - On veut pouvoir indiquer avec le curseur de la souris quelle pi�ce d�placer � quel endroit et avoir une
    r�troaction visuelle si le mouvement n�est pas permis.
    
    Non par manque de temps, mais j'ai les methodes pour le faire dans Scene.h - Avoir une mani�re pour dire qu�on veut d�marrer une nouvelle partie et choisir d�une liste une position de
    d�part (vous pouvez prendre des positions classiques ou mettre n�importe quoi).
    Non - Les tests avec aucune ligne non couverte pour la partie mod�le du jeu. Vous n�avez pas � automatiser les tests
    de l�interface graphique (pas mati�re � ce cours).
    Oui - Vous pouvez ajouter des images � vos pi�ces.
    Presque, il faut integrer mon verificateur de tours (Tour du joueur blanc ou noir), ajouter la mise en echec, et fixer un peu de bugs - Avoir un jeu fonctionnel.
    */
    
    mainScene->show();

    return a.exec();
}
