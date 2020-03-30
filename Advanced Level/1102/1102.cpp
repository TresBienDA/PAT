#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector> 
using namespace std;

typedef struct {
	int left;
	int right;
}Node;

vector<int> in;
vector<int> level;
Node node[10];

void Levelorder(int root)
{
	queue<int> que;
	que.push(root);
	while(!que.empty())
	{
		int p=que.front();
		level.push_back(p);
		que.pop();
		if(node[p].right!=-1){
			que.push(node[p].right);
		}
		if(node[p].left!=-1){
			que.push(node[p].left);
		}
	}
	cout<<level[0];
	for(int i=1;i<level.size();i++){
		cout<<" "<<level[i];
	}
}

void Inorder(int root)
{
	if(root==-1) return;
	Inorder(node[root].right);
	in.push_back(root);
	Inorder(node[root].left);
}

int main()
{
	int n;
	cin>>n;
	char left,right;
	for(int i=0;i<n;i++){
		cin>>left>>right;
		if(left=='-'){
			node[i].left=-1;
		} else {
			node[i].left=left-'0';
		} 
		if(right=='-'){
			node[i].right=-1;
		} else {
			node[i].right=right-'0';
		}
	}
	int root;
	for(int i=0;i<n;i++)
	{
		int flag=1;
		root=i;
		for(int j=0;j<n;j++){
			if(root==node[j].left||root==node[j].right){
				flag=0;
			}
		}
		if(flag==1){
			break;
		}
	}
	Levelorder(root);
	cout<<endl;
	Inorder(root);
	cout<<in[0];
	for(int i=1;i<in.size();i++){
		cout<<" "<<in[i];
	}
}
