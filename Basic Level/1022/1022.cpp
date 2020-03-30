#include<stdio.h>

int main()
{
    long a;
    long b;
    long c;
    int d;
    scanf("%ld%ld%d",&a,&b,&d);
    c=a+b;
    int res[100];
    int i=0;
    while(c!=0)
    {
        res[i]=c%d;
        c=c/d;
        i++;
    }
    i--;
    while(i!=-1)
    {
        printf("%d",res[i]);
        i--;
    }
}
