#ifndef BLACK_WIN_TIP_H
#define BLACK_WIN_TIP_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QPainter>
#include <QRect>
#include <QBrush>
#include <QFont>

namespace Ui {
class black_win_tip;
}

class black_win_tip : public QWidget
{
    Q_OBJECT

public:
    explicit black_win_tip(QWidget *parent = nullptr);
    ~black_win_tip();
    void paintEvent(QPaintEvent *);
    void closeEvent(QCloseEvent *event);

private:
    Ui::black_win_tip *ui;
    QPushButton *wintip;

signals:
    void ExitWin();
};

#endif // BLACK_WIN_TIP_H
