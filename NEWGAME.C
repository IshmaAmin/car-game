#include<graphics.h>
#include<stdio.h>
int main()
{
int gd,i,gm;
gd=DETECT;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
//background
setcolor(GREEN);
rectangle(0,0,1000,1000);
setfillstyle(1,GREEN);
floodfill(1,1,GREEN);
//track
setcolor(WHITE);
rectangle(200,-1,400,500);
setfillstyle(1,8);
floodfill(201,0,WHITE);
//track
for(i=0;i<500;i+=65)
{
rectangle(290,10+i,310,50+i);
setfillstyle(1,WHITE);
floodfill(291,11+i,WHITE);
}

//FOR LIFE AND POINTS
settextstyle(11,0,2);
outtextxy(20,20,"LIFE:");
outtextxy(20,40,"POINTS:");

 //drawing circles
 circle(90,20,6);
 setfillstyle(1,WHITE);
 floodfill(91,21,WHITE);
 circle(110,20,6);
 setfillstyle(1,WHITE);
 floodfill(111,21,WHITE);
 circle(130,20,6);
 setfillstyle(1,WHITE);
 floodfill(131,21,WHITE);

getch();
}