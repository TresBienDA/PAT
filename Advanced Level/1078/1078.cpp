#include<iostream>
#include<math.h>
using namespace std;

int hashtable[100000];
int size;
bool p[100000]={0};
int prime[10000];
int num=0;

void find_prime()
{
    for(int i=2;i<100000;i++)
    {
        if(p[i]==0)
        {
            prime[num++]=i;
            if(num>=10000) break;
            for(int j=i+i;j<100000;j=j+i){
                p[j]=1;
            }
        }
    }
}

void initTable(int size)
{
	for(int i=0;i<size;i++)
	{
		hashtable[i]=-1;
	}
}

bool isprime(int m)
{
    //判断素数要注意1
    if(m==1) return false;
    //循环条件注意可以取等
    for(int i=2;i<=(int)sqrt(m);i++)
    {
        if(m%i==0){
            return false;
        }
    }
    return true;
}

int find_size(int m)
{
    if(isprime(m)==false)
    {
        for(int i=0;i<10000;i++)
        {
            if(prime[i]>m){
                m=prime[i];
                return m;
            }
        }
    } else {
        return m;
    }
}

bool isempty(int i)
{
    if(hashtable[i]==-1){
        return true;
    } else {
        return false;
    }
}

void insert(int number)
{
    int i=1;
    int ad=number%size;
    int adr=ad;
    while(isempty(adr)==false)
    {
        if(i==size){
            cout<<"-";
            break;
        }
        adr=(ad+i*i)%size;
        i++;
    }
    if(isempty(adr)==true){
    	hashtable[adr]=number;
    	cout<<adr;
    }
}

int main()
{
    int m,n;
    int a[10000];
    cin>>m>>n;
    find_prime(); 
    size=find_size(m);
    initTable(size);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(i==0){
            insert(a[i]);
        } else {
            cout<<" ";
            insert(a[i]);
        }
    }
}
