#include<stdio.h>
#include<iostream>
#define Maxsize 100
using namespace std;
int main()
{
	char number[Maxsize];
	int digit[Maxsize];
	int i=0;
	int top=-1;
	int sum=0;
	char x;
	scanf("%s",number);
	for(i=0;number[i]!='\0';i++)
	{
		sum=sum+(number[i]-'0');
	}
	while(sum!=0)
	{
		digit[++top]=sum%10;
		sum=sum/10;
	}
	while(top!=-1)
	{
		switch(digit[top])
		{
			case 0:
            printf("ling");
            break;
            case 1:
            printf("yi");
            break;
            case 2:
            printf("er");
            break;
            case 3:
            printf("san");
            break;
            case 4:
            printf("si");
            break;
            case 5:
            printf("wu");
            break;
            case 6:
            printf("liu");
            break;
            case 7:
            printf("qi");
            break;
            case 8:
            printf("ba");
            break;
            case 9:
            printf("jiu");
            break;
        }
        if(top!=0)
        {
        	cout<<" ";
        }
        top--;
	} 
} 
