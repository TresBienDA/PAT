#include<iostream>
#include<stdio.h> 
#include<vector>
#include<math.h>
using namespace std;

typedef struct {
	vector<int> child; 
}Node;

Node node[100001];
int root,maxd=0;
int N,count=0;
double P,r;

void DFS(int root,int depth)
{
	if(node[root].child.size()==0){
		if(depth>maxd){
			maxd=depth;
			count=1; 
		} else if(depth==maxd){
			count++;
		}
		return;
	}
	for(int i=0;i<node[root].child.size();i++){
		DFS(node[root].child[i],depth+1);
	}
}

int main()
{
	cin>>N>>P>>r;
	for(int i=0;i<N;i++)
	{
		int id;
		cin>>id;
		if(id==-1){
			root=i;	
		} else {
			node[id].child.push_back(i);	
		}
	}
	DFS(root,0);
	P=P*pow(1+r/100,maxd);
	printf("%.2f %d",P,count);
} 
