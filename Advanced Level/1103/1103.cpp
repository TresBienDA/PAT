#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

vector<int> fac,ans,temp;
int n,k,p,Maxfacsum=-1;

//计算x^p 
int power(int x)
{
	int temp=1;
	//p次乘以x 
	for(int i=0;i<p;i++){
		temp=temp*x;
	}
	return temp;
}

//预处理fac数组
//fac[0]=0,fac[1]=1,fac[2]=4,fac[3]=9,下标和结果对应 
void init()
{
	int i=0,temp=0;
	while(temp<=n){
		fac.push_back(temp);
		temp=power(++i);
	}
}

void DFS(int index,int nowk,int sum,int facsum){
	if(sum==n&&nowk==k){//如果当前平方和为n，且选出了k项 
		//底数和大于原来则更新 
		if(facsum>Maxfacsum){
			ans=temp;
			Maxfacsum=facsum; 
		}
		return ;
	}
	//如果当前平方和或者项数超过了k则直接返回 
	if(sum>n||nowk>k) return;
	//这里fac[0]不考虑，用if过滤掉 
	if(index-1>=0)
	{
		//选择index的分支 
		temp.push_back(index);
		DFS(index,nowk+1,sum+fac[index],facsum+index);
		//不选index的分支 
		temp.pop_back();
		DFS(index-1,nowk,sum,facsum);
	}
}




int main()
{
	cin>>n>>k>>p;
	init();
	DFS(fac.size()-1,0,0,0);
	if(Maxfacsum==-1){
		cout<<"Impossible";
	} else {
		printf("%d = %d^%d ",n,ans[0],p);
		for(int i=1;i<ans.size();i++){
			printf("+ %d^%d ",ans[i],p);
		}
	}
	return 0;
}
