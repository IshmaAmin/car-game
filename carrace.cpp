#include<graphics.h>
#include<cstdlib>
void CreateNMoveEnemyCar(int x,int y,int moveFactor,int body,int head)
{
    setcolor(BLACK);
    rectangle(x,y+moveFactor,x+40,-50+y+moveFactor);
    setfillstyle(1,body);
    floodfill(x+1,-20+y+moveFactor-1,BLACK);

    setcolor(BLACK);
    rectangle(x+15,y+moveFactor,x+25,10+y+moveFactor);
    setfillstyle(1,head);
    floodfill(x+17,4+y+moveFactor-1,BLACK);

}
int main()
{
    int gd=DETECT,gm,t=0;
    int xe1=305,xe2=200,xe3=350,xe4=250,r[8],b[8],g[8];
    initgraph(&gd,&gm,"c:\\turboc3\\bgi");
    int page=0,t_y=-300;
    //car variables
    int C_x=0,M_Speed=5;
    int enemyNormal=0,enemyFast=0,enemySlow=0;
    while(1)
    {
    setactivepage(page);
    setvisualpage(1-page);
    cleardevice();



    //for background
    setcolor(GREEN);
    rectangle(0,0,1000,1000);
    setfillstyle(1,GREEN);
    floodfill(1,1,GREEN);
    //creating track
    setcolor(WHITE);
    rectangle(200,-1,400,500);
    setfillstyle(1,8);
    floodfill(201,0,WHITE);
    //line in roads
    for(int i=0;i<450;i+=105)
    {
        rectangle(290,10+i+t_y,310,50+i+t_y);
        setfillstyle(1,WHITE);
        floodfill(291,11+i+t_y,WHITE);

        //CreateNMoveEnemyCar(305,-50,12,RED,GREEN);
    }

    t_y+=15;
    if(t_y>500)
        t_y=-500;


    //for life and points
    settextstyle(10,0,2);
    outtextxy(10,10,"LIFE:");
    outtextxy(10,40,"POINTS:");
    //drawing circle for life
    setfillstyle(1,WHITE);
    circle(90,20,6);
    floodfill(91,21,WHITE);
    circle(110,20,6);
    floodfill(111,21,WHITE);
    circle(130,20,6);
    floodfill(131,21,WHITE);

    outtextxy(100,40,"0");


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


    //enemyCar

    if(t%80==0){
        enemyFast=0;
        do{
            xe1=201+rand()%175;
        }while(xe1>xe2 && xe1<=xe2+45  && xe1>xe3 && xe1<=xe3+45  && xe1>xe4 && xe1<=xe4+45 );
        r[0]=rand()%256;
        r[1]=rand()%256;
        g[0]=rand()%256;
        g[1]=rand()%256;
        b[0]=rand()%256;
        b[1]=rand()%256;
    }
     if (t%200==0){
        enemySlow=0;
        do{
            xe3=201+rand()%175;
        }while(xe3>xe1 && xe3<=xe1+45 && xe3>xe2 && xe3<=xe2+45  && xe3>xe4 && xe3<=xe4+45 );
        r[4]=rand()%256;
        r[5]=rand()%256;
        g[4]=rand()%256;
        g[5]=rand()%256;
        b[4]=rand()%1256;
        b[5]=rand()%256;
    }
    if (t%100==0){
        //enemyFast=0;
        do{
            xe4=201+rand()%175;
        }while(xe4>xe1 && xe4<=xe1+45 && xe4>xe2 && xe4<=xe2+45 && xe4>xe3 && xe4<=xe3+45);
        r[6]=rand()%256;
        r[7]=rand()%256;
        g[6]=rand()%256;
        g[7]=rand()%256;
        b[6]=rand()%256;
        b[7]=rand()%256;
    }
    if (t%130==0){
        enemyNormal=0;
        do{
            xe2=201+rand()%175;
        }while(xe2>xe1 && xe2<=xe1+45 && xe2>xe3 && xe2<=xe3+45  && xe2>xe4 && xe2<=xe4+45 );
        r[2]=rand()%256;
        r[3]=rand()%256;
        g[2]=rand()%256;
        g[3]=rand()%256;
        b[2]=rand()%256;
        b[3]=rand()%256;
    }


    CreateNMoveEnemyCar(xe1,-50,enemyFast,COLOR(r[0],g[0],b[0]),COLOR(r[1],g[1],b[1]));

    CreateNMoveEnemyCar(xe3,-30,enemySlow,COLOR(r[4],g[4],b[4]),COLOR(r[5],g[5],b[5]));
    CreateNMoveEnemyCar(xe4,-100,enemyFast-200,COLOR(r[6],g[6],b[6]),COLOR(r[7],g[7],b[7]));
    CreateNMoveEnemyCar(xe2,-17,enemyNormal,COLOR(r[2],g[2],b[2]),COLOR(r[3],g[3],b[3]));


//
    enemyNormal+=8;
    enemyFast+=10;
    enemySlow+=4;
    t++;



    if(GetAsyncKeyState(VK_LEFT))
        C_x-=M_Speed;
    else if(GetAsyncKeyState(VK_RIGHT))
        C_x+=M_Speed;

    page=1-page;
    delay(50);
    }

    getch();

}
