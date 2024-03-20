/*
Auteur: Jerry Lau
Travail : TP GoBan
Nom du ficher: principale.cpp
Date: 05 May 2020
But: Application de la classe Principale
*/

#include "principale.h"
#include <QMenuBar>
#include <QApplication>
#include <QDebug>

Principale::Principale()
{
    m_menu = new QMenu;
    m_fenAPro = new APropos;
    m_fenReg = new Reglements;
    m_fenJeu = new JeuSudokuz;
	m_fenAcc = new Accueil;

    m_menu = menuBar()->addMenu("Partie");

    m_NouvellePartie = new QAction("Nouvelle Partie");
    m_Quitter = new QAction("Quitter");

    m_menu->addAction(m_NouvellePartie);
    QObject::connect(m_NouvellePartie, SIGNAL(triggered(bool)), this, SLOT(recevoirJeu()));

    m_menu->addAction(m_Quitter);
    QObject::connect(m_Quitter, SIGNAL(triggered(bool)), qApp, SLOT(quit()));

    m_menu = menuBar()->addMenu("Aide");

    m_Reglements = new QAction("Reglements");
    m_Apropos = new QAction("A propos");

    m_menu->addAction(m_Reglements);
    m_menu->addAction(m_Apropos);

    QObject::connect(m_Reglements, SIGNAL(triggered(bool)), this, SLOT(recevoirMenuReg()));
    QObject::connect(m_Apropos, SIGNAL(triggered(bool)), this, SLOT(recevoirMenuAPro()));

    recevoirMenuAcc();
}

Principale::~Principale()
{

}

void Principale::recevoirMenuAcc()
{
    setCentralWidget(m_fenAcc);
}

void Principale::recevoirJeu()
{     
    m_fenJeu->show();
}

void Principale::recevoirMenuAPro()
{
    m_fenAPro->show();
}

void Principale::recevoirMenuReg()
{
    m_fenReg->show();
}
