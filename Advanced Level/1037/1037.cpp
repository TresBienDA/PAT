#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    long long C[100000];
    long long P[100000];
    int m,n;
    long long money=0;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>C[i];
    }
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>P[i];
    }
    sort(C,C+m);
    sort(P,P+n);
    int i=0,j=0;
    while(i<m&&j<n&&C[i]<0&&P[j]<0)
    {
        money=money+C[i]*P[j];
        i++;
        j++;
    }
    int s=m-1,t=n-1;
    while(s>=0&&t>=0&&C[s]>0&&P[t]>0)
    {
        money=money+C[s]*P[t];
        s--;
        t--;
    }
    cout<<money;
}
