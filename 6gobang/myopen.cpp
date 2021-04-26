#include "myopen.h"
#include "ui_myopen.h"


myopen::myopen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myopen)
{
    ui->setupUi(this);
    pvpnh= new QPushButton("PvP",this);
    pvpnh->resize(80,40);
    pvpnh->move(50,300);

    pve_black=new QPushButton("PvE（先手）",this);
    pve_black->resize(80,40);
    pve_black->move(250,300);

    pve_white=new QPushButton("PvE（后手）",this);
    pve_white->resize(80,40);
    pve_white->move(150,300);

    eve=new QPushButton("EvE",this);
    eve->resize(80,40);
    eve->move(350,300);

    mycliant_white=new QPushButton("联机白（客户端）",this);
    mycliant_white->resize(80,40);
    mycliant_white->move(350,400);

    myserver_black=new QPushButton("联机黑（服务端）",this);
    myserver_black->resize(80,40);
    myserver_black->move(150,400);

    test=new QPushButton("联机（测试1）",this);
    test->resize(80,40);
    test->move(250,400);

    myserver_white=new QPushButton("联机白（服务端）",this);
    myserver_white->resize(80,40);
    myserver_white->move(150,350);

    mycliant_black=new QPushButton("联机黑（客户端）",this);
    mycliant_black->resize(80,40);
    mycliant_black->move(350,350);

    test2=new QPushButton("联机（测试2）",this);
    test2->resize(80,40);
    test2->move(250,350);

//    server=new QPushButton("联机（监视器）",this);
//    server->resize(80,40);
//    server->move(100,350);

//    test3=new QPushButton("联机（测试3）",this);
//    test3->resize(80,40);
//    test3->move(100,400);


    myquit= new QPushButton("退出",this);
    myquit->resize(80,40);
    myquit->move(450,300);
    setFixedSize(600,450);




}
void myopen::paintEvent(QPaintEvent *)
{
    QPainter painter( this);
    painter.drawPixmap(0,0,600,450,QPixmap(":new/prefix1/open.jpg"));
    qDebug()<<"open界面";

    connect(pvpnh,&QPushButton::clicked,this,&myopen::back1);
    connect(pvpnh,&QPushButton::clicked,this,&myopen::close);


    connect(pve_black,&QPushButton::clicked,this,&myopen::back2);
    connect(pve_black,&QPushButton::clicked,this,&myopen::close);

    connect(pve_white,&QPushButton::clicked,this,&myopen::back3);
    connect(pve_white,&QPushButton::clicked,this,&myopen::close);

    connect(eve,&QPushButton::clicked,this,&myopen::back4);
    connect(eve,&QPushButton::clicked,this,&myopen::close);

    connect(mycliant_white,&QPushButton::clicked,this,&myopen::back5);
    connect(mycliant_white,&QPushButton::clicked,this,&myopen::close);



    connect(myserver_black,&QPushButton::clicked,this,&myopen::back6);
    connect(myserver_black,&QPushButton::clicked,this,&myopen::close);

    connect(test,&QPushButton::clicked,this,&myopen::back7);
    connect(test,&QPushButton::clicked,this,&myopen::close);

    connect(myserver_white,&QPushButton::clicked,this,&myopen::back8);
    connect(myserver_white,&QPushButton::clicked,this,&myopen::close);


    connect(mycliant_black,&QPushButton::clicked,this,&myopen::back9);
    connect(mycliant_black,&QPushButton::clicked,this,&myopen::close);





    connect(test2,&QPushButton::clicked,this,&myopen::back10);
    connect(test2,&QPushButton::clicked,this,&myopen::close);

//    connect(server,&QPushButton::clicked,this,&myopen::back11);
//    connect(server,&QPushButton::clicked,this,&myopen::close);

//    connect(test3,&QPushButton::clicked,this,&myopen::back12);
//    connect(test3,&QPushButton::clicked,this,&myopen::close);

    connect(myquit,&QPushButton::clicked,this,&myopen::quittype);
    connect(myquit,&QPushButton::clicked,this,&myopen::close);


}

//void myopen::closeEvent(QCloseEvent *)
//{
//    if(type_judge==1)
//      emit ExitWin1();
//}

myopen::~myopen()
{
    delete ui;
}
