#include<iostream>
using namespace std;

int prime[10000];
bool p[120000]={0};
int num=0;

//����ɸ��
void find_prime(int n)
{
	//������2��ʼ��i��2��ʼ 
    for(int i=2;i<120000;i++)
    {
        if(p[i]==0){
            prime[num++]=i;
            if(num>=n) break;
            //�ж�����֮��Ѹ������ı���ȫ��ɸ�� 
            for(int j=i+i;j<120000;j=j+i){ 
                p[j]=1;
            }
        }
    }
}

int main()
{
    int m,n,count=0;
    cin>>m>>n;
    find_prime(n);
    for(int i=m;i<=n;i++)
    {
        cout<<prime[i-1];
        count++;
        if(count%10!=0&&i<n){
            cout<<" ";
        } else {
            cout<<endl;
        }
    }
    return 0;
}
