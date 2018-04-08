
#include<graphics.h>
#include<cstdlib>
#include<stdio.h>
#include<windows.h>
struct Student {
   int score;
   char *name;

};
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
    int gd=DETECT,gm,t=0,c=0,sc=100;
    int xe1=305,xe2=200,xe3=350,xe4=250,r[8],b[8],g[8];
    struct Student s1[10],s2[10],a;
   FILE *fp;
   int i;
   int j;
   char str[40];
   char temp[]="riya";
   char temp1[]="priya";
   char temp2[]="ajay";
char temp3[]="abhay";
char temp4[10];
   fp = fopen("ip.txt", "w");
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

    CreateNMoveEnemyCar(xe1,-50,enemyFast,RED,BLUE);

    CreateNMoveEnemyCar(xe3,-30,enemySlow,BLUE,RED);
    CreateNMoveEnemyCar(xe4,-100,enemyFast-200,YELLOW,BLACK);
    CreateNMoveEnemyCar(xe2,-17,enemyNormal,BLACK,YELLOW);


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
if(GetAsyncKeyState(VK_RETURN))
   {
    closegraph();

    break;
   }

    }
outtextxy(100,100,"enter your name");

s1[1].score=45;
s1[1].name=temp;
s1[2].score=50;
s1[2].name=temp1;

s1[3].score=70;
s1[3].name=temp2;
s1[4].score=80;
s1[4].name=temp3;

printf("please enter your name");
    scanf("%s",temp4);
    s1[0].name=temp4;

    s1[0].score=sc;

   fwrite(&s1, sizeof(s1), 1, fp);
   fclose(fp);

   fp = fopen("ip.txt", "r");
   fread(&s2, sizeof(s2), 1, fp);

   fclose(fp);

while(fgets(str, 255, (FILE*) fp)) {
    printf("%s\n",str);
    fseek(fp,0,SEEK_CUR);
}

printf("***LEADERBOARD***\n");
 printf("\nName\t\t\tScore\n");



   for(i=0;i<=4;i++)
   {
       for(j=i;j<=4;j++)
       {if(s2[i].score>s2[j].score)
           {
               a=s2[i];
               s2[i]=s2[j];
               s2[j]=a;

           }
       }
   }
   for(i=0;i<=4;i++)
{
printf("%s\t\t\t%d\n",s2[i].name,s2[i].score);
}
    printf("\n\n1.retry \t\t2.exit");
    scanf("%d %d",&t);
    if(t==1)
    {


    }
    else
    {

        exit(0);
    }
}
