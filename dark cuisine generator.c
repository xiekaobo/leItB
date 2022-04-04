#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct food
{
    char str[20]; //name
    int no;  //number
}a[100]={{" ",0}};  //initialize

int Get_Foodbank(food *a)
{
    FILE *fp;
    char ch;
    int i,n=0,choice,who;
    fp=fopen("food.txt","r");
    if(fp==NULL)
    {
        printf("can not open the file\n");
        return 1;
    }
    while((ch=fgetc(fp))!=EOF)
    {
        if(ch=='\n')n++; //size
    }  
    rewind(fp);
    for(i=0;i<n;i++)
    {
        a[i].no=i; //num
        fscanf(fp,"%s\n",a[i].str);
    }
    fclose(fp);
    return n;
}

int Generate_dishes(food *a,int n)
{
	int who=0;
    srand(time(NULL));
    for(int i=1;i<n;i++)
    {
            who=rand()%n+1;
            printf("%s",a[who].str);
            printf("_with_");
            who=rand()%n+1;
            puts(a[who].str);
    }
    return 0;
}


int main()
{
	int n=Get_Foodbank(a);
	Generate_dishes(a,n);
	return 0;
}
