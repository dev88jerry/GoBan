/*
Auteur: Jerry Lau
Travail : TP GoBan
Nom du ficher: reglements.cpp
Date: 05 May 2020
But: Application de la classe Reglements
*/

#include "reglements.h"

Reglements::Reglements():QWidget()
{
    m_layoutR = new QVBoxLayout;
    m_fermer = new QPushButton("Fermer");

    m_labelRegle = new QLabel("Reglements du jeu");
    m_labelRegle->setFont(QFont("Arial", 24));
    m_labelRegle->setAlignment(Qt::AlignCenter);

    m_labelR = new QLabel("C'est un jeu de société traditionnel joué avec des pièces de go (pierres noires et blanches originaires de Chine).\nLa pierre noir doit passer en premier. Chaque personne doit placer ses pierres à la croix.\nLa première personne à avoir 5 pierres d'affilée gagne la partie.");
    m_labelR->setAlignment(Qt::AlignLeft);
    m_labelR->setFont(QFont("Arial", 10));
    m_labelR->setWordWrap(true);

    m_layoutR->addWidget(m_labelRegle);
    m_layoutR->addWidget(m_labelR);
    m_layoutR->addWidget(m_fermer);

    QObject::connect(m_fermer, SIGNAL(clicked()), this, SLOT(slotFermer()));

    setLayout(m_layoutR);
}

Reglements::~Reglements()
{

}

void Reglements::slotFermer()
{
    close();
}
