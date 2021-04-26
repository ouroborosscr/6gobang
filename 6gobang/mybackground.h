#ifndef MYBACKGROUND_H
#define MYBACKGROUND_H

#include <QWidget>
#include <QtGui>
#include <QLabel>
#include <QPushButton>
#include <windows.h>

class mybackground : public QWidget
{
    Q_OBJECT
public:
    QPushButton *btn[16][16];
    mybackground();//
    ~mybackground();
//    explicit mybackground(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent * event);
    void myframe(QPaintEvent * event);
signals:

};

#endif // MYBACKGROUND_H
