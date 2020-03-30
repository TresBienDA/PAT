#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct {
	int weight;
	vector<int> child;
}Node;

Node node[110];
int path[110];
int n,m,s; 

bool cmp(int a,int b)
{
	if(a!=b){
		return node[a].weight>node[b].weight;
	}
}

void DFS(int root,int num,int sum)
{
	if(sum>s) return;
	if(sum==s) {
		if(node[root].child.size()!=0){
			return;
		} else {
			cout<<node[path[0]].weight;
			for(int i=1;i<num;i++)
			{
				cout<<" "<<node[path[i]].weight;
			}
			cout<<endl;
		}
	}
	for(int i=0;i<node[root].child.size();i++)
	{
		int child=node[root].child[i];
		path[num]=child;
		DFS(child,num+1,sum+node[child].weight);
	}
	
}

int main()
{
	cin>>n>>m>>s;
	for(int i=0;i<n;i++)
	{
		cin>>node[i].weight;
	}
	for(int i=0;i<m;i++)
	{
		int id,num;
		cin>>id>>num;
		for(int j=0;j<num;j++)
		{
			int c;
			cin>>c;
			node[id].child.push_back(c);
		}
		sort(node[id].child.begin(),node[id].child.end(),cmp);
	}
	int root=0;
	DFS(root,1,node[0].weight);
}
