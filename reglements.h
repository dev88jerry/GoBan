/*
Auteur: Jerry Lau
Travail : TP GoBan
Nom du ficher: reglements.h
Date: 05 May 2020
But: Definition de la classe Reglements
*/

#ifndef REGLEMENTS_H
#define REGLEMENTS_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QAction>
#include <QObject>

class Reglements : public QWidget
{
    Q_OBJECT
public:
    Reglements();
    ~Reglements();

public slots:
    void slotFermer(void);

protected:
    QVBoxLayout *m_layoutR;
    QLabel *m_labelRegle;
    QLabel *m_labelR;
    QPushButton *m_fermer;

};

#endif // REGLEMENTS_H
