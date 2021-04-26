#include "draw_tip.h"
#include "ui_draw_tip.h"

draw_tip::draw_tip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::draw_tip)
{
    ui->setupUi(this);

    wintip= new QPushButton("确定",this);
    wintip->resize(30,20);
    wintip->move(45,40);
    setFixedSize(120,80);
}
void draw_tip::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 1));
    painter.drawText(40,20,QStringLiteral("双方平手"));

    connect(wintip,&QPushButton::clicked,this,&draw_tip::close);
}


void draw_tip::closeEvent(QCloseEvent *)
{
    emit ExitWin();
}

draw_tip::~draw_tip()
{
    delete ui;
    delete wintip;
}
