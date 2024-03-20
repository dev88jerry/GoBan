/*
Auteur: Jerry Lau
Travail : TP GoBan
Nom du ficher: gagnant.h
Date: 05 May 2020
But: Definition de la classe Gagnant
*/

#ifndef GAGNANT_H
#define GAGNANT_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QObject>
#include <QAction>

class Gagnant : public QWidget
{
    Q_OBJECT
public:
    Gagnant();
    ~Gagnant();

public slots:
    void slotFermer(void);

protected:
    QVBoxLayout *m_layoutG;
    QLabel *m_labelG;
    QLabel *m_labelP;
    QPushButton *m_fermer;
};

#endif // GAGNANT_H
