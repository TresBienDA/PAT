#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;

bool cmp(string a,string b)
{
    if(strcmp(a.c_str(),b.c_str())!=0){
        return a+b<b+a;
    }
}

int main()
{
    int n;
    string str[10000];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>str[i];
    }
    sort(str,str+n,cmp);
    string res;
    for(int i=0;i<n;i++)
    {
        res=res+str[i];
    }
    while(res.size()!=0&&res[0]=='0')
    {
        res.erase(res.begin());
    }
    if(res.size()==0) 
        cout<<0;
    else{
        cout<<res;
    }
}
