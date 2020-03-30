#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;

int main()
{
    int C1,C2;
    cin>>C1>>C2;
    int hh;
    int mm;
    int ss;
    float second;
    int a;
    float b;
    second=(float)(C2-C1)/100;
    cout<<second<<endl; 
    a=(int)second;
    b=second-a;
    if(b-0.5>=0)
    {
        a++;
    }
    cout<<a<<endl;
    hh=a/3600;
    a=a%3600;
    mm=a/60;
    a=a%60;
    ss=a;
    cout<<hh<<":"<<mm<<":"<<ss;
}
