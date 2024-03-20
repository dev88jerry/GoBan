/*
Auteur: Jerry Lau
Travail : TP GoBan
Nom du ficher: newp.h
Date: 05 May 2020
But: Definition de la classe NewP
*/

#ifndef NEWP_H
#define NEWP_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QAction>
#include <QLineEdit>

class NewP : public QWidget
{
    Q_OBJECT
public:
    NewP();
    ~NewP();

public slots:
    void slotFermer(void);
    void echoNom1(void);
    void echoNom2(void);
    void slotDebut(void);

protected:
    QGridLayout *m_layoutNewP;
    QLabel *m_labelNewP;
    QPushButton *m_start;
    QPushButton *m_quit;
    QLineEdit *m_nom1;
    QLineEdit *m_nom2;
};

#endif // NEWP_H
