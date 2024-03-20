/*
Auteur: Jerry Lau
Travail : TP GoBan
Nom du ficher: gagnant.cpp
Date: 05 May 2020
But: Application de la classe Gagnant
*/

#include "gagnant.h"

Gagnant::Gagnant()
{
    m_layoutG = new QVBoxLayout;
    m_fermer = new QPushButton("Fermer");
    QObject::connect(m_fermer, SIGNAL(clicked()), this, SLOT(slotFermer()));

    m_labelG = new QLabel("Vous avez gagne!!! :D");
    m_labelP = new QLabel("Vous avez perdu :( ");

    if(true){
        m_layoutG->addWidget(m_labelG);
    }else{
        m_layoutG->addWidget(m_labelP);
    }
    m_layoutG->addWidget(m_fermer);

    setLayout(m_layoutG);
}

Gagnant::~Gagnant()
{

}

void Gagnant::slotFermer()
{
    close();
}
