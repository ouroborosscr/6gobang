#include "black_win_tip.h"
#include "ui_black_win_tip.h"

black_win_tip::black_win_tip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::black_win_tip)
{
    ui->setupUi(this);
    wintip= new QPushButton("确定",this);

    wintip->resize(30,20);
    wintip->move(45,40);
    setFixedSize(120,80);
}

void black_win_tip::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 1));
    painter.drawText(40,20,QStringLiteral("黑棋胜利"));

    connect(wintip,&QPushButton::clicked,this,&black_win_tip::close);

//    connect(wintip,&QPushButton::clicked,&MainWindow,&MainWindow::close);
}

void black_win_tip::closeEvent(QCloseEvent *)
{
    emit ExitWin();
}

black_win_tip::~black_win_tip()
{
    delete ui;
    delete wintip;
}
