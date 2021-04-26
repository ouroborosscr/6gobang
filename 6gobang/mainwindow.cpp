#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mybackground.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);





}

//背景图片以及画棋盘的线和点
void MainWindow::paintEvent(QPaintEvent *)
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
                mypieces_live[i][j]=1;

            }
            else if(mypieces_color[i][j]==2)
            {
                painter.setPen(QPen(Qt::white,4));
                painter.setBrush(QBrush(Qt::white,Qt::SolidPattern));
                painter.drawEllipse((i*20-5),(j*20-5),10,10);
               mypieces_live[i][j]=1;
            }
        }




}

//定位点击
//void MainWindow::mouseMoveEvent(QMouseEvent *event)
//{
//    x=event->x();
//    y=event->y();
//    qDebug()<<(x+10)/20<<"\n"<<(y+10)/20<<"\n";
//    x1=(x+10)/20;
//    y1=(y+10)/20;
//    if(event->button() == Qt::LeftButton)
//    {
//        if(x1>=1&&x1<=15&&y1>=1&&y1<=15&&mypieces[x1][y1].live==0)
//        {
//            mystep++;
//            if(mystep%2==1)
//            mypieces[x1][y1].color=1;
//            else
//            mypieces[x1][y1].color=2;

//            update();
//            qDebug()<<mystep;
//        }
//        else
//        {
//            x1=-100;
//            y1=-100;
//        }
//    }


//}//这个是移动定位，用来测试点的位置的，不用一直点击鼠标，按下拖动就行


//定位点击:
void MainWindow::mousePressEvent(QMouseEvent *event)
{
        myjudgement judge;
        warning44 warn44;
        warnin55 warn55;

    x=event->x();
    y=event->y();
    qDebug()<<(x+10)/20<<"\n"<<(y+10)/20<<"\n"; //测试方位
    x1=(x+10)/20;
    y1=(y+10)/20;
    if(event->button() == Qt::LeftButton)
    {
        if(x1>=1&&x1<=21&&y1>=1&&y1<=21&&mypieces_live[x1][y1]==0)
        {
            mystep++;
            if(mystep%2==1)
            mypieces_color[x1][y1]=1;
            else
            mypieces_color[x1][y1]=2;

            update();
            qDebug()<<mystep;


            if(help==0)//无帮助模式
            {
                if(mystep%2==1&&warn44.myjudge(x1,y1,mypieces_color)==1)//四四禁手
                {
                    white44_win=new white44_win_tip;
                    white44_win->show();

//                    my_open=new myopen;
                    connect(white44_win,SIGNAL(ExitWin()),this,SLOT(close()));
//                    connect(white44_win,SIGNAL(ExitWin()),my_open,SLOT(show()));
                }

                if(mystep%2==1&&warn55.myjudge(x1,y1,mypieces_color)==1)//五五禁手
                {
                    white55_win=new white55_win_tip;
                    white55_win->show();

//                    my_open=new myopen;
                    connect(white55_win,SIGNAL(ExitWin()),this,SLOT(close()));
//                    connect(white55_win,SIGNAL(ExitWin()),my_open,SLOT(show()));
                }
            }


            if(judge.myjudge(mypieces_color[x1][y1],x1,y1,mypieces_color)==1)
            {
                qDebug()<<"win";
                if(mystep%2==1)
                {
                    black_win=new black_win_tip;
                    black_win->show();

//                    my_open=new myopen;
//                    my_open->setFixedSize(600,450);
//                    my_open->setWindowTitle("六子棋");
                    connect(black_win,SIGNAL(ExitWin()),this,SLOT(close()));

//                    //接收到pvp-no help
//                    connect(my_open,SIGNAL(ExitWin1()),this,SLOT(clean()));
//                    connect(my_open,SIGNAL(ExitWin1()),this,SLOT(no_help()));
//                    connect(my_open,SIGNAL(ExitWin1()),this,SLOT(pvp()));
//                    connect(my_open,SIGNAL(ExitWin1()),this,SLOT(show()));
                }
                else
                {
                    white_win=new white_win_tip;
                    white_win->show();

//                    my_open=new myopen;
                    connect(white_win,SIGNAL(ExitWin()),this,SLOT(close()));
//                    connect(white_win,SIGNAL(ExitWin()),my_open,SLOT(show()));
                }


//                win=new win_tip;
//                win->show();


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
        else
        {
            x1=-100;
            y1=-100;
        }
    }




}

void MainWindow::showEvent(QShowEvent* )
{
    for(int i=1;i<=21;i++)
        for(int j=1;j<=21;j++)
        {
            mypieces_color[i][j]=0;
            mypieces_live[i][j]=0;
        }
    mystep=0;
    update();
}

void MainWindow::closeEvent(QCloseEvent *)
{
    emit ExitWin();
}

MainWindow::~MainWindow()
{
    delete ui;
//    delete win;
//    delete black_win;
//    delete white_win;
}

