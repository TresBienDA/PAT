#include<stdio.h>
#define Maxsize 100
int main()
{
    int a[Maxsize];
    int k;
    int n;
    int i,j;
    for(i=0;i<Maxsize;i++)
    {
        a[i]=0;
    }
    scanf("%d",&k);
    if(k==0)
    return 0;
    for(i=0;i<k;i++)
    {
        scanf("%d",&n);
        a[n]=1;
    }
    for(i=0;i<Maxsize;i++)
    {
        if(a[i]==1){
            j=i;
            while(j!=1)
            {
                if(j%2==0)
                {
                    j=j/2;
                    if(j<100)
                    {
                        a[j]=0;
                    }
                }
                if(j%2!=0&&j!=1)
                {
                    j=j*3+1;
                    j=j/2;
                    if(j<100)
                    {
                        a[j]=0;
                    }
                }
            }
        }
    }
    i--;
    while(i>0&&a[i]==0)
    {
        i--;
    }
    printf("%d",i);
    while(i>0)
    {
        i--;
        if(a[i]!=0)
        {
            printf("% d",i);
        }
    }
    return 0;

}
