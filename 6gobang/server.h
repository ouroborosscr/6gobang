#ifndef SERVER_H
#define SERVER_H

#include <QLineEdit>
#include <QTcpServer>
#include <QTcpSocket>
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
#include "server_ready.h"
#include "ui_server_ready.h"
#include "myport_ready.h"
#include "ui_myport_ready.h"

//未成功，应该是单线程下connect一个端口，另一个端口会断开，无法做到同时监听两个端口

namespace Ui {
class server;
}

class server : public QWidget
{
    Q_OBJECT

public:
    explicit server(QWidget *parent = nullptr);
    ~server();

    void receive1();
    void receive2();
    void send1(int x,int y);
    void send2(int x,int y);
    void close1();
    void close2();

    void paintEvent(QPaintEvent * event);
    void closeEvent(QCloseEvent *event);
    void showEvent(QShowEvent* event);

    void changemonitor1()
    {
        qint16 myport1=port_inport1->text().toInt();
        tcpServer1->listen(QHostAddress::Any,myport1);
        myportready = new myport_ready;
        myportready->show();
    }

    void changemonitor2()
    {
        qint16 myport2=port_inport2->text().toInt();
        tcpServer2->listen(QHostAddress::Any,myport2);
        myportready = new myport_ready;
        myportready->show();
    }

    qint16 myport1=8000;
    qint16 myport2=8888;

    QLineEdit *port_inport1;
    QLineEdit *port_inport2;

    myport_ready *myportready;

    QPushButton *my_monitor;

    int x,y,x1,y1;

private:
    Ui::server *ui;

    QPainter *mypiece[22][22];
    int mypieces_color[22][22]={{0}}; //0-nothing;1-black;2-white
    win_tip *win;
    black_win_tip *black_win;
    white_win_tip *white_win;
    white44_win_tip *white44_win;
    white55_win_tip *white55_win;
    draw_tip *draw;
    int mystep=0;

    QTcpServer *tcpServer1;
    QTcpServer *tcpServer2;
    QTcpSocket *tcpSocket1;
    QTcpSocket *tcpSocket2;

signals:
    void ExitWin();
};

#endif // SERVER_H
