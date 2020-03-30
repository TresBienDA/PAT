#include<iostream>
#include<stack>
using namespace std;



int main()
{
	stack<int> s;
	int Max;
    int a[1000];
    int n,k;
    cin>>Max>>n>>k;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[j];
        }
        int r=1;
        int flag=1;
        while(s.size()!=0){
        	s.pop();
        }
        for(int j=0;j<n;j++)
        {
        	while(r<=a[j])
        	{
        		s.push(r);
        		r++;
        		if(s.size()==Max){
        			break;
        		}
        	}
        	if(s.top()!=a[j]){
        		flag=0;
        		break;
        	} else {
        		s.pop();
        	}
        }
        if(flag==0){
        	cout<<"NO"<<endl;
        } else {
        	cout<<"YES"<<endl;
        }
    }
}
