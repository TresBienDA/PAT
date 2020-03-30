#include<stdio.h>
#define N 100
int main()
{
	int number[N];
	int n,m;
	int temp;
	scanf("%d%d",&n,&m);
	int i=0,j=0;
	int k,l,pos;
	for(i=0;i<n;i++)
	{
		scanf("%d",&number[i]);
	}
	if(m>=n)
	{
		m=m%n;
	}
	l=i-m;
	k=l-1;
	i--;
	while(j<k)
	{
		temp=number[j];
		number[j]=number[k];
		number[k]=temp;
		j++;
		k--;
	}
	while(l<i)
	{
		temp=number[l];//123456
		number[l]=number[i];
		number[i]=temp;//012345
		i--;
		l++;
	}
	i=0;
	pos=n-1;
	while(i<pos)
	{
		temp=number[pos];
		number[pos]=number[i];
		number[i]=temp;
		i++;
		pos--; 
	}
	printf("%d",number[0]);
	for(i=1;i<n;i++)
	printf("% d",number[i]);
}   
