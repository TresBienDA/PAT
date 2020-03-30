#include<iostream>
#include<stdlib.h>
#include<queue>
#include<vector>
using namespace std;

typedef struct Node {
	int data;
	struct Node *lchild;
	struct Node *rchild;
}BTNode;

BTNode* BuildTree(int *mid,int *post,int n)
{
	if(n<=0) return NULL;
	int *p=mid;
	while(p!=NULL)
	{
		if(*p==*(post+n-1))
		{
			break;
		}
		p++; 
	}
	int len=p-mid;
	BTNode *T;
	T=(BTNode*)malloc(sizeof(BTNode));
	T->data=*p;
	T->lchild=BuildTree(mid,post,len);
	T->rchild=BuildTree(p+1,post+len,n-len-1);
	return T;
}

vector<int> Level(BTNode *bt)
{
	queue<BTNode*> que;
	vector<int> v;
	que.push(bt);
	while(!que.empty())
	{
		BTNode *p;
		p=que.front();
		que.pop();
		v.push_back(p->data);
		if(p->lchild!=NULL){
			que.push(p->lchild);
		} 
		if(p->rchild!=NULL){
			que.push(p->rchild);
		}
	}
	return v;
}

int main()
{
	int post[31];
	int mid[31];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>post[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>mid[i];
	}
	BTNode *bt;
	bt=BuildTree(mid,post,n);
	vector<int> v=Level(bt);
	cout<<v[0];
	for(int i=1;i<v.size();i++){
		cout<<" "<<v[i];
	}
} 
