#include<stdio.h>
#include<iostream>
#define N 10
#define Maxsize 100
using namespace std;
int main()
{
	char answers[N][Maxsize];
	int n;
	scanf("%d",&n);
	int i,j,k,l;
	int count1=0,count2=0,count3=0;
	for(i=0;i<n;i++)
	{
		scanf("%s",answers[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;answers[i][j]!='\0';j++)
		{
			if(answers[i][j]!='A'&&answers[i][j]!='P')
			{
				printf("NO\n");
				break;
			}
			if(answers[i][j]=='P')
			{
				for(k=j+1;answers[i][k]!='T'&&answers[i][k]!='\0';k++)
				{
					if(answers[i][k]!='A')
					{
						printf("NO\n");
						break; 
					}
					else{
						count2++;	
					}
				}
				if(answers[i][k]=='T')
				{
					for(l=k+1;answers[i][l]!='\0';l++)
					{
						if(answers[i][l]!='A'){
							printf("NO\n");
							break;
						}else{
							count3++;
						}
					}
					if(count1*count2==count3&&count2!=0)
					{
						printf("YES\n");
						break;
					}else {
						printf("NO\n");
						break;
					}
				} else {
					printf("NO\n");
					break;
				}	
			}
			if(answers[i][j]='A')
			{
				count1++;
			}
		}
		count1=0;
		count2=0;
		count3=0;
	}
} 
