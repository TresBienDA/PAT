#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
}Node;

vector<int> origin,pre,preM,post,postM;

void insert(Node *&root,int data)
{
	if(root==NULL){
		root=(Node*)malloc(sizeof(Node));
		root->data=data;
		root->left=root->right=NULL;
		return;
	}
	if(data<root->data){
		insert(root->left,data);
	} else {
		insert(root->right,data);
	}
}

void preorder(Node *root)
{
	if(root==NULL) return;
	pre.push_back(root->data);
	preorder(root->left);
	preorder(root->right);
}

void Mpreorder(Node *root)
{
	if(root==NULL) return;
	preM.push_back(root->data);
	Mpreorder(root->right);
	Mpreorder(root->left);
}

void postorder(Node *root)
{
	if(root==NULL) return;
	postorder(root->left);
	postorder(root->right);
	post.push_back(root->data);
}

void Mpostorder(Node *root)
{
	if(root==NULL) return;
	Mpostorder(root->right);
	Mpostorder(root->left);
	postM.push_back(root->data);
}

int main()
{
	int n;
	Node *root=NULL;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int data;
		cin>>data;
		origin.push_back(data);
		insert(root,data);
	}
	preorder(root);
	Mpreorder(root);
	postorder(root);
	Mpostorder(root);
	if(origin==pre){
		cout<<"YSE"<<endl;
		cout<<post[0];
		for(int i=1;i<post.size();i++){
			cout<<" "<<post[i];
		}
	}else if(origin==preM) {
		cout<<"YES"<<endl;
		cout<<postM[0];
		for(int i=1;i<postM.size();i++) {
			cout<<" "<<postM[i];
		}
	} else {
		cout<<"NO"<<endl;
	}
	
} 
