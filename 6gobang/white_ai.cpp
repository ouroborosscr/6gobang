#include "white_ai.h"
#include "ui_white_ai.h"
#include <QDebug>

white_ai::white_ai(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::white_ai)
{
    ui->setupUi(this);

    exit= new QPushButton("返回主菜单",this);
    exit->resize(80,40);
    exit->move(450,300);

    my_clean= new QPushButton("重新开始",this);
    my_clean->resize(80,40);
    my_clean->move(450,200);
}

void white_ai::paintEvent(QPaintEvent *)
{
    QPainter painter( this);

    connect(exit,&QPushButton::clicked,this,&white_ai::close);
    connect(my_clean,&QPushButton::clicked,this,&white_ai::clean);


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


void white_ai::mousePressEvent(QMouseEvent *event)
{
    myjudgement judge;
    warning44 warn44;
    warnin55 warn55;

    x=event->x();
    y=event->y();
    x1=(x+10)/20;
    y1=(y+10)/20;

    if(event->button() == Qt::LeftButton)
    {
            if(x1>=1&&x1<=21&&y1>=1&&y1<=21&&mypieces_color[x1][y1]==0)
            {
                mystep++;
                mypieces_color[x1][y1]=1;
//                update();
                //判定
                if(warn44.myjudge(x1,y1,mypieces_color)==1)//四四禁手
                {
                    white44_win=new white44_win_tip;
                    white44_win->show();
                    connect(white44_win,SIGNAL(ExitWin()),this,SLOT(close()));

                }
                if(warn55.myjudge(x1,y1,mypieces_color)==1)//五五禁手
                {
                    white55_win=new white55_win_tip;
                    white55_win->show();
                    connect(white55_win,SIGNAL(ExitWin()),this,SLOT(close()));
                }
                if(judge.myjudge(mypieces_color[x1][y1],x1,y1,mypieces_color)==1)
                {
                        black_win=new black_win_tip;
                        black_win->show();


                        connect(black_win,SIGNAL(ExitWin()),this,SLOT(close()));


                }


//                Sleep(1000);
                //白棋下子
                ai_judge();
                update();
                //if(mystep%2==1)
                //{
//                    ai_judge();
//                    qDebug()<<x1<<" "<<y1<<"\n";
//                    update();
                //}

                text();//测试

                //判定
                if(judge.myjudge(mypieces_color[x1][y1],x1,y1,mypieces_color)==1)
                {
                    white_win=new white_win_tip;
                    white_win->show();
                    connect(white_win,SIGNAL(ExitWin()),this,SLOT(close()));

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

void white_ai::text()
{
    for(int i=1;i<=21;i++)
    {
        for(int j=1;j<=21;j++)
        {
 //           if(mypieces_color[i][j]!=0)
 //          qDebug()<<mypieces_color[i][j]<<" ";
        }

    }
}

void white_ai::showEvent(QShowEvent* )
{
    for(int i=1;i<=21;i++)
        for(int j=1;j<=21;j++)
        {
            mypieces_color[i][j]=0;
        }
    mystep=0;
    update();
}

void white_ai::closeEvent(QCloseEvent *)
{
    emit ExitWin();
}

void white_ai::ai_judge()
{
    max=0;
    p=0;
    q=0;
    for(int i=1;i<=21;i++)
        for(int j=1;j<=21;j++)
        {
            if(mypieces_color[i][j]==0)
            {
                if(mypieces_color[i+1][j-1]!=0||
                   mypieces_color[i+1][j]!=0||
                   mypieces_color[i+1][j+1]!=0||
                   mypieces_color[i][j-1]!=0||
                   mypieces_color[i][j+1]!=0||
                   mypieces_color[i-1][j-1]!=0||
                   mypieces_color[i-1][j]!=0||
                   mypieces_color[i-1][j+1]!=0)
                {
                    mypieces_empty[i][j]=1;
                    mypieces_score[i][j]=0;
                }

                else
                    mypieces_empty[i][j]=0;
            }
            else
                mypieces_empty[i][j]=0;
        }
    for(int i=1;i<=21;i++)
        for(int j=1;j<=21;j++)
        {
            if(mypieces_empty[i][j]==1)
            {
                if(white_6(i,j)==25748)
                {
                    mypieces_color[i][j]=2;
                    x1=i;
                    y1=j;
                    mystep++;
                    return ;
                    //直接下那一步，跳转回去
                }
                else
                {
                    qDebug()<<i<<" "<<j;
                    qDebug()<<mypieces_score[i][j];

                    mypieces_score[i][j]+=black_5(i,j);
                    qDebug()<<mypieces_score[i][j];

                    mypieces_score[i][j]+=white_live_5(i,j);
                    qDebug()<<mypieces_score[i][j];

                    mypieces_score[i][j]+=black_live_4(i,j);
                    qDebug()<<mypieces_score[i][j];

                    mypieces_score[i][j]+=white_rush_5(i,j);
                    qDebug()<<mypieces_score[i][j];

                    mypieces_score[i][j]+=black_rush_4(i,j);
                    qDebug()<<mypieces_score[i][j];

                    mypieces_score[i][j]+=white_live_4(i,j);
                    qDebug()<<mypieces_score[i][j];

                    mypieces_score[i][j]+=black_live_3(i,j);
                    qDebug()<<mypieces_score[i][j];

                    mypieces_score[i][j]+=white_rush_4(i,j);
                    qDebug()<<mypieces_score[i][j];

                    mypieces_score[i][j]+=black_rush_3(i,j);
                    qDebug()<<mypieces_score[i][j];

                    mypieces_score[i][j]+=white_live_3(i,j);
                    qDebug()<<mypieces_score[i][j];

                    mypieces_score[i][j]+=black_live_2(i,j);
                    qDebug()<<mypieces_score[i][j];

                    mypieces_score[i][j]+=white_rush_3(i,j);
                    qDebug()<<mypieces_score[i][j];

//                    mypieces_score[i][j]+=black_rush_2(i,j);
                    mypieces_score[i][j]+=white_live_2(i,j);
                    qDebug()<<mypieces_score[i][j];

                    mypieces_score[i][j]+=black_live_1(i,j);
                    qDebug()<<mypieces_score[i][j];

                    mypieces_score[i][j]+=white_rush_2(i,j);
                    qDebug()<<mypieces_score[i][j];

//                    mypieces_score[i][j]+=black_rush_1(i,j);
                    if(mypieces_score[i][j]>max)
                    {
                        max=mypieces_score[i][j];
                        p=1;
                    }
                    else if(mypieces_score[i][j]==max)
                        p++;

                }
            }

        }
//    if(p==1)
    for(int i=1;i<=21;i++)
        for(int j=1;j<=21;j++)
        {
            if(mypieces_empty[i][j]==1&&mypieces_score[i][j]==max)
            {
                mypieces_color[i][j]=2;
                x1=i;
                y1=j;
                mystep++;
                qDebug()<<max;
                return ;
                //直接下i，j，然后跳转回去
            }
        }


//    else //同分数可能很多的时候，随机下
//    {
//        p=rand()/p;
//        for(int i=1;i<=21;i++)
//            for(int j=1;j<=21;j++)
//            {
//                if(mypieces_empty[i][j]==1&&mypieces_score[i][j]==max)
//                {
//                    if(p==0)
//                    {
//                        mypieces_color[i][j]=2;
//                        x1=i;
//                        y1=j;
//                        mystep++;
//                        return ;
//                        //直接下i，j，然后跳转回去
//                    }
//                    else
//                        p--;
//                }
//            }
//    }
}

int white_ai::white_6(int x, int y)
{

    int h=0,s=0,zx=0,fx=0;

    //横
    for(int i=1;i<=5;i++)
    {
        if(mypieces_color[x+i][y]!=2)
            break;
        else
            h++;
    }
    for(int i=1;i<=5;i++)
    {
        if(mypieces_color[x-i][y]!=2)
            break;
        else
            h++;
    }

    if(h>=5)
        return 25748;

    //竖
    for(int i=1;i<=5;i++)
    {
        if(mypieces_color[x][y+i]!=2)
            break;
        else
            s++;
    }
    for(int i=1;i<=5;i++)
    {
        if(mypieces_color[x][y-i]!=2)
            break;
        else
            s++;
    }

    if(s>=5)
        return 25748;

    //正斜
    for(int i=1;i<=5;i++)
    {
        if(mypieces_color[x+i][y+i]!=2)
            break;
        else
            zx++;
    }
    for(int i=1;i<=5;i++)
    {
        if(mypieces_color[x-i][y-i]!=2)
            break;
        else
            zx++;
    }

    if(zx>=5)
        return 25748;

    //反斜
    for(int i=1;i<=5;i++)
    {
        if(mypieces_color[x+i][y-i]!=2)
            break;
        else
            fx++;
    }
    for(int i=1;i<=5;i++)
    {
        if(mypieces_color[x-i][y+i]!=2)
            break;
        else
            fx++;
    }

    if(fx>=5)
        return 25748;

    return 0;
}

int white_ai::black_5(int x, int y)
{
    int h=0,s=0,zx=0,fx=0;
    int re=0;
    //横
    for(int i=1;i<=5;i++)
    {
        if(mypieces_color[x+i][y]!=1)
            break;
        else
            h++;

    }
    for(int i=1;i<=5;i++)
    {
        if(mypieces_color[x-i][y]!=1)
            break;
        else
            h++;
    }
    if(h>=5)
        re+=6436;
    //竖
    for(int i=1;i<=5;i++)
    {
        if(mypieces_color[x][y+i]!=1)
            break;
        else
            s++;
    }
    for(int i=1;i<=5;i++)
    {
        if(mypieces_color[x][y-i]!=1)
            break;
        else
            s++;
    }

    if(s>=5)
        re+=6436;

    //正斜
    for(int i=1;i<=5;i++)
    {
        if(mypieces_color[x+i][y+i]!=1)
            break;
        else
            zx++;
    }
    for(int i=1;i<=5;i++)
    {
        if(mypieces_color[x-i][y-i]!=1)
            break;
        else
            zx++;
    }

    if(zx>=5)
        re+=6436;

    //反斜
    for(int i=1;i<=5;i++)
    {
        if(mypieces_color[x+i][y-i]!=1)
            break;
        else
            fx++;
    }
    for(int i=1;i<=5;i++)
    {
        if(mypieces_color[x-i][y+i]!=1)
            break;
        else
            fx++;
    }

    if(fx>=5)
        re+=6436;

    return re;

}
int white_ai::white_live_5(int x, int y)
{

    int h=0,s=0,zx=0,fx=0;
    int re=0;

    mypieces_color[x][y]=2;

    //横
    for(int i=-5;i<=-1;i++)
    {
        h=0;
        if(mypieces_color[x+i][y]==0&&mypieces_color[x+i+6][y]==0)
            for(int j=1;j<=5;j++)
            {
                if(mypieces_color[x+i+j][y]==2)
                    h++;
            }
        if(h==5)
        {
            re+=1608;
            break;
        }
    }
    //横（带空）
    for(int i=-6;i<=-1;i++)
    {
        h=0;
        if(mypieces_color[x+i][y]==0&&
           mypieces_color[x+i+1][y]==2&&
           mypieces_color[x+i+6][y]==2&&
           mypieces_color[x+i+7][y]==0)
            for(int j=1;j<=6;j++)
            {
                if(mypieces_color[x+i+j][y]==2)
                    h++;
                else if(mypieces_color[x+i+j][y]==1)
                {
                    h=0;
                    break;
                }
            }
        if(h==5)
        {
            re+=1608;
            break;
        }
    }
    //竖
    for(int i=-5;i<=-1;i++)
    {
        s=0;
        if(mypieces_color[x][y+i]==0&&mypieces_color[x][y+i+6]==0)
            for(int j=1;j<=5;j++)
            {
                if(mypieces_color[x][y+i+j]==2)
                    s++;
            }
        if(s==5)
        {
            re+=1608;
            break;
        }
    }
    //竖（带空）
    for(int i=-6;i<=-1;i++)
    {
        s=0;
        if(mypieces_color[x][y+i]==0&&
           mypieces_color[x][y+i+1]==2&&
           mypieces_color[x][y+i+6]==2&&
           mypieces_color[x][y+i+7]==0)
            for(int j=1;j<=6;j++)
            {
                if(mypieces_color[x][y+i+j]==2)
                    s++;
                else if(mypieces_color[x][y+i+j]==1)
                {
                    s=0;
                    break;
                }
            }
        if(s==5)
        {
            re+=1608;
            break;
        }
    }

    //正斜
    for(int i=-5;i<=-1;i++)
    {
        zx=0;
        if(mypieces_color[x+i][y+i]==0&&mypieces_color[x+i+6][y+i+6]==0)
            for(int j=1;j<=5;j++)
            {
                if(mypieces_color[x+i+j][y+i+j]==2)
                    zx++;
            }
        if(zx==5)
        {
            re+=1608;
            break;
        }
    }
    //正斜（带空）
    for(int i=-6;i<=-1;i++)
    {
        zx=0;
        if(mypieces_color[x+i][y+i]==0&&
           mypieces_color[x+i+1][y+i+1]==2&&
           mypieces_color[x+i+6][y+i+6]==2&&
           mypieces_color[x+i+7][y+i+7]==0)
            for(int j=1;j<=6;j++)
            {
                if(mypieces_color[x+i+j][y+i+j]==2)
                    zx++;
                else if(mypieces_color[x+i+j][y+i+j]==1)
                {
                    zx=0;
                    break;
                }
            }
        if(zx==5)
        {
            re+=1608;
            break;
        }
    }

    //反斜
    for(int i=-5;i<=-1;i++)
    {
        fx=0;
        if(mypieces_color[x-i][y+i]==0&&mypieces_color[x-i-6][y+i+6]==0)
            for(int j=1;j<=5;j++)
            {
                if(mypieces_color[x-i-j][y+i+j]==2)
                    fx++;
            }
        if(fx==5)
        {
            re+=1608;
            break;
        }
    }
    //反斜（带空）
    for(int i=-6;i<=-1;i++)
    {
        fx=0;
        if(mypieces_color[x-i][y+i]==0&&
           mypieces_color[x-i-1][y+i+1]==2&&
           mypieces_color[x-i-6][y+i+6]==2&&
           mypieces_color[x-i-7][y+i+7]==0)
            for(int j=1;j<=6;j++)
            {
                if(mypieces_color[x-i-j][y+i+j]==2)
                    fx++;
                else if(mypieces_color[x-i-j][y+i+j]==1)
                {
                    fx=0;
                    break;
                }
            }
        if(fx==5)
        {
            re+=1608;
            break;
        }
    }

    mypieces_color[x][y]=0;

    return re;




}
int white_ai::black_live_4(int x, int y)
{
    int h=0,s=0,zx=0,fx=0;
    int re=0;

    //横
    for(int i=1;i<=5;i++)
    {
        if(mypieces_color[x+i][y]==1)
            h++;
        else if(mypieces_color[x+i][y]==2)
        {
            h=0;
            break;
        }
        else
            break;
    }
    for(int i=-1;i>=-5;i--)
    {
        if(mypieces_color[x+i][y]==1)
            h++;
        else if(mypieces_color[x+i][y]==2)
        {
            h=0;
            break;
        }
        else
            break;
    }

    if(h==4)
        re+=803;

    //竖
    for(int i=1;i<=5;i++)
    {
        if(mypieces_color[x][y+i]==1)
            s++;
        else if(mypieces_color[x][y+i]==2)
        {
            s=0;
            break;
        }
        else
            break;
    }
    for(int i=-1;i>=-5;i--)
    {
        if(mypieces_color[x][y+i]==1)
            s++;
        else if(mypieces_color[x][y+i]==2)
        {
            s=0;
            break;
        }
        else
            break;
    }

    if(s==4)
        re+=803;

    //正斜
    for(int i=1;i<=5;i++)
    {
        if(mypieces_color[x+i][y+i]==1)
            zx++;
        else if(mypieces_color[x+i][y+i]==2)
        {
            zx=0;
            break;
        }
        else
            break;
    }
    for(int i=-1;i>=-5;i--)
    {
        if(mypieces_color[x+i][y+i]==1)
            zx++;
        else if(mypieces_color[x+i][y+i]==2)
        {
            zx=0;
            break;
        }
        else
            break;
    }

    if(zx==4)
        re+=803;


    //反斜
    for(int i=1;i<=5;i++)
    {
        if(mypieces_color[x-i][y+i]==1)
            fx++;
        else if(mypieces_color[x-i][y+i]==2)
        {
            fx=0;
            break;
        }
        else
            break;
    }
    for(int i=-1;i>=-5;i--)
    {
        if(mypieces_color[x-i][y+i]==1)
            fx++;
        else if(mypieces_color[x-i][y+i]==2)
        {
            fx=0;
            break;
        }
        else
            break;
    }

    if(fx==4)
        re+=803;

    return re;

}
int white_ai::white_rush_5(int x, int y)
{
    int h=0,s=0,zx=0,fx=0;
    int re=0;
    mypieces_color[x][y]=2;
    //横
    for(int i=-5;i<=-1;i++)
    {
        h=0;
        if((mypieces_color[x+i][y]==0&&mypieces_color[x+i+6][y]==1)||
           (mypieces_color[x+i][y]==1&&mypieces_color[x+i+6][y]==0))
            for(int j=1;j<=5;j++)
            {
                if(mypieces_color[x+i+j][y]==2)
                    h++;
                else if(mypieces_color[x+i+j][y]==1)
                {
                    h=0;
                    break;
                }
            }
        if(h==5)
            re+=802;
    }

    //横（带空）
    for(int i=-6;i<=-1;i++)
    {
        h=0;
        if(((mypieces_color[x+i][y]==0&&mypieces_color[x+i+7][y]==1)||
           (mypieces_color[x+i][y]==1&&mypieces_color[x+i+7][y]==0))&&
            mypieces_color[x+i+1][y]==2&&mypieces_color[x+i+6][y]==2)

            for(int j=1;j<=6;j++)
            {
                if(mypieces_color[x+i+j][y]==2)
                    h++;
                else if(mypieces_color[x+i+j][y]==1)
                {
                    h=0;
                    break;
                }
            }
        if(h==5)
            re+=802;
    }


    //竖
    for(int i=-5;i<=-1;i++)
    {
        s=0;
        if((mypieces_color[x][y+i]==0&&mypieces_color[x][y+i+6]==1)||
           (mypieces_color[x][y+i]==1&&mypieces_color[x][y+i+6]==0))
            for(int j=1;j<=5;j++)
            {
                if(mypieces_color[x][y+i+j]==2)
                    s++;
                else if(mypieces_color[x][y+i+j]==1)
                {
                    s=0;
                    break;
                }
            }
        if(s==5)
            re+=802;
    }

    //竖（带空）
    for(int i=-6;i<=-1;i++)
    {
        s=0;
        if(((mypieces_color[x][y+i]==0&&mypieces_color[x][y+i+7]==1)||
           (mypieces_color[x][y+i]==1&&mypieces_color[x][y+i+7]==0))&&
            mypieces_color[x][y+i+1]==2&&mypieces_color[x][y+i+6]==2)

            for(int j=1;j<=6;j++)
            {
                if(mypieces_color[x][y+i+j]==2)
                    s++;
                else if(mypieces_color[x][y+i+j]==1)
                {
                    s=0;
                    break;
                }
            }
        if(s==5)
            re+=802;
    }


    //正斜
    for(int i=-5;i<=-1;i++)
    {
        zx=0;
        if((mypieces_color[x+i][y+i]==0&&mypieces_color[x+i+6][y+i+6]==1)||
           (mypieces_color[x+i][y+i]==1&&mypieces_color[x+i+6][y+i+6]==0))
            for(int j=1;j<=5;j++)
            {
                if(mypieces_color[x+i+j][y+i+j]==2)
                    zx++;
                else if(mypieces_color[x+i+j][y+i+j]==1)
                {
                    zx=0;
                    break;
                }
            }
        if(zx==5)
            re+=802;
    }

    //正斜（带空）
    for(int i=-6;i<=-1;i++)
    {
        zx=0;
        if(((mypieces_color[x+i][y+i]==0&&mypieces_color[x+i+7][y+i+7]==1)||
           (mypieces_color[x+i][y+i]==1&&mypieces_color[x+i+7][y+i+7]==0))&&
            mypieces_color[x+i+1][y+i+1]==2&&mypieces_color[x+i+6][y+i+6]==2)

            for(int j=1;j<=6;j++)
            {
                if(mypieces_color[x+i+j][y+i+j]==2)
                    zx++;
                else if(mypieces_color[x+i+j][y+i+j]==1)
                {
                    zx=0;
                    break;
                }
            }
        if(zx==5)
            re+=802;
    }


    //反斜
    for(int i=-5;i<=-1;i++)
    {
        fx=0;
        if((mypieces_color[x-i][y+i]==0&&mypieces_color[x-i-6][y+i+6]==1)||
           (mypieces_color[x-i][y+i]==1&&mypieces_color[x-i-6][y+i+6]==0))
            for(int j=1;j<=5;j++)
            {
                if(mypieces_color[x-i-j][y+i+j]==2)
                    fx++;
                else if(mypieces_color[x-i-j][y+i+j]==1)
                {
                    fx=0;
                    break;
                }
            }
        if(fx==5)
            re+=802;
    }

    //反斜（带空）
    for(int i=-6;i<=-1;i++)
    {
        fx=0;
        if(((mypieces_color[x-i][y+i]==0&&mypieces_color[x-i-7][y+i+7]==1)||
           (mypieces_color[x-i][y+i]==1&&mypieces_color[x-i-7][y+i+7]==0))&&
            mypieces_color[x-i-1][y+i+1]==2&&mypieces_color[x-i-6][y+i+6]==2)

            for(int j=1;j<=6;j++)
            {
                if(mypieces_color[x-i-j][y+i+j]==2)
                    fx++;
                else if(mypieces_color[x-i-j][y+i+j]==1)
                {
                    fx=0;
                    break;
                }
            }
        if(fx==5)
            re+=802;
    }


    mypieces_color[x][y]=0;
    return re;
}
int white_ai::black_rush_4(int x, int y)
{
    int h=0,s=0,zx=0,fx=0;
    int re=0;
    int w=0,k=0;
    //向两边延伸，一边遇到白，另一边遇到空
    //横
    w=0;k=0;
    for(int i=1;i<=5;i++)
    {
        if(mypieces_color[x+i][y]==1)
            h++;
        else if(mypieces_color[x+i][y]==0)
        {
            k++;
            break;
        }
        else if(mypieces_color[x+i][y]==2)
        {
            w++;
            break;
        }
    }
    for(int i=-1;i>=-5;i--)
    {
        if(mypieces_color[x+i][y]==1)
            h++;
        else if(mypieces_color[x+i][y]==0)
        {
            k++;
            break;
        }
        else if(mypieces_color[x+i][y]==2)
        {
            w++;
            break;
        }
    }
    if(h==4&&w==k&&w==1)
        re+=400;

    //竖
    w=0;k=0;
    for(int i=1;i<=5;i++)
    {
        if(mypieces_color[x][y+i]==1)
            s++;
        else if(mypieces_color[x][y+i]==0)
        {
            k++;
            break;
        }
        else if(mypieces_color[x][y+i]==2)
        {
            w++;
            break;
        }
    }
    for(int i=-1;i>=-5;i--)
    {
        if(mypieces_color[x][y+i]==1)
            s++;
        else if(mypieces_color[x][y+i]==0)
        {
            k++;
            break;
        }
        else if(mypieces_color[x][y+i]==2)
        {
            w++;
            break;
        }
    }
    if(s==4&&w==k&&w==1)
        re+=400;

    //正斜
    w=0;k=0;
    for(int i=1;i<=5;i++)
    {
        if(mypieces_color[x+i][y+i]==1)
            zx++;
        else if(mypieces_color[x+i][y+i]==0)
        {
            k++;
            break;
        }
        else if(mypieces_color[x+i][y+i]==2)
        {
            w++;
            break;
        }
    }
    for(int i=-1;i>=-5;i--)
    {
        if(mypieces_color[x+i][y+i]==1)
            zx++;
        else if(mypieces_color[x+i][y+i]==0)
        {
            k++;
            break;
        }
        else if(mypieces_color[x+i][y+i]==2)
        {
            w++;
            break;
        }
    }
    if(zx==4&&w==k&&w==1)
        re+=400;

    //反斜
    w=0;k=0;
    for(int i=1;i<=5;i++)
    {
        if(mypieces_color[x-i][y+i]==1)
            fx++;
        else if(mypieces_color[x-i][y+i]==0)
        {
            k++;
            break;
        }
        else if(mypieces_color[x-i][y+i]==2)
        {
            w++;
            break;
        }
    }
    for(int i=-1;i>=-5;i--)
    {
        if(mypieces_color[x-i][y+i]==1)
            fx++;
        else if(mypieces_color[x-i][y+i]==0)
        {
            k++;
            break;
        }
        else if(mypieces_color[x-i][y+i]==2)
        {
            w++;
            break;
        }
    }
    if(fx==4&&w==k&&w==1)
        re+=400;

    return re;
}
int white_ai::white_live_4(int x, int y)
{
    int h=0,s=0,zx=0,fx=0;
    int re=0;
    mypieces_color[x][y]=2;
    //横
    for(int i=-4;i<=-1;i++)
    {
        if(mypieces_color[x+i][y]==0&&
           mypieces_color[x+i+1][y]==2&&
           mypieces_color[x+i+2][y]==2&&
           mypieces_color[x+i+3][y]==2&&
           mypieces_color[x+i+4][y]==2&&
           mypieces_color[x+i+5][y]==0)
        {
            re+=99;
            break;
        }
    }
    //横(带空）

    for(int i=-5;i<=-1;i++)
    {
        h=0;
        if(mypieces_color[x+i][y]==0&&
           mypieces_color[x+i+1][y]==2&&
           mypieces_color[x+i+5][y]==2&&
           mypieces_color[x+i+6][y]==0)
        {
            for(int j=1;j<=5;j++)
            {
                if(mypieces_color[x+i+j][y]==2)
                    h++;
                else if(mypieces_color[x+i+j][y]==1)
                {
                    h=0;
                    break;
                }
            }
            if(h==4)
            {
                re+=99;
                break;
            }
        }
    }

    //竖
    for(int i=-4;i<=-1;i++)
    {
        if(mypieces_color[x][y+i]==0&&
           mypieces_color[x][y+i+1]==2&&
           mypieces_color[x][y+i+2]==2&&
           mypieces_color[x][y+i+3]==2&&
           mypieces_color[x][y+i+4]==2&&
           mypieces_color[x][y+i+5]==0)
        {
            re+=99;
            break;
        }
    }
    //竖(带空）

    for(int i=-5;i<=-1;i++)
    {
        s=0;
        if(mypieces_color[x][y+i]==0&&
           mypieces_color[x][y+i+1]==2&&
           mypieces_color[x][y+i+5]==2&&
           mypieces_color[x][y+i+6]==0)
        {
            for(int j=1;j<=5;j++)
            {
                if(mypieces_color[x][y+i+j]==2)
                    s++;
                else if(mypieces_color[x][y+i+j]==1)
                {
                    s=0;
                    break;
                }
            }
            if(s==4)
            {
                re+=99;
                break;
            }
        }
    }

    //正斜
    for(int i=-4;i<=-1;i++)
    {
        if(mypieces_color[x+i][y+i]==0&&
           mypieces_color[x+i+1][y+i+1]==2&&
           mypieces_color[x+i+2][y+i+2]==2&&
           mypieces_color[x+i+3][y+i+3]==2&&
           mypieces_color[x+i+4][y+i+4]==2&&
           mypieces_color[x+i+5][y+i+5]==0)
        {
            re+=99;
            break;
        }
    }
    //正斜(带空）

    for(int i=-5;i<=-1;i++)
    {
        zx=0;
        if(mypieces_color[x+i][y+i]==0&&
           mypieces_color[x+i+1][y+i+1]==2&&
           mypieces_color[x+i+5][y+i+5]==2&&
           mypieces_color[x+i+6][y+i+6]==0)
        {
            for(int j=1;j<=5;j++)
            {
                if(mypieces_color[x+i+j][y+i+j]==2)
                    zx++;
                else if(mypieces_color[x+i+j][y+i+j]==1)
                {
                    zx=0;
                    break;
                }
            }
            if(zx==4)
            {
                re+=99;
                break;
            }
        }
    }
    //反斜
    for(int i=-4;i<=-1;i++)
    {
        if(mypieces_color[x-i][y+i]==0&&
           mypieces_color[x-i-1][y+i+1]==2&&
           mypieces_color[x-i-2][y+i+2]==2&&
           mypieces_color[x-i-3][y+i+3]==2&&
           mypieces_color[x-i-4][y+i+4]==2&&
           mypieces_color[x-i-5][y+i+5]==0)
        {
            re+=99;
            break;
        }
    }
    //反斜(带空）

    for(int i=-5;i<=-1;i++)
    {
        fx=0;
        if(mypieces_color[x-i][y+i]==0&&
           mypieces_color[x-i-1][y+i+1]==2&&
           mypieces_color[x-i-5][y+i+5]==2&&
           mypieces_color[x-i-6][y+i+6]==0)
        {
            for(int j=1;j<=5;j++)
            {
                if(mypieces_color[x-i-j][y+i+j]==2)
                    fx++;
                else if(mypieces_color[x-i-j][y+i+j]==1)
                {
                    fx=0;
                    break;
                }
            }
            if(fx==4)
            {
                re+=99;
                break;
            }
        }
    }

    mypieces_color[x][y]=0;
    return re;
}
int white_ai::black_live_3(int x, int y)
{

    //两边延伸，遇空格停止，遇白归零
    int h=0,s=0,zx=0,fx=0;
    int re=0;
    //横
    h=0;
    for(int i=1;i<=4;i++)
    {
        if(mypieces_color[x+i][y]==1)
            h++;
        else if(mypieces_color[x+i][y]==2)
        {
            h=0;
            break;
        }
        else
        {
            break;
        }
    }
    for(int i=-1;i>=-4;i--)
    {
        if(mypieces_color[x+i][y]==1)
            h++;
        else if(mypieces_color[x+i][y]==2)
        {
            h=0;
            break;
        }
        else
        {
            break;
        }
    }
    if(h==3)
        re+=98;

    //竖
    s=0;
    for(int i=1;i<=4;i++)
    {
        if(mypieces_color[x][y+i]==1)
            s++;
        else if(mypieces_color[x][y+i]==2)
        {
            s=0;
            break;
        }
        else
        {
            break;
        }
    }
    for(int i=-1;i>=-4;i--)
    {
        if(mypieces_color[x][y+i]==1)
            s++;
        else if(mypieces_color[x][y+i]==2)
        {
            s=0;
            break;
        }
        else
        {
            break;
        }
    }
    if(s==3)
        re+=98;

    //正斜
    zx=0;
    for(int i=1;i<=4;i++)
    {
        if(mypieces_color[x+i][y+i]==1)
            zx++;
        else if(mypieces_color[x+i][y+i]==2)
        {
            zx=0;
            break;
        }
        else
        {
            break;
        }
    }
    for(int i=-1;i>=-4;i--)
    {
        if(mypieces_color[x+i][y+i]==1)
            zx++;
        else if(mypieces_color[x+i][y+i]==2)
        {
            zx=0;
            break;
        }
        else
        {
            break;
        }
    }
    if(zx==3)
        re+=98;

    //反斜
    fx=0;
    for(int i=1;i<=4;i++)
    {
        if(mypieces_color[x-i][y+i]==1)
            fx++;
        else if(mypieces_color[x-i][y+i]==2)
        {
            fx=0;
            break;
        }
        else
        {
            break;
        }
    }
    for(int i=-1;i>=-4;i--)
    {
        if(mypieces_color[x-i][y+i]==1)
            fx++;
        else if(mypieces_color[x-i][y+i]==2)
        {
            fx=0;
            break;
        }
        else
        {
            break;
        }
    }
    if(fx==3)
        re+=98;

    return re;
}
int white_ai::white_rush_4(int x, int y)
{
    int h=0,s=0,zx=0,fx=0;
    int re=0;
    mypieces_color[x][y]=2;

    //横
    for(int i=-4;i<=-1;i++)
    {
        if((mypieces_color[x+i][y]==0&&mypieces_color[x+i+5][y]==1)||
           (mypieces_color[x+i][y]==1&&mypieces_color[x+i+5][y]==0))
            for(int j=1;j<=4;j++)
            {
                if(mypieces_color[x+i+j][y]==2)
                    h++;
                else if(mypieces_color[x+i+j][y]==1)
                {
                    h=0;
                    break;
                }
            }
    }
    if(h==4)
        re+=97;
    //横（带空）

    for(int i=-5;i<=-1;i++)
    {
        h=0;
        if(((mypieces_color[x+i][y]==0&&mypieces_color[x+i+6][y]==1)||
           (mypieces_color[x+i][y]==1&&mypieces_color[x+i+6][y]==0))&&
            mypieces_color[x+i+1][y]==2&&mypieces_color[x+i+5][y]==2)

            for(int j=1;j<=5;j++)
            {
                if(mypieces_color[x+i+j][y]==2)
                    h++;
                else if(mypieces_color[x+i+j][y]==1)
                {
                    h=0;
                    break;
                }
            }
        if(h==4)
            re+=97;
    }


    //竖
    for(int i=-4;i<=-1;i++)
    {
        if((mypieces_color[x][y+i]==0&&mypieces_color[x][y+i+5]==1)||
           (mypieces_color[x][y+i]==1&&mypieces_color[x][y+i+5]==0))
            for(int j=1;j<=4;j++)
            {
                if(mypieces_color[x][y+i+j]==2)
                    s++;
                else if(mypieces_color[x][y+i+j]==1)
                {
                    s=0;
                    break;
                }
            }
    }
    if(s==4)
        re+=97;
    //竖（带空）

    for(int i=-5;i<=-1;i++)
    {
        s=0;
        if(((mypieces_color[x][y+i]==0&&mypieces_color[x][y+i+6]==1)||
           (mypieces_color[x][y+i]==1&&mypieces_color[x][y+i+6]==0))&&
            mypieces_color[x][y+i+1]==2&&mypieces_color[x][y+i+5]==2)

            for(int j=1;j<=5;j++)
            {
                if(mypieces_color[x][y+i+j]==2)
                    s++;
                else if(mypieces_color[x][y+i+j]==1)
                {
                    s=0;
                    break;
                }
            }
        if(s==4)
            re+=97;
    }


    //正斜
    for(int i=-4;i<=-1;i++)
    {
        if((mypieces_color[x+i][y+i]==0&&mypieces_color[x+i+5][y+i+5]==1)||
           (mypieces_color[x+i][y+i]==1&&mypieces_color[x+i+5][y+i+5]==0))
            for(int j=1;j<=4;j++)
            {
                if(mypieces_color[x+i+j][y+i+j]==2)
                    zx++;
                else if(mypieces_color[x+i+j][y+i+j]==1)
                {
                    zx=0;
                    break;
                }
            }
    }
    if(zx==4)
        re+=97;
    //正斜（带空）

    for(int i=-5;i<=-1;i++)
    {
        zx=0;
        if(((mypieces_color[x+i][y+i]==0&&mypieces_color[x+i+6][y+i+6]==1)||
           (mypieces_color[x+i][y+i]==1&&mypieces_color[x+i+6][y+i+6]==0))&&
            mypieces_color[x+i+1][y+i+1]==2&&mypieces_color[x+i+5][y+i+5]==2)

            for(int j=1;j<=5;j++)
            {
                if(mypieces_color[x+i+j][y+i+j]==2)
                    zx++;
                else if(mypieces_color[x+i+j][y+i+j]==1)
                {
                    zx=0;
                    break;
                }
            }
        if(zx==4)
            re+=97;
    }


    //反斜

    for(int i=-4;i<=-1;i++)
    {
        if((mypieces_color[x-i][y+i]==0&&mypieces_color[x-i-5][y+i+5]==1)||
           (mypieces_color[x-i][y+i]==1&&mypieces_color[x-i-5][y+i+5]==0))
            for(int j=1;j<=4;j++)
            {
                if(mypieces_color[x-i-j][y-i-j]==2)
                    fx++;
                else if(mypieces_color[x-i-j][y-i-j]==1)
                {
                    fx=0;
                    break;
                }
            }
    }
    if(fx==4)
        re+=97;
    //反斜（带空）

    for(int i=-5;i<=-1;i++)
    {
        fx=0;
        if(((mypieces_color[x-i][y+i]==0&&mypieces_color[x-i-6][y+i+6]==1)||
           (mypieces_color[x-i][y+i]==1&&mypieces_color[x-i-6][y+i+6]==0))&&
            mypieces_color[x-i-1][y+i+1]==2&&mypieces_color[x-i-5][y+i+5]==2)

            for(int j=1;j<=5;j++)
            {
                if(mypieces_color[x-i-j][y+i+j]==2)
                    fx++;
                else if(mypieces_color[x-i-j][y+i+j]==1)
                {
                    fx=0;
                    break;
                }
            }
        if(fx==4)
            re+=97;
    }


    mypieces_color[x][y]=0;

    return re;
}
int white_ai::black_rush_3(int x, int y)
{
    int h=0,s=0,zx=0,fx=0;
    int re=0;
    int w=0,k=0;
    //向两边延伸，一边遇到白，另一边遇到空
    //横
    w=0;k=0;
    for(int i=1;i<=4;i++)
    {
        if(mypieces_color[x+i][y]==1)
            h++;
        else if(mypieces_color[x+i][y]==0)
        {
            k++;
            break;
        }
        else if(mypieces_color[x+i][y]==2)
        {
            w++;
            break;
        }
    }
    for(int i=-1;i>=-4;i--)
    {
        if(mypieces_color[x+i][y]==1)
            h++;
        else if(mypieces_color[x+i][y]==0)
        {
            k++;
            break;
        }
        else if(mypieces_color[x+i][y]==2)
        {
            w++;
            break;
        }
    }
    if(h==3&&w==k&&w==1)
        re+=96;

    //竖
    w=0;k=0;
    for(int i=1;i<=4;i++)
    {
        if(mypieces_color[x][y+i]==1)
            s++;
        else if(mypieces_color[x][y+i]==0)
        {
            k++;
            break;
        }
        else if(mypieces_color[x][y+i]==2)
        {
            w++;
            break;
        }
    }
    for(int i=-1;i>=-4;i--)
    {
        if(mypieces_color[x][y+i]==1)
            s++;
        else if(mypieces_color[x][y+i]==0)
        {
            k++;
            break;
        }
        else if(mypieces_color[x][y+i]==2)
        {
            w++;
            break;
        }
    }
    if(s==3&&w==k&&w==1)
        re+=96;

    //正斜
    w=0;k=0;
    for(int i=1;i<=4;i++)
    {
        if(mypieces_color[x+i][y+i]==1)
            zx++;
        else if(mypieces_color[x+i][y+i]==0)
        {
            k++;
            break;
        }
        else if(mypieces_color[x+i][y+i]==2)
        {
            w++;
            break;
        }
    }
    for(int i=-1;i>=-4;i--)
    {
        if(mypieces_color[x+i][y+i]==1)
            zx++;
        else if(mypieces_color[x+i][y+i]==0)
        {
            k++;
            break;
        }
        else if(mypieces_color[x+i][y+i]==2)
        {
            w++;
            break;
        }
    }
    if(zx==3&&w==k&&w==1)
        re+=96;
    //反斜
    w=0;k=0;
    for(int i=1;i<=4;i++)
    {
        if(mypieces_color[x-i][y+i]==1)
            fx++;
        else if(mypieces_color[x-i][y+i]==0)
        {
            k++;
            break;
        }
        else if(mypieces_color[x-i][y+i]==2)
        {
            w++;
            break;
        }
    }
    for(int i=-1;i>=-4;i--)
    {
        if(mypieces_color[x-i][y+i]==1)
            fx++;
        else if(mypieces_color[x-i][y+i]==0)
        {
            k++;
            break;
        }
        else if(mypieces_color[x-i][y+i]==2)
        {
            w++;
            break;
        }
    }
    if(fx==3&&w==k&&w==1)
        re+=400;

    return re;

}
int white_ai::white_live_3(int x, int y)
{
    int re=0;
    //直接列
    //横
    if(mypieces_color[x-3][y]==0&&
       mypieces_color[x-2][y]==2&&
       mypieces_color[x-1][y]==2&&
       mypieces_color[x+1][y]==0)
        re+=23;
    else if(mypieces_color[x+3][y]==0&&
       mypieces_color[x+2][y]==2&&
       mypieces_color[x+1][y]==2&&
       mypieces_color[x-1][y]==0)
        re+=23;
    else if(mypieces_color[x-2][y]==0&&
       mypieces_color[x-1][y]==2&&
       mypieces_color[x+1][y]==2&&
       mypieces_color[x+2][y]==0)
        re+=23;

    //竖
    if(mypieces_color[x][y-3]==0&&
       mypieces_color[x][y-2]==2&&
       mypieces_color[x][y-1]==2&&
       mypieces_color[x][y+1]==0)
        re+=23;
    else if(mypieces_color[x][y+3]==0&&
       mypieces_color[x][y+2]==2&&
       mypieces_color[x][y+1]==2&&
       mypieces_color[x][y-1]==0)
        re+=23;
    else if(mypieces_color[x][y-2]==0&&
       mypieces_color[x][y-1]==2&&
       mypieces_color[x][y+1]==2&&
       mypieces_color[x][y+2]==0)
        re+=23;
    //正斜
    if(mypieces_color[x-3][y-3]==0&&
       mypieces_color[x-2][y-2]==2&&
       mypieces_color[x-1][y-1]==2&&
       mypieces_color[x+1][y+1]==0)
        re+=23;
    else if(mypieces_color[x+3][y+3]==0&&
       mypieces_color[x+2][y+2]==2&&
       mypieces_color[x+1][y+1]==2&&
       mypieces_color[x-1][y-1]==0)
        re+=23;
    else if(mypieces_color[x-2][y-2]==0&&
       mypieces_color[x-1][y-1]==2&&
       mypieces_color[x+1][y+1]==2&&
       mypieces_color[x+2][y+2]==0)
        re+=23;

    //反斜
    if(mypieces_color[x+3][y-3]==0&&
       mypieces_color[x+2][y-2]==2&&
       mypieces_color[x+1][y-1]==2&&
       mypieces_color[x-1][y+1]==0)
        re+=23;
    else if(mypieces_color[x-3][y+3]==0&&
       mypieces_color[x-2][y+2]==2&&
       mypieces_color[x-1][y+1]==2&&
       mypieces_color[x+1][y-1]==0)
        re+=23;
    else if(mypieces_color[x+2][y-2]==0&&
       mypieces_color[x+1][y-1]==2&&
       mypieces_color[x-1][y+1]==2&&
       mypieces_color[x-2][y+2]==0)
        re+=23;

    return re;
}
int white_ai::black_live_2(int x, int y)
{
    int re=0;
    //直接列
    //横
    if(mypieces_color[x-3][y]==0&&
       mypieces_color[x-2][y]==1&&
       mypieces_color[x-1][y]==1)
        re+=22;
    else if(mypieces_color[x+3][y]==0&&
       mypieces_color[x+2][y]==1&&
       mypieces_color[x+1][y]==1)
        re+=22;
    else if(mypieces_color[x-2][y]==0&&
       mypieces_color[x-1][y]==1&&
       mypieces_color[x+1][y]==1&&
       mypieces_color[x+2][y]==0)
        re+=22;

    //竖
    if(mypieces_color[x][y-3]==0&&
       mypieces_color[x][y-2]==1&&
       mypieces_color[x][y-1]==1)
        re+=22;
    else if(mypieces_color[x][y+3]==0&&
       mypieces_color[x][y+2]==1&&
       mypieces_color[x][y+1]==1)
        re+=22;
    else if(mypieces_color[x][y-2]==0&&
       mypieces_color[x][y-1]==1&&
       mypieces_color[x][y+1]==1&&
       mypieces_color[x][y+2]==0)
        re+=22;
    //正斜
    if(mypieces_color[x-3][y-3]==0&&
       mypieces_color[x-2][y-2]==1&&
       mypieces_color[x-1][y-1]==1)
        re+=22;
    else if(mypieces_color[x+3][y+3]==0&&
       mypieces_color[x+2][y+2]==1&&
       mypieces_color[x+1][y+1]==1)
        re+=22;
    else if(mypieces_color[x-2][y-2]==0&&
       mypieces_color[x-1][y-1]==1&&
       mypieces_color[x+1][y+1]==1&&
       mypieces_color[x+2][y+2]==0)
        re+=22;

    //反斜
    if(mypieces_color[x+3][y-3]==0&&
       mypieces_color[x+2][y-2]==1&&
       mypieces_color[x+1][y-1]==1)
        re+=22;
    else if(mypieces_color[x-3][y+3]==0&&
       mypieces_color[x-2][y+2]==1&&
       mypieces_color[x-1][y+1]==1)
        re+=22;
    else if(mypieces_color[x+2][y-2]==0&&
       mypieces_color[x+1][y-1]==1&&
       mypieces_color[x-1][y+1]==1&&
       mypieces_color[x-2][y+2]==0)
        re+=22;

    return re;
}
int white_ai::white_rush_3(int x, int y)
{
    int re=0;
    //直接列
    //横
    if(((mypieces_color[x-3][y]==0&&mypieces_color[x+1][y]==1)||(mypieces_color[x-3][y]==1&&mypieces_color[x+1][y]==0))&&
       mypieces_color[x-2][y]==2&&
       mypieces_color[x-1][y]==2)
        re+=21;
    else if(((mypieces_color[x+3][y]==0&&mypieces_color[x-1][y]==1)||(mypieces_color[x+3][y]==1&&mypieces_color[x-1][y]==0))&&
       mypieces_color[x+2][y]==2&&
       mypieces_color[x+1][y]==2)
        re+=21;
    else if(((mypieces_color[x-2][y]==0&&mypieces_color[x+2][y]==1)||(mypieces_color[x-2][y]==1&&mypieces_color[x+2][y]==0))&&
       mypieces_color[x-1][y]==2&&
       mypieces_color[x+1][y]==2)
        re+=21;

    //竖
    if(((mypieces_color[x][y-3]==0&&mypieces_color[x][y+1]==1)||(mypieces_color[x][y-3]==1&&mypieces_color[x][y+1]==0))&&
       mypieces_color[x][y-2]==2&&
       mypieces_color[x][y-1]==2)
        re+=21;
    else if(((mypieces_color[x][y+3]==0&&mypieces_color[x][y-1]==1)||(mypieces_color[x][y+3]==1&&mypieces_color[x][y-1]==0))&&
       mypieces_color[x][y+2]==2&&
       mypieces_color[x][y+1]==2)
        re+=21;
    else if(((mypieces_color[x][y-2]==0&&mypieces_color[x][y+2]==1)||(mypieces_color[x][y-2]==1&&mypieces_color[x][y+2]==0))&&
       mypieces_color[x][y-1]==2&&
       mypieces_color[x][y+1]==2)
        re+=21;
    //正斜
    if(((mypieces_color[x-3][y-3]==0&&mypieces_color[x+1][y+1]==1)||(mypieces_color[x-3][y-3]==1&&mypieces_color[x+1][y+1]==0))&&
       mypieces_color[x-2][y-2]==2&&
       mypieces_color[x-1][y-1]==2)
        re+=21;
    else if(((mypieces_color[x+3][y+3]==0&&mypieces_color[x-1][y-1]==1)||(mypieces_color[x+3][y+3]==1&&mypieces_color[x-1][y-1]==0))&&
       mypieces_color[x+2][y+2]==2&&
       mypieces_color[x+1][y+1]==2)
        re+=21;
    else if(((mypieces_color[x-2][y-2]==0&&mypieces_color[x+2][y+2]==1)||(mypieces_color[x-2][y-2]==1&&mypieces_color[x+2][y+2]==0))&&
       mypieces_color[x-1][y-1]==2&&
       mypieces_color[x+1][y+1]==2)
        re+=21;

    //反斜
    if(((mypieces_color[x+3][y-3]==0&&mypieces_color[x-1][y+1]==1)||(mypieces_color[x+3][y-3]==1&&mypieces_color[x-1][y+1]==0))&&
       mypieces_color[x+2][y-2]==2&&
       mypieces_color[x+1][y-1]==2)
        re+=21;
    else if(((mypieces_color[x-3][y+3]==0&&mypieces_color[x+1][y-1]==1)||(mypieces_color[x-3][y+3]==1&&mypieces_color[x+1][y-1]==0))&&
       mypieces_color[x-2][y+2]==2&&
       mypieces_color[x-1][y+1]==2)
        re+=21;
    else if(((mypieces_color[x+2][y-2]==0&&mypieces_color[x-2][y+2]==1)||(mypieces_color[x+2][y-2]==1&&mypieces_color[x-2][y+2]==0))&&
       mypieces_color[x+1][y-1]==2&&
       mypieces_color[x-1][y+1]==2)
        re+=21;

    return re;
}
int white_ai::white_live_2(int x, int y)
{
    int re=0;
    //横
    if(mypieces_color[x+1][y]==2&&
       mypieces_color[x+2][y]==2&&
       mypieces_color[x+3][y]==0)
        re+=4;
    else if(mypieces_color[x-1][y]==2&&
            mypieces_color[x-2][y]==2&&
            mypieces_color[x-3][y]==0)
        re+=4;
    else if(mypieces_color[x-2][y]==0&&
            mypieces_color[x-1][y]==2&&
            mypieces_color[x+1][y]==2&&
            mypieces_color[x+2][y]==0)
        re+=4;

    //竖
    if(mypieces_color[x][y+1]==2&&
       mypieces_color[x][y+2]==2&&
       mypieces_color[x][y+3]==0)
        re+=4;
    else if(mypieces_color[x][y-1]==2&&
            mypieces_color[x][y-2]==2&&
            mypieces_color[x][y-3]==0)
        re+=4;
    else if(mypieces_color[x][y-2]==0&&
            mypieces_color[x][y-1]==2&&
            mypieces_color[x][y+1]==2&&
            mypieces_color[x][y+2]==0)
        re+=4;

    //正斜
    if(mypieces_color[x+1][y+1]==2&&
       mypieces_color[x+2][y+2]==2&&
       mypieces_color[x+3][y+3]==0)
        re+=4;
    else if(mypieces_color[x-1][y-1]==2&&
            mypieces_color[x-2][y-2]==2&&
            mypieces_color[x-3][y-3]==0)
        re+=4;
    else if(mypieces_color[x-2][y-2]==0&&
            mypieces_color[x-1][y-1]==2&&
            mypieces_color[x+1][y+1]==2&&
            mypieces_color[x+2][y+2]==0)
        re+=4;

    //反斜
    if(mypieces_color[x-1][y+1]==2&&
       mypieces_color[x-2][y+2]==2&&
       mypieces_color[x-3][y+3]==0)
        re+=4;
    else if(mypieces_color[x+1][y-1]==2&&
            mypieces_color[x+2][y-2]==2&&
            mypieces_color[x+3][y-3]==0)
        re+=4;
    else if(mypieces_color[x+2][y-2]==0&&
            mypieces_color[x+1][y-1]==2&&
            mypieces_color[x-1][y+1]==2&&
            mypieces_color[x-2][y+2]==0)
        re+=4;
    return re;
}
int white_ai::black_live_1(int x, int y)
{
    int re=0;
    if(mypieces_color[x][y-1]==0&&
       mypieces_color[x][y]==0&&
       mypieces_color[x][y+1]==0&&
       mypieces_color[x+1][y-1]==0&&
       mypieces_color[x+1][y]==1&&
       mypieces_color[x+1][y+1]==0&&
       mypieces_color[x+2][y-1]==0&&
       mypieces_color[x+2][y]==0&&
       mypieces_color[x+2][y+1]==0)//右
    re+=3;

    if(mypieces_color[x][y-2]==0&&
       mypieces_color[x][y-1]==0&&
       mypieces_color[x][y]==0&&
       mypieces_color[x+1][y-2]==0&&
       mypieces_color[x+1][y-1]==1&&
       mypieces_color[x+1][y]==0&&
       mypieces_color[x+2][y-2]==0&&
       mypieces_color[x+2][y-1]==0&&
       mypieces_color[x+2][y]==0)//右上
    re+=3;

    if(mypieces_color[x][y]==0&&
       mypieces_color[x][y+1]==0&&
       mypieces_color[x][y+2]==0&&
       mypieces_color[x+1][y]==0&&
       mypieces_color[x+1][y+1]==1&&
       mypieces_color[x+1][y+2]==0&&
       mypieces_color[x+2][y]==0&&
       mypieces_color[x+2][y+1]==0&&
       mypieces_color[x+2][y+2]==0)//上
    re+=3;

    if(mypieces_color[x-1][y-2]==0&&
       mypieces_color[x-1][y-1]==0&&
       mypieces_color[x-1][y]==0&&
       mypieces_color[x][y-2]==0&&
       mypieces_color[x][y-1]==1&&
       mypieces_color[x][y]==0&&
       mypieces_color[x+1][y-2]==0&&
       mypieces_color[x+1][y-1]==0&&
       mypieces_color[x+1][y]==0)//左上
    re+=3;

    if(mypieces_color[x-2][y-2]==0&&
       mypieces_color[x-2][y-1]==0&&
       mypieces_color[x-2][y]==0&&
       mypieces_color[x-1][y-2]==0&&
       mypieces_color[x-1][y-1]==1&&
       mypieces_color[x-1][y]==0&&
       mypieces_color[x][y-2]==0&&
       mypieces_color[x][y-1]==0&&
       mypieces_color[x][y]==0)//左
    re+=3;

    if(mypieces_color[x-2][y]==0&&
       mypieces_color[x-2][y+1]==0&&
       mypieces_color[x-2][y+2]==0&&
       mypieces_color[x-1][y]==0&&
       mypieces_color[x-1][y+1]==1&&
       mypieces_color[x-1][y+2]==0&&
       mypieces_color[x][y]==0&&
       mypieces_color[x][y+1]==0&&
       mypieces_color[x][y+2]==0)//左下
    re+=3;

    if(mypieces_color[x-1][y]==0&&
       mypieces_color[x-1][y+1]==0&&
       mypieces_color[x-1][y+2]==0&&
       mypieces_color[x][y]==0&&
       mypieces_color[x][y+1]==1&&
       mypieces_color[x][y+2]==0&&
       mypieces_color[x+1][y]==0&&
       mypieces_color[x+1][y+1]==0&&
       mypieces_color[x+1][y+2]==0)//下
    re+=3;

    if(mypieces_color[x][y]==0&&
       mypieces_color[x][y+1]==0&&
       mypieces_color[x][y+2]==0&&
       mypieces_color[x+1][y]==0&&
       mypieces_color[x+1][y+1]==1&&
       mypieces_color[x+1][y+2]==0&&
       mypieces_color[x+2][y]==0&&
       mypieces_color[x+2][y+1]==0&&
       mypieces_color[x+2][y+2]==0)//右下
    re+=3;
    return re;
}
int white_ai::white_rush_2(int x, int y)
{
    int re=0;
    mypieces_color[x][y]=2;
    //横
    if(((mypieces_color[x-1][y]==1&&mypieces_color[x+2][y]==0)||
        (mypieces_color[x-1][y]==0&&mypieces_color[x+2][y]==1))&&
       mypieces_color[x+1][y]==2)
        re+=4;
    else if(((mypieces_color[x+1][y]==1&&mypieces_color[x-2][y]==0)||
             (mypieces_color[x+1][y]==0&&mypieces_color[x-2][y]==1))&&
            mypieces_color[x-1][y]==2)
        re+=4;

    //竖
    if(((mypieces_color[x][y-1]==1&&mypieces_color[x][y+2]==0)||
        (mypieces_color[x][y-1]==0&&mypieces_color[x][y+2]==1))&&
       mypieces_color[x][y+1]==2)
        re+=4;
    else if(((mypieces_color[x][y+1]==1&&mypieces_color[x][y-2]==0)||
             (mypieces_color[x][y+1]==0&&mypieces_color[x][y-2]==1))&&
            mypieces_color[x][y-1]==2)
        re+=4;

    //正斜
    if(((mypieces_color[x-1][y-1]==1&&mypieces_color[x+2][y+2]==0)||
        (mypieces_color[x-1][y-1]==0&&mypieces_color[x+2][y+2]==1))&&
       mypieces_color[x+1][y+1]==2)
        re+=4;
    else if(((mypieces_color[x+1][y+1]==1&&mypieces_color[x-2][y-2]==0)||
             (mypieces_color[x+1][y+1]==0&&mypieces_color[x-2][y-2]==1))&&
            mypieces_color[x-1][y-1]==2)
        re+=4;

    //反斜
    if(((mypieces_color[x+1][y-1]==1&&mypieces_color[x-2][y+2]==0)||
        (mypieces_color[x+1][y-1]==0&&mypieces_color[x-2][y+2]==1))&&
       mypieces_color[x-1][y+1]==2)
        re+=4;
    else if(((mypieces_color[x-1][y+1]==1&&mypieces_color[x+2][y-2]==0)||
             (mypieces_color[x-1][y+1]==0&&mypieces_color[x+2][y-2]==1))&&
            mypieces_color[x+1][y-1]==2)
        re+=4;



    mypieces_color[x][y]=0;
    return re;
}

void white_ai::clean()
{
    for(int i=1;i<=21;i++)
        for(int j=1;j<=21;j++)
        {
            mypieces_color[i][j]=0;
        }
    mystep=0;
    update();
}

white_ai::~white_ai()
{
    delete ui;
}


