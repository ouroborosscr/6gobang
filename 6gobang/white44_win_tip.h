#ifndef WHITE44_WIN_TIP_H
#define WHITE44_WIN_TIP_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QPainter>
#include <QRect>
#include <QBrush>
#include <QFont>

namespace Ui {
class white44_win_tip;
}

class white44_win_tip : public QWidget
{
    Q_OBJECT

public:
    explicit white44_win_tip(QWidget *parent = nullptr);
    ~white44_win_tip();

    void paintEvent(QPaintEvent *);

    void closeEvent(QCloseEvent *event);
private:
    Ui::white44_win_tip *ui;
    QPushButton *wintip;

signals:
    void ExitWin();
};

#endif // WHITE44_WIN_TIP_H
