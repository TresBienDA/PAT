#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(int a,int b)
{
    if(a!=b)
    {
        return a<b;
    }
}

int main()
{
    int n,p;
    int a[100000];
    scanf("%d%d",&n,&p); 
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n,cmp);
    int max=0;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j]*p>=a[i]&&max<i-j+1)
            {
                max=i-j+1;
                break;
            }
        }
    }
    cout<<max;
}
