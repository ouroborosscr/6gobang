#ifndef WARNIN55_H
#define WARNIN55_H

#include <QWidget>
#include <QDebug>
#include "mainwindow.h"

class warnin55 : public QWidget
{
    Q_OBJECT
private:
    int p;
public:
    explicit warnin55(QWidget *parent = nullptr);
    int myjudge(int piece_x,int piece_y,int checkerboard[22][22]);
    int myhorizontal(int x,int y,int checkerboard[22][22]); //横
    int myvertical(int x,int y,int checkerboard[22][22]);//竖
    int myoblique1(int x,int y,int checkerboard[22][22]);//正斜
    int myoblique2(int x,int y,int checkerboard[22][22]);//反斜
signals:

};

#endif // WARNIN55_H
