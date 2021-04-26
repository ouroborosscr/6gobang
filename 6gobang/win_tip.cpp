#include "win_tip.h"
#include "ui_win_tip.h"

win_tip::win_tip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::win_tip)
{
    ui->setupUi(this);
    wintip= new QPushButton("确定",this);


    wintip->resize(30,20);
    wintip->move(45,40);
    setFixedSize(120,80);

    connect(wintip,&QPushButton::clicked,this,&win_tip::close);

}

void win_tip::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 1));
    painter.drawText(40,20,QStringLiteral("黑棋胜利"));
}


win_tip::~win_tip()
{
    delete ui;

}
