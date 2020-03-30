#include<iostream>
using namespace std;
int main()
{
    int a[10];
    int b[10];
    long long n,res;
    cin>>n;
    for(int i=0;i<10;i++)
    {
        a[i]=0;
        b[i]=0;
    }
    res=2*n;
    long long res1=n;
    long long res2=res;
    int temp;
    while(res1!=0)
    {
        temp=res1%10;
        a[temp]++;
        res1=res1/10;
    }
    while(res2!=0)
    {
        temp=res2%10;
        b[temp]++;
        res2=res2/10;
    }
    int i=0;
    for(i=1;i<10;i++)
    {
        if(a[i]!=b[i])
        {
            cout<<"No"<<endl;
            cout<<res;
            break;
        }
    }
    if(i==10) 
    {
        cout<<"Yes"<<endl;
        cout<<res;
    }
}
