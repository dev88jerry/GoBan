/*
Auteur: Jerry Lau
Travail : TP GoBan
Nom du ficher: jeusudokuz.h
Date: 05 May 2020
But: Definition de la classe JeuSudokuz
*/

#ifndef JEUSUDOKUZ_H
#define JEUSUDOKUZ_H

#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QAction>
#include <QMouseEvent>
#include <QPainter>
#include <QPixmap>
#include <QImage>
#include "newp.h"
#include "gagnant.h"

#pragma once

class JeuSudokuz : public QWidget
{
    Q_OBJECT
public:
    JeuSudokuz();
    ~JeuSudokuz();
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    bool gagner();
    void setOpenG(bool s);
    bool isOpen();

public slots:
    void fenNewP(void);
    void fermer(void);
    void fenGagner(void);
    void resetGame(void);

protected:
    QGridLayout *m_jeu;
    QLabel *m_joueur1;//string
    QLabel *m_joueur2;//string
    QLabel *m_grille;//pixmap

    QPushButton *m_fermer;
    QPushButton *m_newG;
    QPushButton *m_resetG;
    QPainter *m_imp;

    unsigned int t = 0;
    int xg=0,yg=0;
    int xp=-1,yp=-1;
    bool dis=false;
    bool startG=false;
    bool winG = false;
    bool open = true;

    //grid[x][y]
    //0=emp,1=b,2=w
    int grid[13][13]={0};

    NewP *m_newP;
    Gagnant *m_gagnant;

};

#endif // JEUSUDOKUZ_H

