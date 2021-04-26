#include "mainwindow.h"
#include "myopen.h"
#include "ui_myopen.h"
#include "white_ai.h"
#include "ui_white_ai.h"
#include "black_ai.h"
#include "ui_black_ai.h"
#include "eve_ai.h"
#include "eve_ai.h"
#include "cliant_white.h"
#include "ui_cliant_white.h"
#include "server_black.h"
#include "ui_server_black.h"
#include "server_white.h"
#include "ui_server_white.h"
#include "cliant_black.h"
#include "ui_cliant_black.h"
#include "server.h"
#include "ui_server.h"

#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    myopen *my_open;
    MainWindow *w;
    white_ai *x;
    black_ai *y;
    eve_ai *z;
    cliant_white *o;
    server_black *p;
    server_white *q;
    cliant_black *r;
//    server *s;//设计了一个监视器，用于连接两个客户端，但是失效了

    w=new MainWindow;
    w->setFixedSize(600,450);
    w->setWindowTitle("六子棋PvP（无帮助）");

    x=new white_ai;
    x->setFixedSize(600,450);
    x->setWindowTitle("六子棋PvE（先手）");

    y=new black_ai;
    y->setFixedSize(600,450);
    y->setWindowTitle("六子棋PvE（后手）");

    z=new eve_ai;
    z->setFixedSize(600,450);
    z->setWindowTitle("六子棋EvE");

    o=new cliant_white;
    o->setFixedSize(600,450);
    o->setWindowTitle("六子棋联机(白)（客户端）");

    p=new server_black;
    p->setFixedSize(600,450);
    p->setWindowTitle("六子棋联机(黑)（服务端）");

    q=new server_white;
    q->setFixedSize(600,450);
    q->setWindowTitle("六子棋联机(白)（服务端）");

    r=new cliant_black;
    r->setFixedSize(600,450);
    r->setWindowTitle("六子棋联机(黑)（客户端）");

//    s=new server;
//    s->setFixedSize(600,450);
//    s->setWindowTitle("六子棋联机（服务端）（监视器）");

    my_open=new myopen;
    my_open->setFixedSize(600,450);
    my_open->setWindowTitle("六子棋");
    my_open->show();
    //接收到pvp-no help
    QObject::connect(my_open,SIGNAL(ExitWin1()),w,SLOT(show()));
    QObject::connect(my_open,SIGNAL(ExitWin2()),x,SLOT(show()));
    QObject::connect(my_open,SIGNAL(ExitWin3()),y,SLOT(show()));
    QObject::connect(my_open,SIGNAL(ExitWin4()),z,SLOT(show()));
    QObject::connect(my_open,SIGNAL(ExitWin5()),o,SLOT(show()));
    QObject::connect(my_open,SIGNAL(ExitWin6()),p,SLOT(show()));
    QObject::connect(my_open,SIGNAL(ExitWin8()),q,SLOT(show()));
    QObject::connect(my_open,SIGNAL(ExitWin9()),r,SLOT(show()));
//    QObject::connect(my_open,SIGNAL(ExitWin11()),s,SLOT(show()));

    QObject::connect(my_open,SIGNAL(ExitWin7()),o,SLOT(show()));
    QObject::connect(my_open,SIGNAL(ExitWin7()),p,SLOT(show()));//测试1

    QObject::connect(my_open,SIGNAL(ExitWin10()),q,SLOT(show()));
    QObject::connect(my_open,SIGNAL(ExitWin10()),r,SLOT(show()));//测试2

//    QObject::connect(my_open,SIGNAL(ExitWin12()),o,SLOT(show()));
//    QObject::connect(my_open,SIGNAL(ExitWin12()),r,SLOT(show()));
//    QObject::connect(my_open,SIGNAL(ExitWin12()),s,SLOT(show()));//测试3



    QObject::connect(w,SIGNAL(ExitWin()),my_open,SLOT(show()));
    QObject::connect(x,SIGNAL(ExitWin()),my_open,SLOT(show()));
    QObject::connect(y,SIGNAL(ExitWin()),my_open,SLOT(show()));
    QObject::connect(z,SIGNAL(ExitWin()),my_open,SLOT(show()));
    QObject::connect(o,SIGNAL(ExitWin()),my_open,SLOT(show()));
    QObject::connect(p,SIGNAL(ExitWin()),my_open,SLOT(show()));
    QObject::connect(q,SIGNAL(ExitWin()),my_open,SLOT(show()));
    QObject::connect(r,SIGNAL(ExitWin()),my_open,SLOT(show()));



//    MainWindow w;
//    w.setFixedSize(600,450);
//    w.setWindowTitle("六子棋");
//    w.show();

//    //棋盘背景——木制:
//    mybackground *frame =  new mybackground;
//    frame->setFixedSize(400,400); //固定窗口大小，改变参数时要连同mybackground的参数一起改

//    frame->show();

//    //程序框标题:
//    frame->setWindowTitle("六子棋");

//    frame->show();

//    //划线：


    return a.exec();
}

