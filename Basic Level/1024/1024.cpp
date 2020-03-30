#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str;
    cin>>str; 
    int len=str.length();
    int len0=0;
    for(int i=0;i<len;i++)
    {
        if(str[i]=='E')
        {
            if(str[0]=='-')
            {
                cout<<'-';
            }
            for(int j=i+2;j<len;j++)
            {
                len0=len0*10+(str[j]-'0');
            }
            if(len0==0)
            {
                for(int j=1;j<i;j++)
                {
                    cout<<str[j];
                }
            }else if(str[i+1]=='+')
	            {
	                cout<<str[1];
	                if(len0<i-3)
	                {
	                    for(int j=3;j<3+len0;j++)
	                    {
	                        cout<<str[j];
	                    }
	                    cout<<".";
	                    for(int j=3+len0;j<i;j++)
	                    {
	                        cout<<str[j];
	                    }
	                } else
	                    {
	                        for(int j=3;j<i;j++)
	                        {
	                            cout<<str[j];
	                        }
	                        for(int j=0;j<len0-(i-3);j++)
	                        {
	                            cout<<0;
	                        }
	                    }
	            } else 
		                {
		                    cout<<"0.";
		                    for(int j=1;j<len0;j++)
		                    {
		                        cout<<0;
		                    }
		                    cout<<str[1];
		                    for(int j=3;j<i;j++)
		                    {
		                        cout<<str[j];
		                    }
		                }
        }
    }
}
