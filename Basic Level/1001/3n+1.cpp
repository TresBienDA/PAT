#include<stdio.h>
int main()
{
       int count=0;
       int n;
       scanf("%d",&n);
    if(n>0&&n<=1000){
    while(n!=1)
    {
        if(n%2==0)
        {
            n=n/2;
            count++;
        }
        if(n%2!=0&&n!=1)
        {
            n=3*n+1;
            n=n/2;
            count++;
        }
    }
    printf("%d\n",count);
    }
    return 0;
}
