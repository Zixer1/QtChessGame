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
    Modèle :
    Oui - Vous devez avoir un roi et deux autres pièces de types différents, par exemple tour et cavalier.
    Oui - Votre programme devrait être conçu pour pouvoir facilement ajouter les autres types de pièces.
    Oui avec petites erreurs- Les pièces doivent savoir quels mouvements sont valides, sans tenir compte de la mise en échec (dont la
    vérification demande de regarder toutes les pièces du jeu et ce n’est donc peut-être pas à la pièce à faire cette
    vérification), pour pouvoir faire un mouvement ou dire que le mouvement n’est pas valide.
    La vérification s’il y a échec : si une pièce peut atteindre le roi adverse et ne pas permettre un mouvement qui
    nous met nous-même en échec.
    Moyen, oui mais avec des bugs a fixer - Des tests préliminaires pour vérifier qu’on peut bien bouger les pièces seulement pour des mouvements valides.
    Interface graphique :
    Oui - Affichage de l’échiquier (grille de 8×8 cases) dans une fenêtre pour y mettre les pièces, en utilisant la
    bibliothèque Qt. Les pièces peuvent être des mots/lettres dans les cases.
    Oui - On veut pouvoir indiquer avec le curseur de la souris quelle pièce déplacer à quel endroit et avoir une
    rétroaction visuelle si le mouvement n’est pas permis.
    
    Non par manque de temps, mais j'ai les methodes pour le faire dans Scene.h - Avoir une manière pour dire qu’on veut démarrer une nouvelle partie et choisir d’une liste une position de
    départ (vous pouvez prendre des positions classiques ou mettre n’importe quoi).
    Non - Les tests avec aucune ligne non couverte pour la partie modèle du jeu. Vous n’avez pas à automatiser les tests
    de l’interface graphique (pas matière à ce cours).
    Oui - Vous pouvez ajouter des images à vos pièces.
    Presque, il faut integrer mon verificateur de tours (Tour du joueur blanc ou noir), ajouter la mise en echec, et fixer un peu de bugs - Avoir un jeu fonctionnel.
    */
    
    mainScene->show();

    return a.exec();
}
