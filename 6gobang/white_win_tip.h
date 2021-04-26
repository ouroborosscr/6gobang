#ifndef WHITE_WIN_TIP_H
#define WHITE_WIN_TIP_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QPainter>
#include <QRect>
#include <QBrush>
#include <QFont>

namespace Ui {
class white_win_tip;
}

class white_win_tip : public QWidget
{
    Q_OBJECT

public:
    explicit white_win_tip(QWidget *parent = nullptr);
    ~white_win_tip();
    void paintEvent(QPaintEvent *);

    void closeEvent(QCloseEvent *event);

private:
    Ui::white_win_tip *ui;
    QPushButton *wintip;

signals:
    void ExitWin();
};

#endif // WHITE_WIN_TIP_H
