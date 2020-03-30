#include<iostream>
#include<string>
#include<map>
using namespace std;

#define INF 1000000000
#define maxn 2010

map<int,string> intTostring; 
map<string,int> stringToint;
//��Ϊmap����ֻ����first->second�ķ�ʽ�����ʣ��������ﶨ������mapʵ�ֻ������ 
map<string,int> Gang;
//��ĿҪ�����head�����ƺ�head����Gang�����������Զ���һ��mapʵ��head->numPerson�ķ��� 
int G[maxn][maxn]={0},weight[maxn]={0};
//��Ȩ�����ڽӾ��󣩺͵�Ȩ��������Ϣ�� 
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

//��������������Ҫ�õ�ÿ������Ҫ�����ͨ�����Ľ�����͵�Ȩ���Ľ�㣬��ÿһ��
//��ȱ�����������һ����ͨ���������н�㣬����DFS()��Ҫ�����У�
//1.�ҳ�����ͨ�����е�Ȩ���Ľ�㣨head�� 
//2.�������ͨ�����Ľڵ���(numMember)
//3.�����ͨ��������Ȩֵ(totalValue)
//�ټ��ϵ�ǰ������ڵݹ飬����DFS�Ĳ����Ϳ���ȷ���ˡ�
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


//DFS()����ֻ����һ����ͨ����������DFSTrave����������Ҫ��ѭ����ʵ��������ͨ����
//�ı���������Ҫ�����Ľ���浽Gang��ȥ 
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


//main����ʵ�����ݵĶ�ȡ��
//1.��ȡ�ַ���ת���ɱ�ż�¼��stringToint�У��Ա��ڽӾ���ͽ����Ϣ�ı�ʾ
//2.����һ���ڽӾ����ʾ��ͼ
//��ȡ֮�������ҵ��������������� 
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
