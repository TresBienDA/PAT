#include<stdio.h>
#include<iostream>
int main()
{
	int T;
	long long int A,B,C;//�������ע�⿼��ȡֵ��Χ 
	scanf("%d",&T);//������������ĸ���;
	bool Case[10];
	for(int i=0;i<T;i++)
	{
		scanf("%lld%lld%lld",&A,&B,&C);
		if(A+B>C)
		{
			Case[i]=true;
		} else {
			Case[i]=false;
		}
	} 
	for(int i=0;i<T;i++)
	{	if(Case[i]==true) 
		printf("Case #%d: true\n",i+1);
		else
		printf("Case #%d: false\n",i+1);
	}
} 
