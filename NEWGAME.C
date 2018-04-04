#include<graphics.h>
#include<stdio.h>
int main()
{
//initwindow(400,300);
int gd,i,gm;
gd=DETECT;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
int page=0,t_y=-300;
int C_x=0,M_Speed=5;

while(1){
//background
setactivepage(page);
setvisualpage(1-page);
cleardevice();
setcolor(GREEN);
rectangle(0,0,1000,1000);
setfillstyle(1,GREEN);
floodfill(1,1,GREEN);
//track
setcolor(WHITE);
rectangle(200,-1,400,500);
setfillstyle(1,8);
floodfill(201,0,WHITE);
//model for track
for(i=0;i<400;i+=65)
{
rectangle(290,10+i+t_y,310,50+i+t_y);
setfillstyle(1,WHITE);
floodfill(291,11+i+t_y,WHITE);
}
t_y+=15;
if(t_y>500)
    t_y=-500;

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

 outtextxy(100,40,"0");

 //Car
 setcolor(BLACK);
 setfillstyle(1,RED);
 rectangle(300+C_x,400,340+C_x,460);
 floodfill(301+C_x,401,BLACK);

 //Front
 setfillstyle(5,YELLOW);
 rectangle(305+C_x,385,335+C_x,400);
 floodfill(306+C_x,386,BLACK);

 //Hood

 setfillstyle(9,CYAN);
 rectangle(305+C_x,405,335+C_x,455);
 floodfill(306+C_x,406,BLACK);

 //Wheels
 setfillstyle(1,BROWN);
 pieslice(305+C_x,392,90,270,6);
 pieslice(337+C_x,392,270,90,5);

 if(GetAsyncKeyState(VK_LEFT))
    C_x-=M_Speed;
 else if(GetAsyncKeyState(VK_RIGHT))
    C_x+=M_Speed;


page=1-page;
delay(20);


}
}
