#include<cstdio>
#define MAXN 100000 
int main()
{
	int N,M,C1,C2;
	scanf("%d%d%d%d",&N,&M,&C1,&C2);//读入N--城市数，M--道路数，C1--源点,C2--目的点 
	int City[N];
	int arcs[N][N];
	int Sum[N];
	int gather[N];
	int i,i1,i2,d;
	for(i1=0;i1<N;++i1)//初始化道路的权值 
	{
		for(i2=0;i2<N;i2++)
		{
			arcs[i1][i2]=MAXN;
			if(i1==i2)
				arcs[i1][i2]=0;
		}
	}
	for(i=0;i<N;++i)//读入城市救援队的数量 
		scanf("%d",&City[i]);
	for(i=0;i<M;++i)//读入城市间的道路和权值 
	{
		scanf("%d%d%d",&i1,&i2,&d);
		arcs[i1][i2]=d;
		arcs[i2][i1]=d;
	}
	
	bool S[N];//标记是否被访问的数组 
	int dist[N],path[N];//源点到i点的路径权值数组和到i点的父结点数组 
	for(i=0;i<N;++i)//初始化访问数组，路径权值数组，集结救援队数组，最小路径条数数组 
	{
		S[i]=false;
		dist[i]=arcs[C1][i];
		//path[i]=C1;
		if(i==C1)
		{
			Sum[C1]=1;
			gather[C1]=City[C1];
		}else
		{
			Sum[i]=0;
			gather[i]=0;
		}
	}
	int c=-1;//源点的父结点编号 
	while(c!=C2)
	{
		d=MAXN;
		for(i=0;i<N;++i)
		{
			if(S[i]==true)//跳过已访问结点 
				continue;
			if(dist[i]<d)//更新到i结点的路径长 
			{
				i1=i;
				d=dist[i];
			}
		}
		S[i1]=true;//标记i结点已经访问 
		c=i1;//更新下一结点的父结点编号 
		for(i=0;i<N;++i)
		{
			if(S[i]==true)//跳过已在集合中的结点 
				continue;
			if(dist[i]>dist[c]+arcs[c][i])//比较之前到i结点的路径和经c结点中转的路径长度 
			{
				dist[i]=dist[c]+arcs[c][i];
				//path[i]=c;
				gather[i]=City[i]+gather[c];
				Sum[i]=Sum[c];
			}else if(dist[i]==dist[c]+arcs[c][i])//若相等则需将最小路径条数更新 
			{
				Sum[i]=Sum[i]+Sum[c];
				if(gather[i]<gather[c]+City[i])//比叫新老最小路径集结队伍的数量 
					gather[i]=gather[c]+City[i];
			}
		}
	}
	printf("%d %d",Sum[C2],gather[C2]);
	return 0;
}
