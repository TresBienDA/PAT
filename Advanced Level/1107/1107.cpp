#include<iostream>
#include<stdio.h> 
#include<algorithm>
using namespace std;

int father[1010];
//course[i]表示喜欢i号活动的第一个人的编号——“集合的根节点”
//coures[i]==0表示i号活动没有人喜欢 
int course[1010]={0}; 
//如果isRoot[i]==0表示i号人不是根节点 
int isRoot[1010]; 

//寻找根节点 
int findFather(int x)
{
	int a=x;
	while(x!=father[x])
	{
		x=father[x];
	}
}

//初始化并查集 
void init(int n)
{
	for(int i=1;i<=n;i++)
	{
		father[i]=i;
		isRoot[i]=0;
	}
}

//合并集合 
void Union(int a,int b)
{
	int faA=findFather(a);
	int faB=findFather(b);
	//通过把根节点并入集合中来合并两个集合 
	if(faA!=faB){
		father[faA]=faB;
	} 
}

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	int n,h,k;
	cin>>n;
	init(n); 
	for(int i=1;i<=n;i++)
	{
		scanf("%d:",&k);
		for(int j=0;j<k;j++)
		{
			cin>>h;
			//判断是否第一次出现一个新集合 
			if(course[h]==0){
				course[h]=i;
			}
			//如果上述if条件不成立则表示h号活动已经有组织
			//直接将i号人加入组织中
			//如果上述条件成立则此时course[h]==i
			//i为根节点 
			Union(i,findFather(course[h]));
		}
	} 
	for(int i=1;i<=n;i++)
	{
		isRoot[findFather(i)]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(isRoot[i]!=0){
			ans++;
		}
	}
	cout<<ans<<endl;
	sort(isRoot+1,isRoot+n+1,cmp);
	for(int i=1;i<=ans;i++)
	{
		cout<<isRoot[i];
		if(i<ans){
			cout<<" ";
		}
	}
} 
