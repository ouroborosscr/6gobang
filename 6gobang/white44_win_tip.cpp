#include "white44_win_tip.h"
#include "ui_white44_win_tip.h"

white44_win_tip::white44_win_tip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::white44_win_tip)
{
    ui->setupUi(this);

    wintip= new QPushButton("确定",this);


    wintip->resize(30,20);
    wintip->move(45,40);
    setFixedSize(120,80);
}

void white44_win_tip::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 1));
    painter.drawText(40,15,QStringLiteral("四四禁手"));
    painter.drawText(40,25,QStringLiteral("白棋胜利"));

    connect(wintip,&QPushButton::clicked,this,&white44_win_tip::close);
}

void white44_win_tip::closeEvent(QCloseEvent *)
{
    emit ExitWin();
}

white44_win_tip::~white44_win_tip()
{
    delete ui;
}
