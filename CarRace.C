#include<graphics.h>
#include<cstdlib>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
struct Student {
   int score;
   char *name;

};
struct Student s1[10],s2[10],a;
int rec=0;
int CreateNMoveEnemyCar(int x,int y,int moveFactor,int body,int head)
{
    setcolor(BLACK);
    rectangle(x,y+moveFactor,x+40,-50+y+moveFactor);
    setfillstyle(1,body);
    floodfill(x+1,-20+y+moveFactor-1,BLACK);

    setcolor(BLACK);
    rectangle(x+15,y+moveFactor,x+25,10+y+moveFactor);
    setfillstyle(1,head);
    floodfill(x+17,4+y+moveFactor-1,BLACK);
    return(10+y+moveFactor);
}


colors p=WHITE, q=WHITE, r1=WHITE;
int main()
{


    int gd=DETECT,gm,t=0,accident=0, flag=0,score=0,f=0,ac=0;

    char buff[1];
    int b1=8,m=10,n=4;
    int i=0;
    int j=0;
    char str[40];
    char temp[10];

    int xe1=300,xe2=200,xe3=359,xe4=260,r[8],b[8],g[8],ye[8];
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
        rectangle(290,10+i+t_y,310,50+i+t_y+m);
        setfillstyle(1,WHITE);
        floodfill(291,11+i+t_y,WHITE);

        //CreateNMoveEnemyCar(305,-50,12,RED,GREEN);
    }

    t_y+=15+m;
    if(t_y>500)
        t_y=-500;



    //for life and points
    settextstyle(10,0,2);
    outtextxy(10,10,"LIFE:");
    outtextxy(10,40,"POINTS:");
    //drawing circle for life
    setfillstyle(1,WHITE);
    circle(90,20,6);
    floodfill(91,21,p);
    circle(110,20,6);
    floodfill(111,21,q);
    circle(130,20,6);
    floodfill(131,21,r1);

    sprintf(buff,"%d",score);
    outtextxy(100,40,buff);


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

    if(t%(80-m)==0){
        score+=10;
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
     ye[0]=CreateNMoveEnemyCar(xe1,-50+m,enemyFast,COLOR(r[0],g[0],b[0]),COLOR(r[1],g[1],b[1]));
     if((ye[0]>=400 && ye[0]<=455) ||((ye[0]-10-50>=400 && ye[0]-10-50<=455) || (ye[0]-10>=400  && ye[0]-10<=455)))
    {
        if((xe1>=305+C_x && xe1<=340+C_x) ||(xe1+40>=305+C_x && xe1+40<=340+C_x))
            accident=1;
            flag++;
    }



     if (t%(200-n)==0){

        enemySlow=0;
        do{
            xe3=201+rand()%175;
        }while(xe3>xe1 && xe3<=xe1+45 && xe3>xe2 && xe3<=xe2+45  && xe3>xe4 && xe3<=xe4+45 );
        r[4]=rand()%256;
        r[5]=rand()%256;
        g[4]=rand()%256;
        g[5]=rand()%256;
        b[4]=rand()%256;
        b[5]=rand()%256;
    }
    ye[1]=CreateNMoveEnemyCar(xe3,-30+n,enemySlow,COLOR(r[4],g[4],b[4]),COLOR(r[5],g[5],b[5]));
    if((ye[1]>=400 && ye[1]<=455) ||(ye[1]-10-50>=400 && ye[1]-10-50<=455) || (ye[1]-10>=400  && ye[1]-10<=455))
    {
       // if(xe3>=305+C_x && xe3<=265+C_x)
        if((xe3>=305+C_x && xe3<=340+C_x) ||(xe3+40>=305+C_x && xe3+40<=340+C_x))
            accident=1;
            flag++;
    }

    if (t%(100-m)==0){
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
    ye[2]=CreateNMoveEnemyCar(xe4,-100+m,enemyFast-200,COLOR(r[6],g[6],b[6]),COLOR(r[7],g[7],b[7]));
    if((ye[2]>=400 && ye[2]<=455) || (ye[2]-10-50>=400 && ye[2]-10-50<=455) || (ye[2]-10>=400  && ye[2]-10<=455))
    {
        //if(xe4>=305+C_x && xe4<=340+C_x)
        if((xe4>=305+C_x && xe4<=340+C_x) ||(xe4+40>=305+C_x && xe4+40<=340+C_x))
            accident=1;
            flag++;
    }
    if (t%(130-b1)==0){
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
    ye[3]=CreateNMoveEnemyCar(xe2,-17+b1,enemyNormal,COLOR(r[2],g[2],b[2]),COLOR(r[3],g[3],b[3]));
    if((ye[3]>=400 && ye[3]<=455) ||(ye[3]-10-50>=400 && ye[3]-10-50<=455) || (ye[3]-10>=400  && ye[3]-10<=455))
    {
        //if(xe2>=305+C_x && xe2<=340+C_x)
        if((xe2>=305+C_x && xe2<=340+C_x) ||(xe2+40>=305+C_x && xe2+40<=340+C_x))
            accident=1;
            flag++;
    }

//

    enemyNormal+=b1;
    enemyFast+=m;
    enemySlow+=n;

    //printf("%d %d %d %d %d",t,enemyFast,enemyNormal,enemySlow);

    if(t%100==0){
        b1+=2;
        m+=2;
        n+=2;
        }


    if(accident==1){
        //cleardevice();
        //setcolor(BLACK);
            //settextstyle(10,0,2);
            t=0;

            enemyNormal=0;
            enemyFast=0;
            enemySlow=0;
            ac++;
            accident=0;
            //C_x=0;
            //flag=0;
            setcolor(WHITE);
            //delay(100);

        outtextxy(getmaxx()/2-100,getmaxy()/2,"You Crashed. Lost one Life");
        if(ac==01){
        p=GREEN;
        floodfill(131,21,GREEN);
        }
        else if(ac==02){
        q=GREEN;
        floodfill(111,21,GREEN);
        }
        else if(ac==03){
        r1=GREEN;
        floodfill(91,21,GREEN);
        outtextxy(getmaxx()/2-100,getmaxy()/2,"You Lost");
        delay(1000);
        //closegraph(0);

        }
       delay(1000);
       //cleardevice();
    }

   /* if(accident==1 && flag==2){
        //cleardevice();
        //setcolor(BLACK);
            //settextstyle(10,0,2);
            //t==0;
            accident=0;
            //C_x=0;
            //flag=0;
            setcolor(WHITE);
            //delay(100);

        outtextxy(getmaxx()/2-100,getmaxy()/2,"You Crashed. Lost one Life");
        q=GREEN;
        floodfill(111,21,GREEN);
       delay(1000);
    }
    if(accident==1 && flag==3){
        //cleardevice();
        //setcolor(BLACK);
            //settextstyle(10,0,2);
            //t==0;
            accident=0;
            //C_x=0;
            //flag=0;
            setcolor(WHITE);
            //delay(100);

        outtextxy(getmaxx()/2-100,getmaxy()/2,"You Crashed. Lost one Life");
        r1=GREEN;
        floodfill(91,21,GREEN);
       delay(1000);
    }*/
    t++;

    if(GetAsyncKeyState(VK_LEFT))
        if (C_x<=-110);
        else
            C_x-=M_Speed;
    else if(GetAsyncKeyState(VK_RIGHT))
        if (C_x>=70);
        else
                C_x+=M_Speed;

    if (score>=500 || ac>=3 ){
        delay(100);
            //cleardevice();
            //setbkcolor(YELLOW);
            //setcolor(WHITE);
            if (ac>=3){
                printf("\nYou Lost. Game Over\n");
               cleardevice();

            }

            else
            printf("Congratulations. You Won\n");
            delay(100);
            closegraph();

         /*   s1[1].score=score;
s1[1].name=temp;
s1[2].score=50;
s1[2].name=temp1;

s1[3].score=70;
s1[3].name=temp2;
s1[4].score=80;
s1[4].name=temp3;*/


printf("please enter your name\n");
    scanf("%s",temp);
    s1[rec].name=temp;
    s1[rec].score=score;

   /*fwrite(&s1, sizeof(s1), 1, fp);
   fclose(fp);

   fp = fopen("ip.txt", "r");
   fread(&s2, sizeof(s2), 1, fp);

   fclose(fp);

while(fgets(str, 255, (FILE*) fp)) {
    printf("%s\n",str);
    fseek(fp,0,SEEK_CUR);
}*/

printf("***LEADERBOARD***\n");
 printf("\nName\t\t\tScore\n");


int k,l;
   for(i=0;i<=rec;i++)
   {
       for(j=0;j<rec-i;j++)
       {if(s1[j].score<s1[j+1].score)
           {
               a=s1[j];
               s1[j]=s1[j+1];
               s1[j+1]=a;

           }
       }
   }
   for(k=0;k<=rec;k++)
{
printf("%s\t\t\t%d\n",s1[k].name,s1[k].score);
}
int res;
    printf("\n\n1.retry \t\t2.exit\n");
    scanf("%d",&res);
    if(res==1)
    {   system("cls");
        score=0;
        p=WHITE;
        q=WHITE;
        r1=WHITE;
        rec++;
        main();
    }
    else
    {

        exit(0);
    }

    getch();
    }




    page=1-page;
    delay(50);
    }

    getch();


}
