#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

typedef struct {
	vector<int> child;
}Node;

Node node[100];
int level[100];
int n,m;

void BFS(int root)
{
	queue<int> que;
	que.push(root);
	int last=1;
	int count=0;
	int l=0;
	while(!que.empty())
	{
		int front=que.front();
		que.pop();
		if(node[front].child.size()==0){
			count++;
		} else {
			for(int i=0;i<node[front].child.size();i++){
				que.push(node[front].child[i]);
			}
		}
		if(front==last){
			int num=node[front].child.size();
			if(num==0){
				level[l]=count;
				count=0;
				l++;
			} else { 
				level[l]=count;
				last=node[front].child[num-1];
				count=0;
				l++;
			} 
		}
	}
	cout<<level[0];
	for(int i=1;i<l;i++)
	{
		cout<<" "<<level[i];
	}
}

int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int id;
		int num;
		cin>>id>>num;
		for(int j=0;j<num;j++)
		{
			int c;
			cin>>c;
			node[id].child.push_back(c); 
		}
	}
	int root=1;
	BFS(root);
} 
