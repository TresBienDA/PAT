#include<stdio.h>
#include<iostream>
#define Maxsize 100
int main()
{
	int n;
	scanf("%d",&n);
	int number[Maxsize];
	int i=0;
	while(n!=0)
	{
		number[i]=n%10;
		n=n/10;
		i++;
	}
	i--;
	while(i>-1)
	{
		if(i==2)
		{
			for(int j=0;j<number[i];j++)
			{
				printf("B");
			}
		}
		if(i==1)
		{
			for(int j=0;j<number[i];j++)
			{
				printf("S");
			}
		}
		if(i==0)
		{
			for(int j=0;j<number[i];j++)
			{
				printf("%d",j+1);
			}
		}
		i--; 
	}
} 
