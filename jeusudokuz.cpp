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

    if (t % 2 == 1) {
        //vertical check working
        int x = 0;
        do {
            int j = 5;
            int i = 0;
            do {
                int br = 0;
                int k = i;
                do {
                    //black row
                    if (*gCheck[x][k] == 1) {
                        br += *gCheck[x][k];
                        if (br == 5) {
                            //qDebug() << "Winner black row " << x << " count: " << br << endl;
                            //cout << "Winner black row " << x << " count: " << br << endl;
                            bWin = true;
                        }
                    }
                    k++;
                } while (k < j && bWin == false);
                j++;
                i++;
            } while (i < 9 && bWin == false);
            x++;
        } while (x < 13 && bWin == false);

        if (bWin == false) {
            //horizontal check
            for (int i = 0; i < 13; i++) {
                for (int j = 0; j < 13; j++) {
                    int a = i, b = j;
                    int bc = 0;
                    for (int k = 0; k < 5; k++) {
                        if (a <= 12 && b <= 12) {
                            if (*gCheck[a][b] == 1) {
                                bc += *gCheck[a][b];
                                if (bc == 5) {
                                    //qDebug() << "start column: " << a << " ,  " << b << endl;
                                    bWin = true;
                                }
                            }
                            a++;
                        }
                    }
                    b++;
                }
            }

            //diag right
            for (int i = 0; i < 13; i++) {
                for (int j = 0; j < 13; j++) {
                    int dxr = i, dyr = j;
                    int bc = 0;
                    //diag++
                    if (dxr + 5 <= 13 && dyr + 5 <= 13) {
                        for (int sdx = dxr, sdy = dyr; dxr < sdx + 5 && dyr < sdy + 5; dxr++, dyr++) {
                            //black
                            if (*gCheck[dxr][dyr] == 1) {
                                bc += *gCheck[dxr][dyr];
                                if (bc == 5) {
                                    //qDebug() << "start X,Y: " << dxr << " ,  " << dyr << endl;
                                    //cout << "start X,Y: " << dxr << " ,  " << dyr << endl;
                                    bWin = true;
                                }
                            }
                        }
                    }
                }
            }
            //diag left
            for (int i = 12; i >= 0; i--) {
                for (int j = 0; j < 13; j++) {
                    int dxl = i, dyl = j;
                    int bc = 0;
                    if (dxl - 5 > -2 && dyl + 5 <= 13) {
                        for (int sdx = dxl, sdy = dyl; dxl >= sdx - 5 && dyl < sdy + 5; dxl--, dyl++) {
                            //black
                            if (*gCheck[dxl][dyl] == 1) {
                                bc += *gCheck[dxl][dyl];
                                if (bc == 5) {
                                    //qDebug() << "start X,Y: " << dxl << " ,  " << dyl << endl;
                                    //cout << "start X,Y: " << dxl << " ,  " << dyl << endl;
                                    bWin = true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else {
        //white check
        //vertical
        int x = 0;
        do {
            int j = 5;
            int i = 0;
            do {
                int wr = 0;
                int k = i;
                do {
                    //white row
                    if (*gCheck[x][k] == 2) {
                        wr += *gCheck[x][k];
                        if (wr == 10) {
                            //qDebug() << "Winner white row " << x << " count: " << wr << endl;
                            //cout << "Winner white row " << x << " count: " << wr << endl;
                            wWin = true;
                        }
                    }
                    k++;
                } while (k < j && wWin == false);
                j++;
                i++;
            } while (i < 9 && wWin == false);
            x++;
        } while (x < 13 && wWin == false);

        if (wWin == false) {
            //horizontal

            for (int i = 0; i < 13; i++) {
                for (int j = 0; j < 13; j++) {
                    int a = i, b = j;
                    int wc = 0;
                    for (int k = 0; k < 5; k++) {
                        if (a <= 12 && b <= 12) {
                            if (*gCheck[a][b] == 2) {
                                wc += *gCheck[a][b];
                                if (wc == 10) {
                                    //qDebug() << "start column: " << a << " ,  " << b << endl;
                                    bWin = true;
                                }
                            }
                            a++;
                        }
                    }
                    b++;
                }
            }

            //diag right
            for (int i = 0; i < 13; i++) {
                for (int j = 0; j < 13; j++) {
                    int dxr = i, dyr = j;
                    int wc = 0;
                    //diag++
                    if (dxr + 5 <= 13 && dyr + 5 <= 13) {
                        for (int sdx = dxr, sdy = dyr; dxr < sdx + 5 && dyr < sdy + 5; dxr++, dyr++) {
                            if (*gCheck[dxr][dyr] == 2) {
                                wc += *gCheck[dxr][dyr];
                                if (wc == 10) {
                                    //qDebug() << "start X,Y: " << dxr << " ,  " << dyr << endl;
                                    //cout << "start X,Y: " << dxr << " ,  " << dyr << endl;
                                    wWin = true;
                                }
                            }
                        }
                    }
                }
            }
            //diag left
            for (int i = 12; i >= 0; i--) {
                for (int j = 0; j < 13; j++) {
                    int dxl = i, dyl = j;
                    int wc = 0;
                    if (dxl - 5 > -2 && dyl + 5 <= 13) {
                        for (int sdx = dxl, sdy = dyl; dxl >= sdx - 5 && dyl < sdy + 5; dxl--, dyl++) {
                            //white
                            if (*gCheck[dxl][dyl] == 2) {
                                wc += *gCheck[dxl][dyl];
                                if (wc == 10) {
                                    //qDebug() << "start X,Y: " << dxl << " ,  " << dyl << endl;
                                    //cout << "start X,Y: " << dxl << " ,  " << dyl << endl;
                                    wWin = true;
                                }
                            }
                        }
                    }
                }
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
