#include<iostream>
#include<string>
using namespace std;

int main()
{
    char mp[5]={'S','H','C','D','J'};
    int a[55];
    int b[55];
    int c[55];
    int k;
    cin>>k;
    for(int i=1;i<55;i++)
    {
        a[i]=i;
    }
    for(int i=1;i<55;i++)
    {
        cin>>b[i];
    }
    for(int i=0;i<k;i++)
    {
        for(int j=1;j<55;j++)
        {
            c[b[j]]=a[j];
        }
        for(int j=1;j<55;j++)
        {
            a[j]=c[j];
        }
    }
    cout<<mp[a[1]/13]<<a[1]%13;
    for(int i=2;i<55;i++)
    {
    	//�����һ��Ϊ�˷�ֹ13%13==0�����������һ֮��a[i]%13��ֵ��Ϊ0~12;
    	a[i]--; 
        cout<<" "<<mp[a[i]/13]<<a[i]%13+1;
    }
}
