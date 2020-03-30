#include<iostream>
#include<stdio.h> 
#include<algorithm>
using namespace std;

int father[1010];
//course[i]��ʾϲ��i�Ż�ĵ�һ���˵ı�š��������ϵĸ��ڵ㡱
//coures[i]==0��ʾi�Żû����ϲ�� 
int course[1010]={0}; 
//���isRoot[i]==0��ʾi���˲��Ǹ��ڵ� 
int isRoot[1010]; 

//Ѱ�Ҹ��ڵ� 
int findFather(int x)
{
	int a=x;
	while(x!=father[x])
	{
		x=father[x];
	}
}

//��ʼ�����鼯 
void init(int n)
{
	for(int i=1;i<=n;i++)
	{
		father[i]=i;
		isRoot[i]=0;
	}
}

//�ϲ����� 
void Union(int a,int b)
{
	int faA=findFather(a);
	int faB=findFather(b);
	//ͨ���Ѹ��ڵ㲢�뼯�������ϲ��������� 
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
			//�ж��Ƿ��һ�γ���һ���¼��� 
			if(course[h]==0){
				course[h]=i;
			}
			//�������if�������������ʾh�Ż�Ѿ�����֯
			//ֱ�ӽ�i���˼�����֯��
			//������������������ʱcourse[h]==i
			//iΪ���ڵ� 
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
