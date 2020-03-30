#include<cstdio>
#define MAXN 100000 
int main()
{
	int N,M,C1,C2;
	scanf("%d%d%d%d",&N,&M,&C1,&C2);//����N--��������M--��·����C1--Դ��,C2--Ŀ�ĵ� 
	int City[N];
	int arcs[N][N];
	int Sum[N];
	int gather[N];
	int i,i1,i2,d;
	for(i1=0;i1<N;++i1)//��ʼ����·��Ȩֵ 
	{
		for(i2=0;i2<N;i2++)
		{
			arcs[i1][i2]=MAXN;
			if(i1==i2)
				arcs[i1][i2]=0;
		}
	}
	for(i=0;i<N;++i)//������о�Ԯ�ӵ����� 
		scanf("%d",&City[i]);
	for(i=0;i<M;++i)//������м�ĵ�·��Ȩֵ 
	{
		scanf("%d%d%d",&i1,&i2,&d);
		arcs[i1][i2]=d;
		arcs[i2][i1]=d;
	}
	
	bool S[N];//����Ƿ񱻷��ʵ����� 
	int dist[N],path[N];//Դ�㵽i���·��Ȩֵ����͵�i��ĸ�������� 
	for(i=0;i<N;++i)//��ʼ���������飬·��Ȩֵ���飬�����Ԯ�����飬��С·���������� 
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
	int c=-1;//Դ��ĸ������ 
	while(c!=C2)
	{
		d=MAXN;
		for(i=0;i<N;++i)
		{
			if(S[i]==true)//�����ѷ��ʽ�� 
				continue;
			if(dist[i]<d)//���µ�i����·���� 
			{
				i1=i;
				d=dist[i];
			}
		}
		S[i1]=true;//���i����Ѿ����� 
		c=i1;//������һ���ĸ������ 
		for(i=0;i<N;++i)
		{
			if(S[i]==true)//�������ڼ����еĽ�� 
				continue;
			if(dist[i]>dist[c]+arcs[c][i])//�Ƚ�֮ǰ��i����·���;�c�����ת��·������ 
			{
				dist[i]=dist[c]+arcs[c][i];
				//path[i]=c;
				gather[i]=City[i]+gather[c];
				Sum[i]=Sum[c];
			}else if(dist[i]==dist[c]+arcs[c][i])//��������轫��С·���������� 
			{
				Sum[i]=Sum[i]+Sum[c];
				if(gather[i]<gather[c]+City[i])//�Ƚ�������С·�������������� 
					gather[i]=gather[c]+City[i];
			}
		}
	}
	printf("%d %d",Sum[C2],gather[C2]);
	return 0;
}
