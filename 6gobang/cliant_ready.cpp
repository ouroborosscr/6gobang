#include "cliant_ready.h"
#include "ui_cliant_ready.h"

cliant_ready::cliant_ready(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cliant_ready)
{
    ui->setupUi(this);

    cliantready= new QPushButton("确定",this);


    cliantready->resize(30,20);
    cliantready->move(45,40);
    setFixedSize(120,80);

    connect(cliantready,&QPushButton::clicked,this,&cliant_ready::close);
}

void cliant_ready::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 1));
    painter.drawText(30,20,QStringLiteral("已连接到服务端"));
}

cliant_ready::~cliant_ready()
{
    delete ui;
}
