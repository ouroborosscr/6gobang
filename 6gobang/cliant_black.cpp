#include "cliant_black.h"
#include "ui_cliant_black.h"

cliant_black::cliant_black(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cliant_black)
{
    ui->setupUi(this);


    tcpSocket=NULL;

    tcpSocket = new QTcpSocket(this);

    connect(tcpSocket,&QTcpSocket::connected,
            [=]()
            {
                //弹一个弹窗，成功建立连接（未完成）
                qDebug()<<"客户端：连接建立";
                mystep++;

                cliant_ready *cliantready=new cliant_ready;
                cliantready->show();
            }
            );

    connect(tcpSocket, &QTcpSocket::readyRead,
            [=]()
            {
                myjudgement judge;
                warning44 warn44;
                warnin55 warn55;
                //取出内容
                QByteArray array=tcpSocket->readAll();
                char *strback= array.data();
                int xback,yback;
                xback=*strback;
                yback=*(strback+1);
                mypieces_color[xback][yback]=2;
                update();
                mystep++;//测试用，让棋子下下去




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
            }
    );

    //设计一个connect按钮，转到myconnect
    my_connect= new QPushButton("connect",this);
    my_connect->resize(40,20);
    my_connect->move(500,150);

    connect(my_connect,&QPushButton::clicked,this,&cliant_black::myconnect);




    //设计两个文本输入框
    ip_inport=new QLineEdit("127.0.0.1",this);
    port_inport=new QLineEdit("8000",this);

    ip_inport->move(500,50);
    ip_inport->setMaximumWidth(75);

    port_inport->move(500,100);
    port_inport->setMaximumWidth(75);
}

//背景图片以及画棋盘的线和点
void cliant_black::paintEvent(QPaintEvent *)
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

void cliant_black::showEvent(QShowEvent* )
{
    for(int i=1;i<=21;i++)
        for(int j=1;j<=21;j++)
        {
            mypieces_color[i][j]=0;
        }
    mystep=-1;
    update();
}

void cliant_black::closeEvent(QCloseEvent *)
{
    myclose();
    emit ExitWin();
}

//写一个鼠标事件，判定，发送数据
void cliant_black::mousePressEvent(QMouseEvent *event)
{
    myjudgement judge;
    warning44 warn44;
    warnin55 warn55;
    int x,y,x1,y1;
    x=event->x();
    y=event->y();
    x1=(x+10)/20;
    y1=(y+10)/20;
//    qDebug()<<x1<<" "<<y1;

  //写一个条件，step为2的倍数+1，点为空，点击点在棋盘内
    if(event->button() == Qt::LeftButton)
    {
        if(mystep%2==0&&x1>=1&&x1<=21&&y1>=1&&y1<=21&&mypieces_color[x1][y1]==0)
        {
            send(x1,y1);
            mystep++;
            mypieces_color[x1][y1]=1;
            update();

            if(judge.myjudge(mypieces_color[x1][y1],x1,y1,mypieces_color)==1)
            {
                black_win=new black_win_tip;
                black_win->show();
            }

            if(warn44.myjudge(x1,y1,mypieces_color)==1)//四四禁手
            {
                white44_win=new white44_win_tip;
                white44_win->show();

//                    my_open=new myopen;

//                    connect(white44_win,SIGNAL(ExitWin()),my_open,SLOT(show()));
            }

            if(warn55.myjudge(x1,y1,mypieces_color)==1)//五五禁手
            {
                white55_win=new white55_win_tip;
                white55_win->show();

//                    my_open=new myopen;

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


        }
    }





}


void cliant_black::myconnect()
{
    //获取服务器ip，端口
    //在上面的ui界面做两个输入框，然后做一个按钮
        QString ip=ip_inport->text();//接收输入框ip
        qint16 port=port_inport->text().toInt();//接收输入框端口

    //主动建立连接
    tcpSocket->connectToHost(QHostAddress(ip),port);
}

void cliant_black::send(int x,int y)
{
    if(NULL==tcpSocket)
    {
        return;
    }
    char str[2];
    str[0]=x;
    str[1]=y;
    //发送数据
    //做一个条件函数，只有某种情况的时候，写入
    tcpSocket->write(str);
}

void cliant_black::myclose()
{
    if(NULL==tcpSocket)
    {
        return;
    }
    //主动断开连接
    tcpSocket->disconnectFromHost();
    tcpSocket->close();

    qDebug()<<"客户端：断开连接";

    //弹一个断开连接对话框（未完成）
}

cliant_black::~cliant_black()
{
    delete ui;
}
