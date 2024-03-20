/*
Auteur: Jerry Lau
Travail : TP GoBan
Nom du ficher: apropos.h
Date: 05 May 2020
But: Definition de la classe APropos
*/

#ifndef APROPOS_H
#define APROPOS_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QObject>
#include <QAction>

class APropos : public QWidget
{
    Q_OBJECT
public:
    APropos();
    ~APropos();

public slots:
    void slotFermer(void);

protected:
    QVBoxLayout *m_layoutAP;
    QLabel *m_labelLogo;
    QLabel *m_labelVersion;
    QLabel *m_labelConcepteur;
    QPushButton *m_fermer;
};

#endif // APROPOS_H
