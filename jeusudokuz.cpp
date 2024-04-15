/*
Auteur: Jerry Lau
Travail : TP GoBan
Nom du ficher: jeusudokuz.cpp
Date: 05 May 2020
But: Application de la classe JeuSudokuz
*/

#include "jeusudokuz.h"
#include <QDebug>
#include <QEvent>
#include <QPixmap>
#include <QImage>

using namespace std;

JeuSudokuz::JeuSudokuz()
{
    m_jeu = new QGridLayout;
    m_newP = new NewP;
    m_joueur1 = new QLabel;
    m_joueur2 = new QLabel;

    //pixmap
    m_grille = new QLabel("Grid");
    m_grille->setPixmap(QPixmap(":src/img/grid.png"));

    m_fermer = new QPushButton("Fermer");
    QObject::connect(m_fermer, SIGNAL(clicked()), this, SLOT(fermer()));

    m_newG = new QPushButton("Nouvelle partie");
    QObject::connect(m_newG, SIGNAL(clicked()), this, SLOT(fenNewP()));

    m_resetG = new QPushButton("Recommencer");
    QObject::connect(m_resetG, SIGNAL(clicked()), this, SLOT(resetGame()));

    m_jeu->addWidget(m_grille);
    m_jeu->addWidget(m_newG);
    m_jeu->addWidget(m_resetG);
    m_jeu->addWidget(m_fermer);

    setLayout(m_jeu);    
}

JeuSudokuz::~JeuSudokuz()
{

}

void JeuSudokuz::mouseReleaseEvent(QMouseEvent *event)
{
    if(startG){
        int tx = event->x();
        tx-=12;
        int ty = event->y();
        ty-=12;

        //x coord
        int j=0,l=0;
        for (int i = 0; i < 13; i++) {
            j = (i * 50) + 25;
            l = (i * 50) + 75;
            if(tx >= j && tx < l){
                xg = (i * 50) + 50;
            }
        }
        //y coord
        j=0,l=0;
        for (int i = 0; i < 13; i++) {
            j = (i * 50) + 25;
            l = (i * 50) + 75;
            if(ty>=j && ty<l){
                yg = (i * 50) + 50;
            }
        }

        if(grid[(xg-50)/50][(yg-50)/50] == 0){
            dis = true;
            update();
        }

    }
    else{
        event->ignore();
    }
}

void JeuSudokuz::paintEvent(QPaintEvent *event)
{
    if(dis){
        //QImage tmp(m_grille->pixmap()->toImage());

        QPixmap pixmap = m_grille->pixmap();

        QImage tmp(pixmap.toImage());

        QPainter m_imp(&tmp);

        //prev
        if(xp != -1 && yp != -1){
            if(grid[(xp-50)/50][(yp-50)/50] == 1){
                m_imp.setBrush(Qt::black);
            }else{
                m_imp.setBrush(Qt::white);
            }
            m_imp.drawEllipse(xp-20,yp-20,40,40);
        }

        if(t%2==0){
           m_imp.setBrush(Qt::black);
           grid[(xg-50)/50][(yg-50)/50] = 1;
        }
        else{
           m_imp.setBrush(Qt::white);
           grid[(xg-50)/50][(yg-50)/50] = 2;

        }
        t++;

        //current
        m_imp.drawEllipse(xg-20,yg-20,40,40);
        m_imp.setBrush(Qt::green);
        m_imp.drawRect(xg-5,yg-5,10,10);

        xp = xg;
        yp = yg;

        m_grille->setPixmap(QPixmap::fromImage(tmp));

        dis = false;

        winG = gagner();

        if(winG){
            fenGagner();
            startG = false;
        }
    }
}

