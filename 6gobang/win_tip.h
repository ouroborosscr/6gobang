#ifndef WIN_TIP_H
#define WIN_TIP_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QPainter>
#include <QRect>
#include <QBrush>
#include <QFont>

namespace Ui {
class win_tip;
}

class win_tip : public QWidget
{
    Q_OBJECT

public:
    explicit win_tip(QWidget *parent = nullptr);
    ~win_tip();
    void paintEvent(QPaintEvent *);

private:
    Ui::win_tip *ui;
    QPushButton *wintip;
};

#endif // WIN_TIP_H
