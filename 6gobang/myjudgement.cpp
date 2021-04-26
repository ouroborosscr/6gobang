#include "myjudgement.h"

myjudgement::myjudgement(QWidget *parent) : QWidget(parent)
{

}



int myjudgement::myjudge(int color,int piece_x,int piece_y,int checkerboard[22][22])
{
    if(piece_x<=5)
        x_borderf=1;
    else
        x_borderf=piece_x-5;
    if(piece_x>=16)
        x_borderl=21;
    else
        x_borderl=piece_x+5;

    if(piece_y<=5)
        y_borderf=1;
    else
        y_borderf=piece_y-5;
    if(piece_y>=16)
        y_borderl=21;
    else
        y_borderl=piece_y+5;

    for(int i=x_borderf;i<=x_borderl;i++)
        for(int j=y_borderf;j<=y_borderl;j++)
            {
                if(i<=16)
                {
                    winjudge=myhorizontal(color,i,j,checkerboard);
                    if(winjudge!=0)
                    {
                        qDebug()<<"win:"<<winjudge;
                        return 1;
                        break;//或者直接跳转胜利弹窗
                    }
                }
                if(j<=16)
                {
                    winjudge=myvertical(color,i,j,checkerboard);
                    if(winjudge!=0)
                    {
                        qDebug()<<"win:"<<winjudge;
                        return 1;
                        break;//或者直接跳转胜利弹窗
                    }
                }
                if(i<=16&&j<=16)
                {
                    winjudge=myoblique1(color,i,j,checkerboard);
                    if(winjudge!=0)
                    {
                        qDebug()<<"win:"<<winjudge;
                        return 1;
                        break;//或者直接跳转胜利弹窗
                    }
                    winjudge=myoblique2(color,i,j,checkerboard);
                    if(winjudge!=0)
                    {
                        qDebug()<<"win:"<<winjudge;
                        return 1;
                        break;//或者直接跳转胜利弹窗
                    }
                }

            }
    if(winjudge!=0)
        return 1;
    else
        return 0;

}

int myjudgement::myhorizontal(int color,int x,int y,int checkerboard[22][22])
{
    for(int i=x;i<=x+5;i++)
    {
        if(checkerboard[i][y]!=color)
            return 0;
    }
    return 1;

}

int myjudgement::myvertical(int color,int x,int y,int checkerboard[22][22])
{
    for(int j=y;j<=y+5;j++)
    {
        if(checkerboard[x][j]!=color)
            return 0;
    }
    return 1;

}

int myjudgement::myoblique1(int color,int x,int y,int checkerboard[22][22])
{
    for(int i=x,j=y;i<=x+5;i++,j++)
    {
        if(checkerboard[i][j]!=color)
            return 0;
    }
    return 1;

}

int myjudgement::myoblique2(int color,int x,int y,int checkerboard[22][22])
{
    for(int i=x,j=y+5;i<=x+5;i++,j--)
    {
        if(checkerboard[i][j]!=color)
            return 0;
    }
    return 1;

}
