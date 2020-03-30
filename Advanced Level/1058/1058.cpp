#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
    int G1,S1,K1;
    while(scanf("%d.%d.%d",&G1,&S1,&K1)!=EOF)
    {
        int sum1=0,sum2=0;
        int sum=0;
        int G2,S2,K2;
        int Gs,Ss,Ks;
        scanf("%d.%d.%d",&G2,&S2,&K2);
        sum1=K1+S1*29+G1*17*29;
        sum2=K2+S2*29+G2*17*29;
        sum=sum2+sum1;
        Gs=sum/(17*29);
        sum=sum-Gs*17*29; 
        Ss=sum/29;
        sum=sum-Ss*29;
        Ks=sum;
        printf("%d.%d.%d",Gs,Ss,Ks);
    }
}
