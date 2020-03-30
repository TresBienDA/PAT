#include<iostream>
#include<string>
#include<map>
using namespace std;

#define INF 1000000000
#define maxn 2010

map<int,string> intTostring; 
map<string,int> stringToint;
//因为map类型只能由first->second的方式来访问，所以这里定义两个map实现互相访问 
map<string,int> Gang;
//题目要求输出head的名称和head所在Gang的人数，所以定义一个map实现head->numPerson的访问 
int G[maxn][maxn]={0},weight[maxn]={0};
//边权矩阵（邻接矩阵）和点权（顶点信息） 
int n,k,numPerson=0;
bool vis[maxn]={false};

int change(string str)
{
	if(stringToint.find(str)!=stringToint.end()){
		return stringToint[str];
	} else {
		stringToint[str]=numPerson;
		intTostring[numPerson]=str;
		return numPerson++;
	}
}

//根据题意我们需要得到每个符合要求的连通分量的结点数和点权最大的结点，而每一次
//深度遍历都访问了一个连通分量的所有结点，所以DFS()需要做的有：
//1.找出该连通分量中点权最大的结点（head） 
//2.计算出连通分量的节点数(numMember)
//3.求出连通分量的总权值(totalValue)
//再加上当前结点用于递归，所以DFS的参数就可以确定了。
void DFS(int now,int &head,int &numMember,int &totalValue)
{
	numMember++;
	vis[now]=true;
	if(weight[now]>weight[head]){
		head=now;
	}
	for(int i=0;i<numPerson;i++){
		if(G[now][i]>0){
			totalValue+=G[now][i];
			G[now][i]=G[i][now]=0;
			if(vis[i]==false){
				DFS(i,head,numMember,totalValue);
			}
		}
	}
}


//DFS()函数只遍历一个连通分量，所以DFSTrave（）函数需要用循环来实现所有连通分量
//的遍历，并且要将最后的结果存到Gang中去 
void DFSTrave()
{
	for(int i=0;i<numPerson;i++)
	{
		if(vis[i]==false){
			int head=i,numMember=0,totalValue=0;
			DFS(i,head,numMember,totalValue);
			if(numMember>2&&totalValue>k){
				Gang[intTostring[head]]=numMember;
			}
		}
	}
}


//main函数实现数据的读取：
//1.读取字符串转换成编号记录到stringToint中，以便邻接矩阵和结点信息的表示
//2.构建一个邻接矩阵表示的图
//读取之后还需调用业务函数，最后输出结果 
int main()
{
	string str1,str2;
	int w;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>str1>>str2>>w;
		int id1=change(str1);
		int id2=change(str2);
		weight[id1]+=w;
		weight[id2]+=w;
		G[id1][id2]+=w;
		G[id2][id1]+=w;
	}
	DFSTrave();
	cout<<Gang.size()<<endl;
	map<string,int>::iterator it;
	for(it=Gang.begin();it!=Gang.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}
	return 0;
} 
