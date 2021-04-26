#ifndef WHITE55_WIN_TIP_H
#define WHITE55_WIN_TIP_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QPainter>
#include <QRect>
#include <QBrush>
#include <QFont>

namespace Ui {
class white55_win_tip;
}

class white55_win_tip : public QWidget
{
    Q_OBJECT

public:
    explicit white55_win_tip(QWidget *parent = nullptr);
    ~white55_win_tip();

    void paintEvent(QPaintEvent *);

    void closeEvent(QCloseEvent *event);

private:
    Ui::white55_win_tip *ui;

    QPushButton *wintip;

signals:
    void ExitWin();
};

#endif // WHITE55_WIN_TIP_H
