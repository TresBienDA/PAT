#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int BST[1001],CBST[1001];
int index=1;
int n; 

void inorder(int root)
{
	if(root>n) return;
	inorder(2*root);
	CBST[root]=BST[index++];
	inorder(2*root+1);
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>BST[i];
	}
	sort(BST+1,BST+n+1);
	inorder(1);
	for(int i=1;i<=n;i++)
	{
		cout<<CBST[i];
		if(i<n){
			cout<<" ";
		}
	}
}
