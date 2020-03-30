#include<stdio.h>
#include<iostream>
#define N 500
#define INF 100000
using namespace std;

typedef struct {
	int City[N];
	int Road[N][N];
	int cities,roads;
}MGraph;


int dist[N];
int sum[N];
int gather[N];
bool visited[N];


void dijkstra(MGraph Map,int c1,int c2)
{
	int c=-1;
	int d=INF;
	int k,i1,i2;
	for(int i=0;i<Map.cities;i++)
	{
		dist[i]=Map.Road[c1][i];
		visited[i]=false;
		//path[i]=-1;
		if(i==c1)
		{
			sum[i]=1;
			gather[i]=Map.City[i];
		} 
		else
		{
			sum[i]=0;
			gather[i]=0;
		}
		
	}
	while(c!=c2)
	{
		for(k=0;k<Map.cities;k++)
		{
			if(visited[k]==true)
			{
				continue;
			}
			if(dist[k]<d)
			{
				i1=k;
				d=dist[k];	
			}
			visited[i1]=true;
			c=i1;
		}
		for(k=0;k<N;k++)
		{
			if(visited[k]==true)
			{
				continue;
			}
			if(dist[k]>dist[c]+Map.Road[c][k])
			{
				dist[k]=dist[c]+Map.Road[c][k];
				gather[k]=Map.City[k]+gather[c];
			} else if (dist[k]==dist[c]+Map.Road[c][k])
			{
				sum[k]=sum[k]+sum[c];
				if(gather[k]<gather[c]+Map.City[k]){
					gather[k]=gather[c]+Map.City[k];
				}
			}
		}
	}
	printf("%d %d",sum[c2],gather[c2]);
	
}

int main()
{
	MGraph Map;
	int n,m,c1,c2;//n--��������m--��·����c1--Դ���ţ�c2--Ŀ�ĵ��� 
	int j,k;
	cin>>n>>m>>c1>>c2;
	Map.cities=n;
	Map.roads=m;
	for(int i=0;i<Map.cities;i++)//�����Ԯ������ 
	{
		scanf("%d",&Map.City[i]);
	}
	for(int i=0;i<Map.cities;i++)//��ʼ���ߣ���·����Ȩֵ 
	{
		for(int l=0;l<n;l++)
		{
			Map.Road[i][l]=Map.Road[l][i]=INF;
		}
	}
	for(int i=0;i<Map.roads;i++)//�����·��Ȩֵ 
	{
		scanf("%d %d",&j,&k);
		scanf("%d",&Map.Road[j][k]); 
		Map.Road[k][j]=Map.Road[j][k];
	}
	dijkstra(Map,c1,c2);

} 
