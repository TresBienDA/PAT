#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

typedef struct {
	int adress;
	int key;
	int next;
	bool flag=false;
}Node;

bool cmp(Node a,Node b)
{
	if(a.flag==false||b.flag==false)
	{
		return a.flag>b.flag;
	} else {
		return a.key<b.key;
	}
}

int main()
{
	Node L[100000];
	int n,head;
	cin>>n>>head;
	for(int i=0;i<n;i++)
	{
		int ad;
		cin>>ad;
		cin>>L[ad].key>>L[ad].next;
		L[ad].adress=ad;
	}
	int count=0;
	int p=head;
	while(p!=-1)
	{
		count++;
		L[p].flag=true;
		p=L[p].next;
	}
	sort(L,L+100000,cmp);
	if(count==0){
		printf("0 -1");
		exit(0);
	} else {
		printf("%d %05d\n",count,L[0].adress);
		for(int i=0;i<count-1;i++)
		{
			printf("%05d %d %05d\n",L[i].adress,L[i].key,L[i+1].adress);
		}
		printf("%05d %d -1",L[count-1].adress,L[count-1].key);
	}
}
 
