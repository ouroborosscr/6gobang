#ifndef CLIANT_READY_H
#define CLIANT_READY_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QPainter>
#include <QRect>
#include <QBrush>
#include <QFont>

namespace Ui {
class cliant_ready;
}

class cliant_ready : public QWidget
{
    Q_OBJECT

public:
    explicit cliant_ready(QWidget *parent = nullptr);
    ~cliant_ready();
    void paintEvent(QPaintEvent *);

private:
    Ui::cliant_ready *ui;

    QPushButton *cliantready;
};

#endif // CLIANT_READY_H
