#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct {
	char data;
	int next;
}Node;

int main()
{
	int L1,L2,n;
	Node L[100000];
	cin>>L1>>L2>>n;
	for(int i=0;i<n;i++)
	{
		int ad;
		cin>>ad;
		cin>>L[ad].data>>L[ad].next;
	}
	int p=L1,q=L2;
	int c1=0,c2=0;
	while(L[p].next!=-1){
		c1++;
		p=L[p].next;
	}
	while(L[q].next!=-1){
		c2++;
		q=L[q].next;
	}
	p=L1;
	q=L2;
	if(c1>c2){
		for(int i=0;i<abs(c1-c2);i++){
			p=L[p].next;	
		}
	} else {
		for(int i=0;i<abs(c1-c2);i++){
			q=L[q].next;
		}
	}
	while(q!=-1&&p!=-1){
		if(q==p){
			printf("%05d",p);
			break;
		} else {
			p=L[p].next;
			q=L[q].next;
		}
	}
	//注意这里是或 
	if(q==-1||p==-1){
		cout<<-1;
	}
}
