#include<stdio.h>
#include<iostream>
#define N 10000
int main()
{
	int number[N];
	int n;
	scanf("%d",&n);
	int i,j,k=0;
	int tag=0;
	int count=0; 
	for(i=2;i<n;i++)
	{
		for(j=2;j<=i/2;j++)
		{
			if(i%j==0)
			{
				tag=1;
			}
		}
		if(tag==0)
		{
			number[k]=i;
			k++;
		} else {
			tag=0;
		}
	}
	//for(int l=0;l<k;l++)
	//{
	//	printf("%d ",number[l]); 
	//}
	while(k>0)
	{
		if(number[k]-number[k-1]==2)
		{
			count++;
		}
		k--;
	} 
	printf("%d",count);
}