bool JeuSudokuz::gagner()
{
    int *gCheck[13][13] = { 0 };

    //copy into grid check
    //0=emp,1=b,2=w
    //x
    for (int i = 0; i < 13; i++) {
        //y
        for (int j = 0; j < 13; j++) {
            gCheck[i][j] = &grid[i][j];
        }
    }

    bool bWin = false;
    bool wWin = false;

    for(int xCoord = 0; xCoord < BOARD_SIZE; xCoord++){
        for(int yCoord = 0; yCoord < BOARD_SIZE; yCoord++){
            int vertBlack, horzBlack, diagLBlack, diagRBlack = 0;
            int vertWhite, horzWhite, diagLWhite, diagRWhite = 0;
            for(int i = 1; i < 5; i++){
                if(yCoord + i >= BOARD_SIZE && xCoord + i >= BOARD_SIZE && xCoord - i < 0){
                    if(*gCheck[xCoord + i][yCoord]== BLACK){
                        horzBlack++;
                    }
                    if(*gCheck[xCoord][yCoord + i]== BLACK){
                        vertBlack++;
                    }
                    if(*gCheck[xCoord + i][yCoord + i]== BLACK){
                        diagRBlack++;
                    }
                    if(*gCheck[xCoord - i][yCoord+i]== BLACK){
                        diagLBlack++;
                    }
                    if(*gCheck[xCoord + i][yCoord]== WHITE){
                        horzWhite++;
                    }
                    if(*gCheck[xCoord][yCoord + i]== WHITE){
                        vertWhite++;
                    }
                    if(*gCheck[xCoord + i][yCoord + i]== WHITE){
                        diagRWhite++;
                    }
                    if(*gCheck[xCoord - i][yCoord+i]== WHITE){
                        diagLWhite++;
                    }
                }
                else if(yCoord + i >= BOARD_SIZE && xCoord + i >= BOARD_SIZE){
                    if(*gCheck[xCoord + i][yCoord]== BLACK){
                        horzBlack++;
                    }
                    if(*gCheck[xCoord][yCoord + i]== BLACK){
                        vertBlack++;
                    }
                    if(*gCheck[xCoord + i][yCoord + i]== BLACK){
                        diagRBlack++;
                    }
                    if(*gCheck[xCoord + i][yCoord]== WHITE){
                        horzWhite++;
                    }
                    if(*gCheck[xCoord][yCoord + i]== WHITE){
                        vertWhite++;
                    }
                    if(*gCheck[xCoord + i][yCoord + i]== WHITE){
                        diagRWhite++;
                    }
                }
                else if(yCoord + i >= BOARD_SIZE){
                    if(*gCheck[xCoord][yCoord + i]== BLACK){
                        vertBlack++;
                    }
                    if(*gCheck[xCoord][yCoord + i]== WHITE){
                        vertWhite++;
                    }
                }
                else if(xCoord + i >= BOARD_SIZE){
                    if(*gCheck[xCoord + i][yCoord]== BLACK){
                        horzBlack++;
                    }
                    if(*gCheck[xCoord + i][yCoord]== WHITE){
                        horzWhite++;
                    }
                }
                else if(xCoord - i < 0 && yCoord + i >= BOARD_SIZE){
                    if(*gCheck[xCoord - i][yCoord+i]== BLACK){
                        diagLBlack++;
                    }
                    if(*gCheck[xCoord - i][yCoord+i]== WHITE){
                        diagLWhite++;
                    }
                }
            }
            if(vertBlack == 5 || horzBlack == 5 || diagLBlack == 5 || diagRBlack == 5){
                bWin = true;
                break;
            }
            else if(vertWhite == 5 || horzWhite == 5 || diagLWhite == 5 || diagRWhite == 5){
                wWin = true;
                break;
            }
        }
    }

    bool winQ = false;

    if (bWin == true || wWin == true) {
        winQ = true;
    }

    return winQ;
}

void JeuSudokuz::setOpenG(bool s)
{
    open = s;
}

bool JeuSudokuz::isOpen()
{
    return open;
}

void JeuSudokuz::fenNewP()
{
    m_newP->show();
    startG = true;
    resetGame();
}

void JeuSudokuz::fermer()
{
    close();
    open = false;
}

void JeuSudokuz::fenGagner()
{
    m_gagnant = new Gagnant;
    m_gagnant->show();
}

void JeuSudokuz::resetGame()
{
    m_grille->clear();
    m_grille->setPixmap(QPixmap(":src/img/grid.png"));

    //reset grid
    for(int i=0;i<13;i++){
        for(int j=0;j<13;j++){
            grid[i][j]=0;
        }
    }

    t=0;
    xp=-1;
    yp=-1;

    if(winG){
        startG = true;
    }
}
