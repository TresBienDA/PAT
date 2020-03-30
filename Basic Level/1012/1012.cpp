#include<stdio.h>
#define Maxsize 1000
int main()
{
	int A1=0,A2=0,A3=0,A5=0;
	float A4=0;
	int N;
	int numbers[Maxsize];
	scanf("%d",&N);
	for(int i=0;i<N;i++)//¶ÁÈë²âÊÔÓÃÀý 
	{
		scanf("%d",&numbers[i]);
	}
	int i=0;
	int count2=0,count3=0;
	int tag=1,Tag=0;
	while(i<N)
	{
		switch(numbers[i]%5)
		{
			case 0:
				if(numbers[i]%2==0)
				{
					A1=A1+numbers[i];
				}
				break;
			case 1:
				if(tag==1)
				{
					A2=A2+numbers[i];
					tag=0;
					Tag=1;
				} else {
					A2=A2-numbers[i];
					tag=1;
					Tag=1;
				}
				break;
			case 2:
				count2++;
				break;
			case 3:
				A4=A4+numbers[i];
				count3++;
				break;
			case 4:
				if(numbers[i]>A5)
				{
					A5=numbers[i];
				}
				break;
		}
		i++;
	}
	if(A1!=0)
	printf("%d",A1);
	else
	printf("N") ;
	if(Tag==1)
	printf(" %d",A2);
	else
	printf(" N") ;
	printf(" %d",count2);//A3
	if(A4/count3>0)
	{
		printf(" %.1f",A4/count3);
	}
	else
	printf(" N");
	if(A5!=0)
	printf(" %d",A5);
	else
	printf(" N");
} 
