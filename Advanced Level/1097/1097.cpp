#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

typedef struct {
	int key;
	int next;
}Node;

int main()
{
	Node L[100000];
	int h1,n;
	cin>>h1>>n;
	for(int i=0;i<n;i++)
	{
		int ad;
		cin>>ad;
		cin>>L[ad].key>>L[ad].next;
	}
	int p=h1,q=L[h1].next;
	int h2;
	while(q!=-1)
	{
		if(abs(L[p].key)==L[q].key)
		{
			h2=q;
			q=L[q].next;
			L[h2].next=-1;
			L[p].next=q;
			break;
		} else {
			p=L[p].next;
			q=L[q].next;
		}
	}
	int t=h2;
	while(q!=-1)
	{
		int s;
		if(L[p].key==L[q].key)
		{	
			while(L[p].key==L[q].key)
			{
				s=q;
				q=L[q].next;
				L[p].next=q;
				L[t].next=s;
				t=s;
				L[t].next=-1;
			}
		} else {
			p=L[p].next;
			q=L[q].next;
		}
	}
	p=h1;
	q=h2;
	while(p!=-1)
	{
		if(L[p].next==-1){
			printf("%05d %d -1\n",p,L[p].key);
		} else {
			printf("%05d %d %05d\n",p,L[p].key,L[p].next);
		}
		p=L[p].next;
	}
	while(q!=-1)
	{
		if(L[q].next==-1){
			printf("%05d %d -1",q,L[q].key);
		} else {
			printf("%05d %d %05d\n",q,L[q].key,L[q].next);
		}
		q=L[q].next;
	}
	
	
	
} 
