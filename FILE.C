#include<stdio.h>
#include<string.h>
struct Student {
   int score;
   char *name;

};

int main() {
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
    printf("please enter your score");
    scanf("%d",&s1[0].score);

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
       {

           if(s2[i].score>s2[j].score)
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
return(0);

}
