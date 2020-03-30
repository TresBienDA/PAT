#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n,b;
    int temp;
    vector<int> number;
    cin>>n>>b;
    int i=0;
    while(n!=0)
    {
        temp=n%b;
        number.push_back(temp); 
        n=n/b;
        i++;
    }
    int p=0,q=number.size()-1;
    while(p<q)
    {
        if(number[p]==number[q])
        {
            p++;
            q--;
        } else {
            cout<<"No"<<endl;
            break;
        }
    }
    if(p>=q) cout<<"Yes"<<endl;
    int r=number.size()-1;
    cout<<number[r];
    for(r=number.size()-2;r>=0;r--)
    {
        cout<<" "<<number[r];
    }
}
