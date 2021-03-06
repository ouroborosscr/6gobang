#ifndef SERVER_BLACK_H
#define SERVER_BLACK_H

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


namespace Ui {
class server_black;
}

class server_black : public QWidget
{
    Q_OBJECT

public:
    explicit server_black(QWidget *parent = nullptr);
    ~server_black();

    void receive();
    void send(int x,int y);
    void myclose();
    void mousePressEvent(QMouseEvent *event);


    void paintEvent(QPaintEvent * event);
    void closeEvent(QCloseEvent *event);
    void showEvent(QShowEvent* event);

    void changemonitor()
    {
        qint16 myport=port_inport->text().toInt();
        tcpServer->listen(QHostAddress::Any,myport);
        myportready = new myport_ready;
        myportready->show();
    }

    qint16 myport=8888;

    QLineEdit *port_inport;

    myport_ready *myportready;

    QPushButton *my_monitor;

    int x,y,x1,y1;

    QPushButton *exit;


private:
    Ui::server_black *ui;

    QPainter *mypiece[22][22];
    int mypieces_color[22][22]={{0}}; //0-nothing;1-black;2-white
    win_tip *win;
    black_win_tip *black_win;
    white_win_tip *white_win;
    white44_win_tip *white44_win;
    white55_win_tip *white55_win;
    draw_tip *draw;
    int mystep=0;

    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
signals:
    void ExitWin();
};

#endif // SERVER_BLACK_H
