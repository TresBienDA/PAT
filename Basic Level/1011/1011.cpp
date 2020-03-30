#include<stdio.h>
#include<iostream>
int main()
{
	int T;
	long long int A,B,C;//定义变量注意考虑取值范围 
	scanf("%d",&T);//读入测试用例的个数;
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
