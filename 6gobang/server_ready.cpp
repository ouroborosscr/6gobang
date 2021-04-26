#include "server_ready.h"
#include "ui_server_ready.h"

server_ready::server_ready(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::server_ready)
{
    ui->setupUi(this);

    serverready= new QPushButton("确定",this);


    serverready->resize(30,20);
    serverready->move(45,40);
    setFixedSize(120,80);

    connect(serverready,&QPushButton::clicked,this,&server_ready::close);
}

void server_ready::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 1));
    painter.drawText(30,20,QStringLiteral("已连接到客户端"));
}

server_ready::~server_ready()
{
    delete ui;
}
