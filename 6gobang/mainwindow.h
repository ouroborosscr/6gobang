#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "myjudgement.h"
#include <QPushButton>
#include "win_tip.h"
#include "ui_win_tip.h"
#include "black_win_tip.h"
#include "ui_black_win_tip.h"
#include "white_win_tip.h"
#include "ui_white_win_tip.h"
#include "warning44.h"
#include "warnin55.h"
#include "myopen.h"
#include "ui_myopen.h"
#include "draw_tip.h"
#include "ui_draw_tip.h"
#include "white44_win_tip.h"
#include "ui_white44_win_tip.h"
#include "white55_win_tip.h"
#include "ui_white55_win_tip.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent * event);
//    void mouseMoveEvent(QMouseEvent *event);//这个是移动定位，用来测试点的位置的，不用一直点击鼠标，按下拖动就行
    void mousePressEvent(QMouseEvent *event);
    void closeEvent(QCloseEvent *event);

    void showEvent(QShowEvent* event);


//    void no_help()
//    {help=0;}
//    void pvp()
//    {petype=0;}


    void clean();



private:
    Ui::MainWindow *ui;
    QPainter *mypiece[22][22];
    int x,y,x1,y1;
    int mypieces_color[22][22]={{0}}; //0-nothing;1-black;2-white
    int mypieces_live[22][22]={{0}}; //live-0;unlive-1


        win_tip *win;
        black_win_tip *black_win;
        white_win_tip *white_win;
        white44_win_tip *white44_win;
        white55_win_tip *white55_win;
        draw_tip *draw;


        int help=0;//是否提示四四禁手，五五禁手（是-1，否-0）
        int petype=0;//0-pvp,1-p(black)ve,2-p(white)ve,3-pvp

    int mystep=0;
signals:
    void ExitWin();
};
#endif // MAINWINDOW_H
