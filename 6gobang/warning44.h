#ifndef WARNING44_H
#define WARNING44_H

#include <QWidget>
#include <QDebug>
#include "mainwindow.h"

class warning44 : public QWidget
{
    Q_OBJECT
private:
    int p;
public:
    explicit warning44(QWidget *parent = nullptr);
    int myjudge(int piece_x,int piece_y,int checkerboard[22][22]);
    int myhorizontal(int x,int y,int checkerboard[22][22]); //横
    int myvertical(int x,int y,int checkerboard[22][22]);//竖
    int myoblique1(int x,int y,int checkerboard[22][22]);//正斜
    int myoblique2(int x,int y,int checkerboard[22][22]);//反斜
signals:

};

#endif // WARNING44_H
