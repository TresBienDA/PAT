#include<stdio.h>
#include<iostream>
#include<string>
#include<stack>
using namespace std;

typedef struct
{
    int data;
    int next;
}Node;

int main()
{
    Node node[100000];  
    int head,n,k;
    int realnum=0;
    cin>>head>>n>>k;
    for(int i=0;i<n;i++)
    {
        int ad;
        cin>>ad;
        cin>>node[ad].data>>node[ad].next;
    }
    for(int i=head;i!=-1;i=node[i].next)
    {
        realnum++;
    }
    int num=realnum;
    int start;
    start=head; 
    int p=head;
    int q=node[head].next;
    int r=node[node[head].next].next;
    while(num>=k)
    {
        int count1=1;
        int count2=1;
        while(count1<k)
        {
            node[q].next=p;
            p=q;
            q=r;
            r=node[r].next;
            count1++;
        }
        num=num-k;
        if(num==realnum-k)
        {
            head=p;
        }
        p=q;
        q=r;
        r=node[r].next;
        if(num>=k){
        	int temp;
        	temp=p;
	        while(count2<k)
	        {
	        	temp=node[temp].next;
	        	count2++;
	        }
	        node[start].next=temp;
	        start=p;
    	} else {
    		node[start].next=p;
	        start=p;
    	}
	}      
    while(head!=-1)
    {
        if(node[head].next==-1)
        {
            printf("%05d %d %d",head,node[head].data,node[head].next);
        } else
        {
            printf("%05d %d %05d\n",head,node[head].data,node[head].next);
        }
        head=node[head].next;
    }
}
