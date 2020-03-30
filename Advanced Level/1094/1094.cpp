#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> child[100];
int n,m;
int maxl=1,maxg=0;

int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int id,num;
		cin>>id>>num;
		for(int j=0;j<num;j++)
		{
			int no;
			cin>>no;
			child[id].push_back(no);
		}
	}
	queue<int> que;
	que.push(1);
	int sum=0;
	int level=1;
	int last=1;
	while(!que.empty())
	{
		int front=que.front();
		que.pop();
		sum++;
		if(child[front].size()!=0){
			for(int i=0;i<child[front].size();i++){
				que.push(child[front][i]);
			}
		}
		if(front==last){
			if(sum>maxg){
				maxg=sum;
				maxl=level;
				sum=0; 
			}
			last=que.back();
			level++;
		}
	}
	cout<<maxg<<" "<<maxl;
} 
