#include "warnin55.h"

warnin55::warnin55(QWidget *parent) : QWidget(parent)
{

}

int warnin55::myjudge(int piece_x,int piece_y,int checkerboard[22][22])
{
    if((myhorizontal(piece_x,piece_y,checkerboard)+
       myvertical(piece_x,piece_y,checkerboard)+
       myoblique1(piece_x,piece_y,checkerboard)+
       myoblique2(piece_x,piece_y,checkerboard))>=2)
       return 1;
    else
       return 0;

}


int warnin55::myhorizontal(int x,int y,int checkerboard[22][22])
{
    for(int i=1;i<=5;i++)
    {
        if((checkerboard[x-i][y]==0||checkerboard[x-i+6][y]==0)&&
           checkerboard[x-i+1][y]==1&&
           checkerboard[x-i+2][y]==1&&
           checkerboard[x-i+3][y]==1&&
           checkerboard[x-i+4][y]==1&&
           checkerboard[x-i+5][y]==1
           )
            return 1;
    }
    for(int i=1;i<=6;i++)
    {
        if(checkerboard[x-i][y]==0||checkerboard[x-i+7][y]==0)
        {
            p=0;
            for(int j=1;j<=6;j++)
            {
                if(checkerboard[x-i+j][y]==1)
                p++;
                else if(checkerboard[x-i+j][y]==2)
                {
                    p=0;
                    break;
                }
            }
            if(p==5)
            return 1;
        }
    }
    return 0;
}


int warnin55::myvertical(int x,int y,int checkerboard[22][22])
{
        for(int i=1;i<=4;i++)
        {
            if((checkerboard[x][y-i]==0||checkerboard[x][y-i+6]==0)&&
               checkerboard[x][y-i+1]==1&&
               checkerboard[x][y-i+2]==1&&
               checkerboard[x][y-i+3]==1&&
               checkerboard[x][y-i+4]==1)
                return 1;
        }
        for(int i=1;i<=5;i++)
        {
            if(checkerboard[x][y-i]==0||checkerboard[x][y-i+7]==0)
            {
                p=0;
                for(int j=1;j<=6;j++)
                {
                    if(checkerboard[x][y-i+j]==1)
                    p++;
                    else if(checkerboard[x][y-i+j]==2)
                    {
                        p=0;
                        break;
                    }

                }
                if(p==5)
                return 1;
            }
        }
        return 0;
}


int warnin55::myoblique1(int x,int y,int checkerboard[22][22])
{
        for(int i=1;i<=5;i++)
        {
            if((checkerboard[x-i][y-i]==0||checkerboard[x-i+6][y-i+6]==0)&&
               checkerboard[x-i+1][y-i+1]==1&&
               checkerboard[x-i+2][y-i+2]==1&&
               checkerboard[x-i+3][y-i+3]==1&&
               checkerboard[x-i+4][y-i+4]==1&&
               checkerboard[x-i+5][y-i+5]==1)
                return 1;
        }
        for(int i=1;i<=5;i++)
        {
            if(checkerboard[x-i][y-i]==0||checkerboard[x-i+7][y-i+7]==0)
            {
                p=0;
                for(int j=1;j<=6;j++)
                {
                    if(checkerboard[x-i+j][y-i+j]==1)
                    p++;
                    else if(checkerboard[x-i+j][y-i+j]==2)
                    {
                        p=0;
                        break;
                    }

                }
                if(p==5)
                return 1;
            }
        }
        return 0;
}

int warnin55::myoblique2(int x,int y,int checkerboard[22][22])
{
    for(int i=1;i<=5;i++)
    {
        if((checkerboard[x-i][y+i]==0||checkerboard[x-i+6][y+i-6]==0)&&
           checkerboard[x-i+1][y+i-1]==1&&
           checkerboard[x-i+2][y+i-2]==1&&
           checkerboard[x-i+3][y+i-3]==1&&
           checkerboard[x-i+4][y+i-4]==1&&
           checkerboard[x-i+5][y+i-5]==1)
            return 1;
    }
    for(int i=1;i<=6;i++)
    {
        if(checkerboard[x-i][y+i]==0&&checkerboard[x-i+7][y+i-7]==0)
        {
            p=0;
            for(int j=1;j<=5;j++)
            {
                if(checkerboard[x-i+j][y+i-j]==1)
                p++;
                else if(checkerboard[x-i+j][y+i-j]==2)
                {
                    p=0;
                    break;
                }

            }
            if(p==5)
            return 1;
        }
    }
    return 0;
}



