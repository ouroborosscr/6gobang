#ifndef MYOPEN_H
#define MYOPEN_H

#include <QWidget>
#include <QtGui>
#include <QLabel>
#include <QPushButton>
#include <windows.h>
#include <QDebug>
#include <QPushButton>
#include <QPainter>
#include <QRect>
#include <QBrush>
#include <QFont>
#include "cliant_black.h"
#include "ui_cliant_black.h"



namespace Ui {
class myopen;
}

class myopen : public QWidget
{
    Q_OBJECT

public:
    explicit myopen(QWidget *parent = nullptr);
    ~myopen();
    void paintEvent(QPaintEvent * event);

//    void closeEvent(QCloseEvent *event);


    void pvp_nh()
    {type_judge=1;}

    void quittype()
    {type_judge=0;}

    void back1()
    {emit ExitWin1();}

    void back2()
    {emit ExitWin2();}

    void back3()
    {emit ExitWin3();}

    void back4()
    {emit ExitWin4();}

    void back5()
    {emit ExitWin5();}

    void back6()
    {emit ExitWin6();}

    void back7()
    {emit ExitWin7();}

    void back8()
    {emit ExitWin8();}

    void back9()
    {emit ExitWin9();}

    void back10()
    {emit ExitWin10();}

    void back11()
    {emit ExitWin11();}

    void back12()
    {emit ExitWin12();}
private:
    Ui::myopen *ui;
    QPushButton *pvpnh;
    QPushButton *myquit;
    QPushButton *pve_black;
    QPushButton *pve_white;
    QPushButton *eve;
    QPushButton *mycliant_white;
    QPushButton *myserver_black;
    QPushButton *test;
    QPushButton *myserver_white;
    QPushButton *mycliant_black;
    QPushButton *test2;
    QPushButton *server;
    QPushButton *test3;
    int type_judge=0; //1-pvp(no help)
signals:
    void ExitWin1();
    void ExitWin2();
    void ExitWin3();
    void ExitWin4();
    void ExitWin5();
    void ExitWin6();
    void ExitWin7();
    void ExitWin8();
    void ExitWin9();
    void ExitWin10();
    void ExitWin11();
    void ExitWin12();
};

#endif // MYOPEN_H
