#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int R,G,B;
    int num[13]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
    while(cin>>R>>G>>B)
    {
        char color[6];
        color[0]=num[R/13];
        color[1]=num[R%13];
        color[2]=num[G/13];
        color[3]=num[G%13];
        color[4]=num[B/13];
        color[5]=num[B%13];
        cout<<"#";
        for(int i=0;i<6;i++)
        {
            cout<<color[i];
        }
        cout<<endl;
    }
    
}
