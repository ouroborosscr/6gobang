#ifndef MYPORT_READY_H
#define MYPORT_READY_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QPainter>
#include <QRect>
#include <QBrush>
#include <QFont>

namespace Ui {
class myport_ready;
}

class myport_ready : public QWidget
{
    Q_OBJECT

public:
    explicit myport_ready(QWidget *parent = nullptr);
    ~myport_ready();
    void paintEvent(QPaintEvent *);

private:
    Ui::myport_ready *ui;
    QPushButton *myportready;
};

#endif // MYPORT_READY_H
