/*
Auteur: Jerry Lau
Travail : TP GoBan
Nom du ficher: principale.h
Date: 05 May 2020
But: Definition de la classe Principale
*/

#ifndef PRINCIPALE_H
#define PRINCIPALE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QMenu>
#include <QAction>
#include "accueil.h"
#include "apropos.h"
#include "reglements.h"
#include "jeusudokuz.h"

class Principale : public QMainWindow
{
    Q_OBJECT
public:
    Principale();
    ~Principale();

public slots:
    void recevoirMenuAcc(void);
    void recevoirJeu(void);
    void recevoirMenuAPro(void);
    void recevoirMenuReg(void);

protected:
    QMenu *m_menu;
    QAction *m_NouvellePartie;
    QAction *m_Quitter;
    QAction *m_Reglements;
    QAction *m_Apropos;

    Accueil *m_fenAcc;
    APropos *m_fenAPro;
    Reglements *m_fenReg;
    JeuSudokuz *m_fenJeu;
};

#endif // PRINCIPALE_H
