#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

typedef struct {
	int data=0;
	int left;
	int right;
}Tree;

int n;
vector<int> BST;
vector<int> Level;
Tree tree[100];
int index=0;

void Buildtree(int root)
{
	if(root==-1) return;
	Buildtree(tree[root].left);
	tree[root].data=BST[index++];
	Buildtree(tree[root].right);
}

void level(int root)
{
	queue<int> que;
	que.push(root);
	while(!que.empty())
	{
		int front=que.front();
		que.pop();
		Level.push_back(tree[front].data);
		if(tree[front].left!=-1){
			que.push(tree[front].left);
		}
		if(tree[front].right!=-1){
			que.push(tree[front].right);
		}
	}
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>tree[i].left>>tree[i].right;
	}
	for(int i=0;i<n;i++)
	{
		int data;
		cin>>data;
		BST.push_back(data);
	}
	sort(BST.begin(),BST.end());
	Buildtree(0);
	level(0);
	for(int i=0;i<Level.size();i++){
		cout<<Level[i];
		if(i<Level.size()-1){
			cout<<" ";
		} 
	} 
}
