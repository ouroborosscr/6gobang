#ifndef SERVER_READY_H
#define SERVER_READY_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QPainter>
#include <QRect>
#include <QBrush>
#include <QFont>


namespace Ui {
class server_ready;
}

class server_ready : public QWidget
{
    Q_OBJECT

public:
    explicit server_ready(QWidget *parent = nullptr);
    ~server_ready();
    void paintEvent(QPaintEvent *);


private:
    Ui::server_ready *ui;

    QPushButton *serverready;
};

#endif // SERVER_READY_H
