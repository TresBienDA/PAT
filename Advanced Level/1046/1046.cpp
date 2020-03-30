#include<iostream>
using namespace std;

int main()
{
    int exit[100001];
    int n;
    int sum=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>exit[i];
    }
    for(int i=1;i<=n;i++)
    {
        sum=sum+exit[i];
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int from,to;
        int dis=0;
        int from1,to1;
        cin>>from>>to; 
        while(from!=to)
        {
            dis=dis+exit[from];
            from++;
            if(from>n){
                from=1;
            }
        }
        if(dis>sum-dis) {
            cout<<sum-dis<<endl;
        } else {
            cout<<dis<<endl;
        }
    }
}
