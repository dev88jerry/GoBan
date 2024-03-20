/*
Auteur: Jerry Lau
Travail : TP GoBan
Nom du ficher: accueil.h
Date: 05 May 2020
But: Definition de la classe Accueil
*/

#ifndef ACCUEIL_H
#define ACCUEIL_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QObject>
#include <QAction>
#include "jeusudokuz.h"

class Accueil : public QWidget
{
    Q_OBJECT
public:
    Accueil();
    ~Accueil();

public slots:
    void slotJeu(void);

protected:
    QVBoxLayout *m_layoutAcc;
    QLabel *m_labelLogo;
    QPushButton *m_NP;
    QPushButton *m_Quit;

    JeuSudokuz *m_jeu;
};

#endif // ACCUEIL_H
