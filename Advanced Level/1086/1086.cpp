#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<stack>
#include<vector>
using namespace std;

vector<int> v;

typedef struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
}BTNode;

BTNode* BuildTree(int *pre,int *mid,int n)
{
	if(n<=0) return NULL;
	int *p;
	p=mid;
	while(*p!=*pre)
	{
		p++;
	}
	int len=p-mid;
	BTNode *T;
	T=(BTNode*)malloc(sizeof(BTNode));
	T->data=*p;
	T->left=BuildTree(pre+1,mid,len);
	T->right=BuildTree(pre+len+1,p+1,n-len-1);
	return T;
}

void postorder(BTNode *root)
{
	if(root==NULL) return;
	postorder(root->left);
	postorder(root->right);
	v.push_back(root->data);
}

int main()
{
	int pre[31];
	int mid[31];
	string push="Push";
	string pop="Pop";
	string str;
	int n,data=1;
	stack<int> s;
	scanf("%d",&n);
	int num1=0,num2=0,num=0;
	while(cin>>str)
	{
		cin>>str;
		if(strcmp(str.c_str(),push.c_str())==0){
			cin>>data;
			s.push(data);
			pre[num1++]=data;
		}
		if(strcmp(str.c_str(),pop.c_str())==0){
			if(s.size()!=0){
				mid[num2++]=s.top();
				s.pop();
			}
		}
	}
	BTNode *root;
	root=BuildTree(pre,mid,num1);
	postorder(root); 
	cout<<v[0];
	for(int i=1;i<v.size();i++){
		cout<<" "<<v[i];
	}
}
