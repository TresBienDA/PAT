#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

typedef struct {
	int num=0;
	int amount=0;
	vector<int> child; 
}Node;

Node node[100000];
float sum=0;
int n;
float p,r;

void DFS(int root,float price)
{
	if(node[root].num==0){
		sum=sum+node[root].amount*price;
		return;
	} else {
		for(int i=0;i<node[root].num;i++){
			DFS(node[root].child[i],price*(1+r/100));
		}
	}
}

int main()
{
	cin>>n>>p>>r;
	for(int i=0;i<n;i++)
	{
		cin>>node[i].num;
		if(node[i].num!=0)
		{
			for(int j=0;j<node[i].num;j++)
			{
				int id;
				cin>>id;
				node[i].child.push_back(id);
						
			}
		} else {
			cin>>node[i].amount;
		}
	}
	DFS(0,p);
	printf("%.1f",sum);
} 
