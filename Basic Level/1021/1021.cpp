#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string number;
    int a[10]={0,0,0,0,0,0,0,0,0,0};
    cin>>number;
    int len=number.length();
    for(int i=0;i<len;i++)
    {
        a[number[i]-'0']++;
    }
    for(int i=0;i<10;i++)
    {
        if(a[i]!=0)
        {
            cout<<i<<":"<<a[i]<<endl;
        }
    }
}
