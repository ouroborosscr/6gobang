#include "server.h"
#include "ui_server.h"

server::server(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::server)
{
    ui->setupUi(this);

    tcpServer1 = NULL;
    tcpServer2 = NULL;
    tcpSocket1 = NULL;
    tcpSocket2 = NULL;

    //文本框，输入监听的端口
    port_inport1=new QLineEdit("8000",this);
    port_inport1->move(500,50);
    port_inport1->setMaximumWidth(75);

    port_inport2=new QLineEdit("8888",this);
    port_inport2->move(500,100);
    port_inport2->setMaximumWidth(75);

    my_monitor= new QPushButton("monitor",this);
    my_monitor->resize(40,20);
    my_monitor->move(500,150);
    connect(my_monitor,&QPushButton::clicked,this,&server::changemonitor1);
    connect(my_monitor,&QPushButton::clicked,this,&server::changemonitor2);

    //监听1
    tcpServer1 =new QTcpServer(this);
    tcpServer1->listen(QHostAddress::Any,myport1);

    connect(tcpServer1,&QTcpServer::newConnection,
            [=]()
            {

                //取出建立好链接的套接字
                tcpSocket1 =tcpServer1->nextPendingConnection();

                //获取对方的ip和端口
                QString ip= tcpSocket1->peerAddress().toString();
                qint16 port =tcpSocket1->peerPort();

                //发送连接成功(做一个新窗口）构造时加ip和port（未完成）
                qDebug()<<"服务端：连接成功"<<ip<<" "<<port;

                server_ready *serverready=new server_ready;
                serverready->show();


                connect(tcpSocket1,&QTcpSocket::readyRead,
                        [=]()
                        {
                            myjudgement judge;
                            warning44 warn44;
                            warnin55 warn55;
                            //取出内容
                            QByteArray array=tcpSocket1->readAll();
                            char *strback= array.data();
                            int xback,yback;
                            xback=*strback;
                            yback=*(strback+1);
                            mypieces_color[xback][yback]=1;
                            update();
                            mystep++;//测试用，让棋子下下去

                            send2(xback,yback);

                            if(judge.myjudge(mypieces_color[xback][yback],xback,yback,mypieces_color)==1)
                            {
                                qDebug()<<"win";
                                if(mystep%2==1)
                                {
                                    black_win=new black_win_tip;
                                    black_win->show();
                                }
                             }

                            if(warn44.myjudge(xback,yback,mypieces_color)==1)//四四禁手
                            {
                                white44_win=new white44_win_tip;
                                white44_win->show();

                //                    my_open=new myopen;
                //                    connect(white44_win,SIGNAL(ExitWin()),my_open,SLOT(show()));
                            }

                            if(warn55.myjudge(xback,yback,mypieces_color)==1)//五五禁手
                            {
                                white55_win=new white55_win_tip;
                                white55_win->show();

                //                    my_open=new myopen;
                //                connect(white55_win,SIGNAL(ExitWin()),this,SLOT(close()));
                //                    connect(white55_win,SIGNAL(ExitWin()),my_open,SLOT(show()));
                            }

                            if(mystep==441)
                            {
                                //平局
                                draw=new draw_tip;
                                draw->show();

                //                my_open=new myopen;
                                connect(draw,SIGNAL(ExitWin()),this,SLOT(close()));
                //                connect(draw,SIGNAL(ExitWin()),my_open,SLOT(show()));
                            }


                            qDebug()<<xback<<" "<<yback;

                        }
                        );



            }

            );


    //监听2
    tcpServer2 =new QTcpServer(this);
    tcpServer2->listen(QHostAddress::Any,myport2);

    connect(tcpServer2,&QTcpServer::newConnection,
            [=]()
            {

                //取出建立好链接的套接字
                tcpSocket2 =tcpServer2->nextPendingConnection();

                //获取对方的ip和端口
                QString ip= tcpSocket2->peerAddress().toString();
                qint16 port =tcpSocket2->peerPort();

                //发送连接成功(做一个新窗口）构造时加ip和port（未完成）
                qDebug()<<"服务端：连接成功"<<ip<<" "<<port;

                server_ready *serverready=new server_ready;
                serverready->show();


                connect(tcpSocket2,&QTcpSocket::readyRead,
                        [=]()
                        {
                            myjudgement judge;
                            //取出内容
                            QByteArray array=tcpSocket2->readAll();
                            char *strback= array.data();
                            int xback,yback;
                            xback=*strback;
                            yback=*(strback+1);
                            mypieces_color[xback][yback]=2;
                            update();
                            mystep++;//测试用，让棋子下下去

                            send1(xback,yback);

                            if(judge.myjudge(mypieces_color[xback][yback],xback,yback,mypieces_color)==1)
                            {
                                qDebug()<<"win";
                                if(mystep%2==0)
                                {
                                    white_win=new white_win_tip;
                                    white_win->show();
                                }
                             }

                            if(mystep==441)
                            {
                                //平局
                                draw=new draw_tip;
                                draw->show();

                //                my_open=new myopen;
                                connect(draw,SIGNAL(ExitWin()),this,SLOT(close()));
                //                connect(draw,SIGNAL(ExitWin()),my_open,SLOT(show()));
                            }


                            qDebug()<<xback<<" "<<yback;

                        }
                        );



            }

            );

}
void server::showEvent(QShowEvent* )
{
    for(int i=1;i<=21;i++)
        for(int j=1;j<=21;j++)
        {
            mypieces_color[i][j]=0;
        }
    mystep=0;//连接上的时候归零，防止未连接时一方下棋
    update();
}

