#include<stdio.h>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

int main()
{
    char number[4];
    string str;
    int len=4;
    int d=0,x=0,cha=0;
    cin>>str;
    for(int i=0;i<len;i++)
    {
        number[i]=str[i]-'0';
    }
    if(number[0]==number[1]&&number[1]==number[2]&&number[2]==number[3])
    {
        cout<<str<<" "<<"-"<<" "<<str<<" "<<"="<<" "<<"0000";
    } else {
        while(cha!=6174)
        {
            sort(number,number+4);
            for(int i=0;i<4;i++)
            {
                x=x*10+number[i];
                d=d*10+number[3-i];
            }
            cha=d-x;
            printf("%04d - %04d = %04d\n",d,x,cha);
            number[3]=cha%10;
            number[2]=(cha/10)%10;
            number[1]=(cha/100)%10;
            number[0]=cha/1000;
            d=0;
            x=0;
        }
    }

}
