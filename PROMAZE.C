#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <process.h>


void level1();
void l1();
void ball(int,int,int);
int c1(int,int,int,char);
void mainmenu();
void ls();


int main()
{
    int gd=DETECT,gm;
    
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    mainmenu();
    closegraph();
    return 0;
}

void level1()
{
    //maze
    //horizontal lines
    line(100,100,460,100);
    line(140,140,420,140);
    line(180,180,460,180);
    line(220,220,340,220);
    line(180,260,300,260);
    line(140,300,260,300);
    line(460,360,500,360);
    line(100,400,500,400);

    //vertical lines
    line(100,100,100,400);
    line(140,140,140,360);
    line(180,180,180,260);
    line(180,340,180,400);
    line(220,300,220,360);
    line(260,340,260,400);
    line(300,260,300,360);
    line(340,220,340,400);
    line(380,180,380,360);
    line(420,220,420,400);
    line(460,100,460,360);

    //destination
    setcolor(10);
    circle(500,380,13);
    setcolor(WHITE);
}

void ball(int x, int y, int r)
{
    circle(x,y,r);
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,14);
    floodfill(x,y,WHITE);
}

void l1()
{
    int x=120,y=120,r=10,flag=0;
    char c;
    cleardevice();
    level1();
    ball(x,y,r);
    getch();

    while(1)
    {        
        c=getch();
        if(c==75||c=='a')
        {
            do
            {
                flag=c1(x,y,r,c);
                if(flag==0)
                {
                    x-=5;
                    cleardevice();
                    level1();
                    ball(x,y,r);
                    delay(50);
                }
            } while (flag==0);
            
        }

        if(c==80||c=='s') 
        {
            do
            {
                flag=c1(x,y,r,c);
                if(flag==0)
                {
                    y+=5;
                    cleardevice();
                    level1();
                    ball(x,y,r);
                    delay(50);
                }
            } while (flag==0);
        }
            
        if(c==77||c=='d') 
        {
            do
            {
                flag=c1(x,y,r,c);
                if(flag==0)
                {
                    x+=5;
                    cleardevice();
                    level1();
                    ball(x,y,r);
                    delay(50);
                }
            } while (flag==0);
        }
        if(c==72||c=='w') 
        {
            do
            {
                flag=c1(x,y,r,c);
                if(flag==0)
                {
                    y-=5;
                    cleardevice();
                    level1();
                    ball(x,y,r);
                    delay(50);
                }
            } while (flag==0);
        } 

        if(flag==2)
        {
            cleardevice();
	    outtextxy(100,200,"CONGRATS !!!    YOU COMPLETED THE LEVEL.....");
            getch();
            break;
        }            
        
        delay(50);
    }
}

int c1(int x, int y, int r, char c)
{
    //left
    if(c==75 || c=='a')
    {
        if(getpixel(x-r-3,y)==10)
            return 2;
        if(getpixel(x-r,y)==getpixel(x-r-10,y))
            return 1;
        else 
            return 0;
    }

    //down
    if(c==80 || c=='s')
    {
        if(getpixel(x,y+r+3)==10)
            return 2;
        if(getpixel(x,y+r)==getpixel(x,y+r+10))
            return 1;
        else 
            return 0;
    }

    //right
    if(c==77 || c=='d')
    {
        if(getpixel(x+r+3,y)==10)
            return 2;
        if(getpixel(x+r,y)==getpixel(x+r+10,y))
            return 1;
        else 
            return 0;
    }

    //up
    if(c==72 || c=='w')
    {
        if( getpixel(x,y-r-3)==10)
            return 2;
        if(getpixel(x,y-r)==getpixel(x,y-r-10))
            return 1;
        else 
            return 0;
    }

    //if reached destination
    if(getpixel(x-r-3,y)==10 && getpixel(x+r+3,y)==10 && getpixel(x,y-r-3)==10 && getpixel(x,y+r+3)==10)
    {
        return 2;
    }

    return 0;
}

void mainmenu()
{
    int x,w;
    x=getmaxx();
    cleardevice();
    settextstyle(BOLD_FONT,HORIZ_DIR,3);
    setcolor(BLUE);
    outtextxy(190,20,"MAZE RUNNER");
    settextstyle(0,HORIZ_DIR,0);
    line(0,80,x,80);
    setcolor(WHITE);
    
    w=textwidth("1. PLAY MAZE RUNNER");
    outtextxy(x/2-w/2,150,"1. PLAY MAZE RUNNER");
    w=textwidth("2. SELECT LEVEL");
    outtextxy(x/2-w/2,200,"2. SELECT LEVEL");
    w=textwidth("3. EXIT");
    outtextxy(x/2-w/2,250,"3. EXIT");

    outtextxy(100,300,"ENTER YOUR CHOICE :      ");
    switch(getch())
    {
	    case '1': l1();
                break;

        case '2': ls();
                break;

        case '3': exit(0);
                break;

        default : outtextxy(100,350,"INVALID CHOICE !!!");
                  outtextxy(100,365,"Press Any Key To Continue.....");
                  getch();
                  mainmenu();   
    }

    getch();
}

void ls()
{
    int x;
    x=getmaxx();
    cleardevice();
    settextstyle(BOLD_FONT,HORIZ_DIR,2);
    setcolor(BLUE);
    outtextxy(190,20,"EVEL SELECT");
    settextstyle(0,HORIZ_DIR,0);
    line(0,80,x,80);
    setcolor(WHITE);

    outtextxy(150,200,"LEVEL 1");
    outtextxy(150,250,"2. BACK");

    outtextxy(150,300,"SELECT LEVEL :     ");

    switch(getch())
    {
        case '1': l1();
                break;

        case '2': mainmenu();
                break;
        
        default : outtextxy(100,350,"INVALID LEVEL !!!");
                  outtextxy(100,365,"Press Any Key To Continue.....");
                  getch();
                  ls();
    }
}
