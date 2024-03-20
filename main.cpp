/*
Auteur: Jerry Lau
Travail : TP GoBan
Nom du ficher: main.cpp
Date: 05 May 2020
But: Program QT principale pour le jeu GoBan
*/

#include <QApplication>
#include "principale.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Principale menuPricipale;

    menuPricipale.show();

    return app.exec();
}
