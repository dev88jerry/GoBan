/*
Auteur: Jerry Lau
Travail : TP GoBan
Nom du ficher: apropos.cpp
Date: 05 May 2020
But: Application de la classe APropos
*/

#include "apropos.h"

APropos::APropos():QWidget()
{
   m_layoutAP = new QVBoxLayout;
   m_fermer = new QPushButton("Fermer");

   m_labelLogo = new QLabel("Logo");
   m_labelLogo->setPixmap(QPixmap(":src/img/titre.png"));
   //path

   m_labelVersion = new QLabel("Version : 1.0");
   m_labelVersion->setFont(QFont("Arial", 12));
   m_labelVersion->setAlignment(Qt::AlignCenter);

   m_labelConcepteur = new QLabel("Concepteur : Jerry Lau");
   m_labelConcepteur->setFont(QFont("Arial", 12));
   m_labelConcepteur->setAlignment(Qt::AlignCenter);

   m_layoutAP->addWidget(m_labelLogo);
   m_layoutAP->addWidget(m_labelVersion);
   m_layoutAP->addWidget(m_labelConcepteur);
   m_layoutAP->addWidget(m_fermer);

   QObject::connect(m_fermer, SIGNAL(clicked()), this, SLOT(slotFermer()));

   setLayout(m_layoutAP);

}

APropos::~APropos()
{

}

void APropos::slotFermer()
{
    close();
}
