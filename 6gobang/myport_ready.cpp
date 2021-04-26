#include "myport_ready.h"
#include "ui_myport_ready.h"

myport_ready::myport_ready(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myport_ready)
{
    ui->setupUi(this);

    myportready= new QPushButton("确定",this);


    myportready->resize(30,20);
    myportready->move(45,40);
    setFixedSize(120,80);

    connect(myportready,&QPushButton::clicked,this,&myport_ready::close);
}

void myport_ready::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 1));
    painter.drawText(30,20,QStringLiteral("端口切换成功"));
}

myport_ready::~myport_ready()
{
    delete ui;
}
