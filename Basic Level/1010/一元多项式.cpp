#include<stdio.h>
#define Maxsize 10000
int main()
{
    int i;
    int n;
    int k;
    int a[Maxsize];
    for(i=0;i<Maxsize;i++)
    {
        a[i]=0;
    }
    while(i!=0)
    {
        scanf("%d",&n);
        scanf("%d",&i);
        a[i]=n;
    }
    for(i=0;i<Maxsize;i++)
    {
        if(a[i]==0);
        if(a[i]!=0)
        {
            if(i-1>=0)
            {
                k=a[i]*i;
                a[i-1]=a[i-1]+k;
                a[i]=0;
            }
            else
            {
                a[i]=0;
            }
        }
    }
    i=i-1;
    while(i>0&&a[i]==0)
	{
		i--;
	}
	printf("%d",a[i]);
	printf("% d",i);
	while(i>0)
	{
		i--;
		if(a[i]!=0)
		{
			printf("% d",a[i]);
			printf("% d",i);
		}
	}
	return 0;
}
