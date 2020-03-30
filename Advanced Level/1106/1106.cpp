#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;

vector<int> child[100001];
int n;
double p,r;
int mind=100000;
int count=0;
int depth;

void DFS(int root,int depth)
{
	if(child[root].size()==0){
		if(depth<mind){
			mind=depth;
			count=1;
		} else if(depth==mind) {
			count++;
		}
		return;
	}
	for(int i=0;i<child[root].size();i++)
	{
		DFS(child[root][i],depth+1);
	}
}

int main()
{
	cin>>n>>p>>r;
	for(int i=0;i<n;i++)
	{
		int num;
		cin>>num;
		for(int j=0;j<num;j++){
			int no;
			cin>>no;
			child[i].push_back(no);
		}
	}
	DFS(0,0);
	p=p*pow((1+r/100),mind);
	printf("%.4f %d",p,count);
} 
