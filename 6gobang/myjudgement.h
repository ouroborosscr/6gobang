#ifndef MYJUDGEMENT_H
#define MYJUDGEMENT_H

#include <QWidget>
#include <QDebug>
#include "mainwindow.h"

class myjudgement : public QWidget
{
    Q_OBJECT
private:
    int winjudge=0;//1-black; 2-white
    int x_borderf,x_borderl,y_borderf,y_borderl;
public:
    explicit myjudgement(QWidget *parent = nullptr);
    int myjudge(int color,int piece_x,int piece_y,int checkerboard[22][22]);

    int myhorizontal(int color,int x,int y,int checkerboard[22][22]); //横
    int myvertical(int color,int x,int y,int checkerboard[22][22]);//竖
    int myoblique1(int color,int x,int y,int checkerboard[22][22]);//正斜
    int myoblique2(int color,int x,int y,int checkerboard[22][22]);//反斜

signals:

};

#endif // MYJUDGEMENT_H
