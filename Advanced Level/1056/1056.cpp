#include<iostream>
#include<queue>
using namespace std;

typedef struct {
	int weight;
	int R;
}mouse;

int main()
{
	queue<int> que;
	mouse mice[1000];
	int np,ng;
	cin>>np>>ng;
	for(int i=0;i<np;i++)
	{
		cin>>mice[i].weight;
	}
	for(int i=0;i<np;i++)
	{
		int no;
		cin>>no;
		que.push(no);
	}
	int num=que.size();
	int group;
	while(que.size()!=1)
	{
		if(np%ng==0){
			group=num/ng;
		} else {
			group=num/ng+1;
		}
		for(int i=0;i<group;i++)
		{
			int k=que.front();
			for(int j=0;j<ng;j++)
			{
				if(i*ng+j>=num){
					break;
				}
				int front=que.front();
				if(mice[k].weight<mice[front].weight)
				{
					k=front;
				}
				mice[front].R=group+1;
				que.pop(); 
			}
			que.push(k);
		}
		num=group;
	}
	mice[que.front()].R=1;
	for(int i=0;i<np;i++)
	{
		cout<<mice[i].R;
		if(i<np-1){
			cout<<" ";
		}
	}
}