void server::closeEvent(QCloseEvent *)
{
    close1();
    close2();
    emit ExitWin();
}

//背景图片以及画棋盘的线和点
void server::paintEvent(QPaintEvent *)
{
    QPainter painter( this);


    //背景图片：
    painter.drawPixmap(0,0,600,450,QPixmap(":new/prefix1/1616672385673.png"));

//    Q_UNUSED(event);

    //边框：
    // 反走样
    painter.setRenderHint(QPainter::Antialiasing, true);
    // 设置画笔颜色、宽度
    painter.setPen(QPen(Qt::black, 2));
    // 设置画刷颜色
//    painter.setBrush(QColor(255, 160, 90));
    painter.drawRect(20, 20, 400, 400);

    //线：
    painter.setPen(QPen(Qt::black, 1));

    for(float i=40;i<=400;i+=20)
    {
        painter.drawLine(QPointF(20, i),QPointF(420,i ));
    }

    for(float i=40;i<=400;i+=20)
    {
        painter.drawLine(QPointF(i, 20),QPointF(i,420));
    }

    //点：
    painter.setPen(QPen(Qt::black, 4));
    painter.setBrush(Qt::black);
    painter.drawEllipse(QPointF(120, 120),1,1);
    painter.drawEllipse(QPointF(120, 300),1,1);
    painter.drawEllipse(QPointF(300, 120),1,1);
    painter.drawEllipse(QPointF(300, 300),1,1);
//    painter.drawEllipse(QPointF(160, 160),1,1);

    //棋子：
    for(int i=0;i<=21;i++)
           for(int j=0;j<=21;j++)
        {
            if(mypieces_color[i][j]==1)
            {
                painter.setPen(QPen(Qt::black,4));
                 painter.setBrush(QBrush(Qt::black,Qt::SolidPattern));
                 painter.drawEllipse((i*20-5),(j*20-5),10,10);

            }
            else if(mypieces_color[i][j]==2)
            {
                painter.setPen(QPen(Qt::white,4));
                painter.setBrush(QBrush(Qt::white,Qt::SolidPattern));
                painter.drawEllipse((i*20-5),(j*20-5),10,10);
            }
        }




}

void server::send1(int x,int y)
{
    if(NULL==tcpSocket1)
    {
        return;
    }
    char str[2];
//    qDebug()<<x<<" "<<y;
    str[0]=x;
    str[1]=y;
    //发送数据
    tcpSocket1->write(str);
}

void server::send2(int x,int y)
{
    if(NULL==tcpSocket2)
    {
        return;
    }
    char str[2];
//    qDebug()<<x<<" "<<y;
    str[0]=x;
    str[1]=y;
    //发送数据
    tcpSocket2->write(str);
}

void server::close1()
{
    if(NULL==tcpSocket1)
    {
        return;
    }
    //主动断开连接
    tcpSocket1->disconnectFromHost();
    tcpSocket1->close();

    //弹一个断开连接对话框（未完成）
    qDebug()<<"服务端：断开连接";
}

void server::close2()
{
    if(NULL==tcpSocket2)
    {
        return;
    }
    //主动断开连接
    tcpSocket2->disconnectFromHost();
    tcpSocket2->close();

    //弹一个断开连接对话框（未完成）
    qDebug()<<"服务端：断开连接";
}


server::~server()
{
    delete ui;
}
