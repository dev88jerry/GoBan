/*
Auteur: Jerry Lau
Travail : TP GoBan
Nom du ficher: newp.cpp
Date: 05 May 2020
But: Application de la classe NewP
*/

#include "newp.h"
#include <QDebug>

NewP::NewP() : QWidget()
{
    m_layoutNewP = new QGridLayout;

    m_labelNewP = new QLabel("Commencer une nouvelle partie");
    m_labelNewP->setFont(QFont("Arial", 12));
    m_labelNewP->setAlignment(Qt::AlignLeft);
    m_labelNewP->setWordWrap(true);

    m_nom1 = new QLineEdit;
    m_nom1->setPlaceholderText("Joueur 1");
    //m_nom1->setFocus();

    m_nom2 = new QLineEdit;
    m_nom2->setPlaceholderText("Joueur 2");
    //m_nom2->setFocus();

    m_start = new QPushButton("Commencer");

    //m_layoutNewP->addWidget(m_labelNewP,0,0,3,3);
    m_layoutNewP->addWidget(m_labelNewP,0,0,Qt::AlignLeft);
    m_layoutNewP->addWidget(m_nom1,1,0);
    m_layoutNewP->addWidget(m_nom2,1,1);
    m_layoutNewP->addWidget(m_start,1,2);
    QObject::connect(m_start,SIGNAL(clicked()), this, SLOT(slotDebut()));

    m_quit = new QPushButton("Fermer");
    QObject::connect(m_quit, SIGNAL(clicked()), this, SLOT(slotFermer()));

    m_layoutNewP->addWidget(m_quit,2,0,Qt::AlignBottom);

    setLayout(m_layoutNewP);
}

NewP::~NewP()
{

}

void NewP::slotFermer()
{
    close();
}

void NewP::echoNom1(void)
{
    m_nom1->setEchoMode(QLineEdit::Normal);
    m_nom1->text().toStdString();
}

void NewP::echoNom2(void)
{
    m_nom2->setEchoMode(QLineEdit::Normal);
    m_nom2->text().toStdString();
}

void NewP::slotDebut()
{
    close();
}
