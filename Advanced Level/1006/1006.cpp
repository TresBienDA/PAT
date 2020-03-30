#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef struct {
    string no;
    string sign_in;
    string sign_out;
}Record;

bool cmp1(Record a,Record b)
{
    if(strcmp(a.sign_in.c_str(),b.sign_in.c_str())!=0)
        return !strcmp(a.sign_in.c_str(),b.sign_in.c_str());
}

bool cmp2(Record a,Record b)
{
    if(strcmp(a.sign_out.c_str(),b.sign_out.c_str())!=0)
        return strcmp(a.sign_out.c_str(),b.sign_out.c_str());
}

int main()
{
    int m;
    cin>>m; 
    Record a[1000];
    for(int i=0;i<m;i++)
    {
        cin>>a[i].no>>a[i].sign_in>>a[i].sign_out;
    }
    sort(a,a+m,cmp1);
    cout<<a[0].no<<" ";
    sort(a,a+m,cmp2);
    cout<<a[0].no<<" ";
}
