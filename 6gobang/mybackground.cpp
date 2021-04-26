#include "mybackground.h"

mybackground::mybackground()
//mybackground::mybackground(QWidget *parent) : QWidget(parent)
{

}

void mybackground::paintEvent(QPaintEvent * event)
{
    QPainter painter( this);



    for(int i=1;i<=15;i++)
        for(int j=1;j<=15;j++)
        {
            btn[i][j]=new QPushButton(this);
        }


    //背景图片：
    painter.drawPixmap(0,0,500,350,QPixmap(":new/prefix1/1616672385673.png"));

//    Q_UNUSED(event);

    //边框：
    // 反走样
    painter.setRenderHint(QPainter::Antialiasing, true);
    // 设置画笔颜色、宽度
    painter.setPen(QPen(Qt::black, 2));
    // 设置画刷颜色
//    painter.setBrush(QColor(255, 160, 90));
    painter.drawRect(20, 20, 300, 300);

    //线：
    painter.setPen(QPen(Qt::black, 1));

    for(float i=40;i<=318;i+=21.4)
    {
        painter.drawLine(QPointF(20, i),QPointF(320,i ));
    }

    for(float i=40;i<=318;i+=21.4)
    {
        painter.drawLine(QPointF(i, 20),QPointF(i,320));
    }

    //点：
    painter.setPen(QPen(Qt::black, 4));
    painter.setBrush(Qt::black);
    painter.drawEllipse(QPointF(82.8, 82.8),1,1);
    painter.drawEllipse(QPointF(82.8, 254),1,1);
    painter.drawEllipse(QPointF(254, 82.8),1,1);
    painter.drawEllipse(QPointF(254, 254),1,1);
    painter.drawEllipse(QPointF(168.4, 168.4),1,1);





//     //尝试部署225个按钮
//    int piece_place[16]={0,13,33,54,76,97,119,140,161,182,204,225,247,268,290,313}; //横纵坐标

//    QPushButton *btn[16][16];


//            //=new QPushButton(this);

//    for(int i=1;i<=15;i++)
//        for(int j=1;j<=15;j++)
//        {
//            btn[i][j]=new QPushButton(this);
//            btn[i][j]->setStyleSheet(QString("QPushButton{background-color:rgba(0,0,0,0);border-width:0px;border-radius:7;} QPushButton:hover{background-color:rgba(255,255,255,0.5);border-width:0px;}"));
//            btn[i][j]->setGeometry(piece_place[i],piece_place[j],14,14);
//            btn[i][j]->show();
//        }




//    btn=new QPushButton(this);
//    btn->setStyleSheet(QString("QPushButton{background-color:rgba(0,0,0,1);border-width:0px;border-radius:7;} QPushButton:hover{background-color:rgba(255,255,255,0.5);border-width:0px;}"));
//    btn->setGeometry(13,161,14,14);
//    btn->show();

//            btn=new QPushButton(this);
//            btn->setStyleSheet(QString("QPushButton{background-color:rgba(0,0,0,1);border-width:0px;border-radius:7;} QPushButton:hover{background-color:rgba(255,255,255,0.5);border-width:0px;}"));
//            btn->setGeometry(33,161,14,14);
//            btn->show();

//            btn=new QPushButton(this);
//            btn->setStyleSheet(QString("QPushButton{background-color:rgba(0,0,0,1);border-width:0px;border-radius:7;} QPushButton:hover{background-color:rgba(255,255,255,0.5);border-width:0px;}"));
//            btn->setGeometry(54,161,14,14);
//            btn->show();

//            btn=new QPushButton(this);
//            btn->setStyleSheet(QString("QPushButton{background-color:rgba(0,0,0,1);border-width:0px;border-radius:7;} QPushButton:hover{background-color:rgba(255,255,255,0.5);border-width:0px;}"));
//            btn->setGeometry(76,161,14,14);
//            btn->show();

//            btn=new QPushButton(this);
//            btn->setStyleSheet(QString("QPushButton{background-color:rgba(0,0,0,1);border-width:0px;border-radius:7;} QPushButton:hover{background-color:rgba(255,255,255,0.5);border-width:0px;}"));
//            btn->setGeometry(97,161,14,14);
//            btn->show();

//            btn=new QPushButton(this);
//            btn->setStyleSheet(QString("QPushButton{background-color:rgba(0,0,0,1);border-width:0px;border-radius:7;} QPushButton:hover{background-color:rgba(255,255,255,0.5);border-width:0px;}"));
//            btn->setGeometry(119,161,14,14);
//            btn->show();

//            btn=new QPushButton(this);
//            btn->setStyleSheet(QString("QPushButton{background-color:rgba(0,0,0,1);border-width:0px;border-radius:7;} QPushButton:hover{background-color:rgba(255,255,255,0.5);border-width:0px;}"));
//            btn->setGeometry(140,161,14,14);
//            btn->show();

//            btn=new QPushButton(this);
//            btn->setStyleSheet(QString("QPushButton{background-color:rgba(0,0,255,1);border-width:0px;border-radius:7;} QPushButton:hover{background-color:rgba(255,255,255,0.5);border-width:0px;}"));
//            btn->setGeometry(161,161,14,14);
//            btn->show();// 中

//            btn=new QPushButton(this);
//            btn->setStyleSheet(QString("QPushButton{background-color:rgba(0,0,0,1);border-width:0px;border-radius:7;} QPushButton:hover{background-color:rgba(255,255,255,0.5);border-width:0px;}"));
//            btn->setGeometry(182,161,14,14);
//            btn->show();

//            btn=new QPushButton(this);
//            btn->setStyleSheet(QString("QPushButton{background-color:rgba(0,0,0,1);border-width:0px;border-radius:7;} QPushButton:hover{background-color:rgba(255,255,255,0.5);border-width:0px;}"));
//            btn->setGeometry(204,161,14,14);
//            btn->show();

//            btn=new QPushButton(this);
//            btn->setStyleSheet(QString("QPushButton{background-color:rgba(0,0,0,1);border-width:0px;border-radius:7;} QPushButton:hover{background-color:rgba(255,255,255,0.5);border-width:0px;}"));
//            btn->setGeometry(225,161,14,14);
//            btn->show();

//            btn=new QPushButton(this);
//            btn->setStyleSheet(QString("QPushButton{background-color:rgba(0,0,0,1);border-width:0px;border-radius:7;} QPushButton:hover{background-color:rgba(255,255,255,0.5);border-width:0px;}"));
//            btn->setGeometry(247,161,14,14);
//            btn->show();

//            btn=new QPushButton(this);
//            btn->setStyleSheet(QString("QPushButton{background-color:rgba(0,0,0,1);border-width:0px;border-radius:7;} QPushButton:hover{background-color:rgba(255,255,255,0.5);border-width:0px;}"));
//            btn->setGeometry(268,161,14,14);
//            btn->show();

//            btn=new QPushButton(this);
//            btn->setStyleSheet(QString("QPushButton{background-color:rgba(0,0,0,1);border-width:0px;border-radius:7;} QPushButton:hover{background-color:rgba(255,255,255,0.5);border-width:0px;}"));
//            btn->setGeometry(290,161,14,14);
//            btn->show();

//            btn=new QPushButton(this);
//            btn->setStyleSheet(QString("QPushButton{background-color:rgba(0,0,0,1);border-width:0px;border-radius:7;} QPushButton:hover{background-color:rgba(255,255,255,0.5);border-width:0px;}"));
//            btn->setGeometry(313,161,14,14);
//            btn->show();




    //按钮：
//    QPushButton *btn=new QPushButton(this);
//    btn->setStyleSheet(QString("QPushButton{background-color:rgba(255,0,0,0);border-width:0px;border-radius:9;} QPushButton:hover{background-color:rgba(255,255,255,0.5);border-width:0px;}"));
//    btn->setGeometry(179,159,20,20);//按钮位置，大小

//    btn->show();//白
//    //btn->setEnabled(false);

//    btn=new QPushButton(this);
//    btn->setStyleSheet(QString("QPushButton{background-color:rgba(255,0,0,0);border-width:0px;border-radius:9;} QPushButton:hover{background-color:rgba(0,0,0,0.5);border-width:0px;}"));
//    btn->setGeometry(159,159,20,20);//按钮位置，大小
//    //btn->setEnabled(true);
//    btn->show();//黑
//    //btn->setEnabled(false);//按钮开关， false是关，true是开，用来确保重叠按钮开关问题，可以刷新，但是要考虑覆盖问题，不过反正重新show过，也可以每次都用setbackground-color，改颜色
//    //按下以后可以重写一个不透明的按钮
}

mybackground::~mybackground()
{
    for(int i=1;i<=15;i++)
        for(int j=1;j<=15;j++)
        {
            delete btn[i][j];
        }
}



