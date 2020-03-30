#include<iostream>
using namespace std;

//平衡二叉树结点，比普通二叉树多了高度字段 
typedef struct node{
	int data;
	int height;
	struct node *left;
	struct node *right; 
}Node;

int n;
int data[21];

//创建一个新结点
//插入的新节点是叶节点，所以高度设为1 
Node* newNode(int data)
{
	Node* node=new Node;
	node->data=data;
	node->height=1;
	node->left=node->right=NULL;
	return node;
}

//取子树的高度 
int getHeight(Node* root)
{
	if(root==NULL) return 0;
	return root->height;
}

//计算平衡因子 
int getBalanceFactor(Node* root)
{
	return getHeight(root->left)-getHeight(root->right);
}

//更新子树高度 
void updateHeight(Node* root)
{
	root->height=max(getHeight(root->left),getHeight(root->right))+1;
}

//左旋 
void L(Node* &root)
{
	Node *temp=root->right;
	root->right=temp->left;
	temp->left=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
}

//右旋 
void R(Node* &root)
{
	Node *temp=root->left;
	root->left=temp->right;
	temp->right=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
}


void insert(Node* &root,int data)
{
	if(root==NULL)
	{
		root=newNode(data);
		return;
	} 
	if(data<root->data)
	{
		insert(root->left,data);
		updateHeight(root);
		if(getBalanceFactor(root)==2){
			if(getBalanceFactor(root->left)==1){
				R(root);
			} else if(getBalanceFactor(root->left)==-1){
				L(root->left);
				R(root);
			}
		} 
	}else {
		insert(root->right,data);
		updateHeight(root);
		if(getBalanceFactor(root)==-2){
			if(getBalanceFactor(root->right)==-1){
				L(root);
			} else if(getBalanceFactor(root->right)==1){
				R(root->right);
				L(root);
			}
		}
	}
}

//建立平衡二叉树 
Node* create(int data[],int n)
{
	Node* root=NULL;
	for(int i=0;i<n;i++)
	{
		insert(root,data[i]);
	}
	return root;
} 

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>data[i];
	}
	Node *root=create(data,n);
	cout<<root->data;
} 
