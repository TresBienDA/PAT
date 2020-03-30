#include<iostream>
#include<queue>
using namespace std;

int stroke[60][1286][128];
int M,N,L,T;
bool visited[60][1286][128]={false};
int X[6]={-1,1,0,0,0,0};
int Y[6]={0,0,-1,1,0,0};
int Z[6]={0,0,0,0,-1,1};

struct node{
	int x,y,z;
}Node;

bool judge(int x,int y,int z)
{
	if(x>=L||x<0||y>=N||y<0||z>=M||z<0){
		return false;
	}
	if(stroke[x][y][z]==0||visited[x][y][z]==true){
		return false;
	}
	return true;
}

int BFS(int x,int y,int z)
{
	queue<node> que;
	int volume=0;
	Node.x=x;Node.y=y;Node.z=z;
	que.push(Node);
	visited[x][y][z]=true;
	while(!que.empty())
	{
		node front;
		front=que.front();
		que.pop();
		volume++;
		for(int i=0;i<6;i++)
		{
			int newX=front.x+X[i];
			int newY=front.y+Y[i];
			int newZ=front.z+Z[i];
			if(judge(newX,newY,newZ)){
				Node.x=newX;
				Node.y=newY;
				Node.z=newZ;
				que.push(Node);
				visited[newX][newY][newZ]=true;
			}
		}
	}
	if(volume>=T){
		return volume;
	} else {
		return 0;
	}
}

int main()
{	
	cin>>N>>M>>L>>T;
	for(int i=0;i<L;i++)
	{
		for(int j=0;j<N;j++){
			for(int k=0;k<M;k++)
			{
				cin>>stroke[i][j][k];
			}
		}
	}
	int v=0;
	for(int x=0;x<L;x++)
	{
		for(int y=0;y<N;y++){
			for(int z=0;z<M;z++)
			{
				if(stroke[x][y][z]==1&&visited[x][y][z]==false){
					v=v+BFS(x,y,z);
				}
			}
		}
	}
	cout<<v;
} 
