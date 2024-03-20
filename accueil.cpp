/*
Auteur: Jerry Lau
Travail : TP GoBan
Nom du ficher: accueil.cpp
Date: 05 May 2020
But: Application de la classe Accueil
*/

#include "accueil.h"
#include <QApplication>
#include <QDebug>

Accueil::Accueil() : QWidget()
{
    m_layoutAcc = new QVBoxLayout;
    m_jeu = new JeuSudokuz;

    m_NP = new QPushButton("Nouvelle partie");
    m_Quit = new QPushButton("Quitter");

    QObject::connect(m_Quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    QObject::connect(m_NP, SIGNAL(clicked()), this, SLOT(slotJeu()));

    m_labelLogo = new QLabel("Logo");
    m_labelLogo->setPixmap(QPixmap(":src/img/titre.png"));

    m_layoutAcc->addWidget(m_labelLogo);
    m_layoutAcc->addWidget(m_NP);
    m_layoutAcc->addWidget(m_Quit);

    setLayout(m_layoutAcc);
}

Accueil::~Accueil()
{

}

void Accueil::slotJeu()
{
    m_jeu->show();
}

