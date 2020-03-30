#include<stdio.h>
#include<iostream>
#define Maxsize 100000
using namespace std;

int main()
{
    int n;
    char A[Maxsize];//甲的出手数组
    char B[Maxsize];//乙的出手数组
    int CountA[3]={0,0,0};
    int CountB[3]={0,0,0};
    int maxA=0,maxB=0;
    int win=0,equal=0,lose=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i]>>B[i];
    }
    for(int i=0;i<n;i++)
    {
        if(A[i]==B[i])
        {
            equal++;
        }
        if(A[i]=='C'&&B[i]=='J')
        {
            CountA[1]++;
            win++;
        }
        if(A[i]=='C'&&B[i]=='B')
        {
            CountB[0]++;
            lose++;
        }
        if(A[i]=='J'&&B[i]=='C')
        {
            CountB[1]++;
            lose++;
        }
        if(A[i]=='J'&&B[i]=='B')
        {
            CountA[2]++;
            win++;
        }
        if(A[i]=='B'&&B[i]=='C')
        {
            CountA[0]++;
            win++;
        }
        if(A[i]=='B'&&B[i]=='J')
        {
            CountB[2]++;
            lose++;
        }
    }
    for(int i=0;i<3;i++)
    {
        if(CountA[maxA]<CountA[i])
        {
            maxA=i;
        }
        if(CountB[maxB]<CountB[i])
        {
            maxB=i;
        }
    }
    printf("%d %d %d\n",win,lose,equal);
    printf("%d %d %d\n",lose,win,equal);
    if(maxA==0)
    {
        printf("B");
    }
    if(maxA==1)
    {
        printf("C");
    }
    if(maxA==2)
    {
        printf("J");
    }
    printf(" ");
    if(maxB==0)
    {
        printf("B");
    }
    if(maxB==1)
    {
        printf("C");
    }
    if(maxB==2)
    {
        printf("J");
    }
}
