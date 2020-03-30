#include<iostream>
using namespace std;

int main()
{
    int k;
    int a[10000];
    int sum=0;
    int front;
    int after;
    int max=0;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<k;i++)
    {
        sum=sum+a[i];
        if(sum<0)
        {
            sum=0;
        } else if(sum>max){
            max=sum;
            after=i;
        }
    }
    int tag=after,Max=max;
    while(Max!=0)
    {
    	Max=Max-a[tag];
    	tag--;
    }
    front=tag+1;
    cout<<max<<" "<<front<<" "<<after; 
}
