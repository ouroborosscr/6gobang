#ifndef WHITE_AI_H
#define WHITE_AI_H

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
#include <stdlib.h>
#include <windows.h>

namespace Ui {
class white_ai;
}

class white_ai : public QWidget
{
    Q_OBJECT

public:
    explicit white_ai(QWidget *parent = nullptr);
    ~white_ai();
    void paintEvent(QPaintEvent * event);
    void mousePressEvent(QMouseEvent *event);
    void closeEvent(QCloseEvent *event);
    void showEvent(QShowEvent* event);

    void text();


    void ai_judge();
    int white_6(int x, int y);//25748   (a)
    int black_5(int x, int y);//6436    (a/4-1)
    int white_live_5(int x, int y);//1608   (a/4-1)/4-1
    int black_live_4(int x, int y);//803    ((a/4-1)/4-1)/2-1    白子不下黑子下就是活五，只能有一个，但是要防止四五比上面那种高，所以除二
    int white_rush_5(int x, int y);//802   ((a/4-1)/4-1)/2-2    两个冲五比堵对方的活四占优势
    int black_rush_4(int x, int y);//400   (((a/4-1)/4-1)/2-2)/2-1黑子下是冲五，只能有一个，但是要防止四五比上面那种高，所以除二
    int white_live_4(int x, int y);//99   ((((a/4-1)/4-1)/2-2)/2-1)/4-1
    int black_live_3(int x, int y);//98   ((((a/4-1)/4-1)/2-2)/2-1)/4-2
    int white_rush_4(int x, int y);//97   ((((a/4-1)/4-1)/2-2)/2-1)/4-3
    int black_rush_3(int x, int y);//96   ((((a/4-1)/4-1)/2-2)/2-1)/4-4
    int white_live_3(int x, int y);//23   (((((a/4-1)/4-1)/2-2)/2-1)/4-4)/4-1
    int black_live_2(int x, int y);//22   (((((a/4-1)/4-1)/2-2)/2-1)/4-4)/4-2
    int white_rush_3(int x, int y);//21   (((((a/4-1)/4-1)/2-2)/2-1)/4-4)/4-3
//    int black_rush_2(int x, int y);//20   (((((a/4-1)/4-1)/2-2)/2-1)/4-4)/4-4
    int white_live_2(int x, int y);//4   ((((((a/4-1)/4-1)/2-2)/2-1)/4-4)/4-4)/4-1
    int black_live_1(int x, int y);//3   ((((((a/4-1)/4-1)/2-2)/2-1)/4-4)/4-4)/4-2
    int white_rush_2(int x, int y);//2   ((((((a/4-1)/4-1)/2-2)/2-1)/4-4)/4-4)/4-3
//    int black_rush_1(int x, int y);//1   ((((((a/4-1)/4-1)/2-2)/2-1)/4-4)/4-4)/4-4
    //规则：白棋进攻：下完这步棋后造成的影响；白棋防守：这个位置能防哪些种类
private:
    Ui::white_ai *ui;
    QPainter *mypiece[22][22];
    int mypieces_color[22][22]={{0}};
    int mypieces_empty[22][22]={{0}};
    int mypieces_score[22][22]={{0}};
    int x,y,x1,y1;
    black_win_tip *black_win;
    white_win_tip *white_win;
    white44_win_tip *white44_win;
    white55_win_tip *white55_win;
    draw_tip *draw;

    int help=0;//是否提示四四禁手，五五禁手（是-1，否-0）
    int petype=0;//0-pvp,1-p(black)ve,2-p(white)ve,3-pvp
    int mystep=0;
    int max;
    int p,q;
signals:
    void ExitWin();
};

#endif // WHITE_AI_H
