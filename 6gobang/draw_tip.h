#ifndef DRAW_TIP_H
#define DRAW_TIP_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QRect>
#include <QBrush>
#include <QFont>

namespace Ui {
class draw_tip;
}

class draw_tip : public QWidget
{
    Q_OBJECT

public:
    explicit draw_tip(QWidget *parent = nullptr);
    ~draw_tip();
    void paintEvent(QPaintEvent *);
    void closeEvent(QCloseEvent *event);

private:
    Ui::draw_tip *ui;
    QPushButton *wintip;
signals:
    void ExitWin();
};

#endif // DRAW_TIP_H
