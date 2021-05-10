#ifndef CLIANT_WHITE_H
#define CLIANT_WHITE_H


#include <QTcpSocket>
#include <QHostAddress>
#include <QLineEdit>
#include <QPushButton>
#include <QtDebug>
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
#include "cliant_ready.h"
#include "ui_cliant_ready.h"


namespace Ui {
class cliant_white;
}

class cliant_white : public QWidget
{
    Q_OBJECT

public:
    explicit cliant_white(QWidget *parent = nullptr);
    ~cliant_white();

    void myconnect();

    void send(int x,int y);
    void myclose();
    void mousePressEvent(QMouseEvent *event);

    void paintEvent(QPaintEvent * event);
    void closeEvent(QCloseEvent *event);
    void showEvent(QShowEvent* event);

    void mydelete()
    {
            tcpSocket->abort();
    }



    QLineEdit *ip_inport;
    QLineEdit *port_inport;

    QPushButton *my_connect;

    int x,y,x1,y1;

    QPushButton *exit;

private:
    Ui::cliant_white *ui;
    QPainter *mypiece[22][22];
    int mypieces_color[22][22]={{0}}; //0-nothing;1-black;2-white
    win_tip *win;
    black_win_tip *black_win;
    white_win_tip *white_win;
    white44_win_tip *white44_win;
    white55_win_tip *white55_win;
    draw_tip *draw;
    int mystep=0;

    QTcpSocket * tcpSocket;
signals:
    void ExitWin();
};

#endif // CLIANT_WHITE_H
