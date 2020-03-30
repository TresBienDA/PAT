#include<stdio.h>
#include<iostream>
using namespace std;

char Tag[3]={'W','T','L'};

float getMax(float a[])
{
    float max=a[0];
    int tag=0;
    for(int i=0;i<3;i++)
    {
        if(max<a[i])
        {
            max=a[i];
        }
    }
    return max;
}

int getTag(float a[])
{
    int max=a[0];
    int tag=0;
    int i=0;
    for(i=0;i<3;i++)
    {
        if(max<a[i])
        {
        	max=a[i]; 
            tag=i;
        }
    }
    return tag;
}

int main()
{
    float odds[3][3];
    float a,b,c;
    int taga,tagb,tagc;
    float sum;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>odds[i][j];
        }
    }
    a=getMax(odds[0]);
    taga=getTag(odds[0]);
    b=getMax(odds[1]);
    tagb=getTag(odds[1]);
    c=getMax(odds[2]);
    tagc=getTag(odds[2]);
    sum=(a*b*c*0.65-1)*2;
    cout<<Tag[taga]<<" "<<Tag[tagb]<<" "<<Tag[tagc]<<" ";
    printf("%.2f",sum);
}
