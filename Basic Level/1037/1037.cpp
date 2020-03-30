#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
    int G1,S1,K1;
    while(scanf("%d.%d.%d",&G1,&S1,&K1)!=EOF)
    {
        int sum1=0,sum2=0;
        int change=0;
        int G2,S2,K2;
        int Gc,Sc,Kc;
        scanf("%d.%d.%d",&G2,&S2,&K2);
        //把单位化成最小的单位 
        sum1=K1+S1*29+G1*17*29;
        sum2=K2+S2*29+G2*17*29;
        change=sum2-sum1;
        if(change<0) {
            printf("-");
            change=-change;
        }
        //类似于进制转换的思想 
        Gc=change/(17*29);
        change=change-Gc*17*29;
        Sc=change/29;
        change=change-Sc*29;
        Kc=change;
        printf("%d.%d.%d",Gc,Sc,Kc);
    }
}
