#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

vector<int> fac,ans,temp;
int n,k,p,Maxfacsum=-1;

//����x^p 
int power(int x)
{
	int temp=1;
	//p�γ���x 
	for(int i=0;i<p;i++){
		temp=temp*x;
	}
	return temp;
}

//Ԥ����fac����
//fac[0]=0,fac[1]=1,fac[2]=4,fac[3]=9,�±�ͽ����Ӧ 
void init()
{
	int i=0,temp=0;
	while(temp<=n){
		fac.push_back(temp);
		temp=power(++i);
	}
}

void DFS(int index,int nowk,int sum,int facsum){
	if(sum==n&&nowk==k){//�����ǰƽ����Ϊn����ѡ����k�� 
		//�����ʹ���ԭ������� 
		if(facsum>Maxfacsum){
			ans=temp;
			Maxfacsum=facsum; 
		}
		return ;
	}
	//�����ǰƽ���ͻ�������������k��ֱ�ӷ��� 
	if(sum>n||nowk>k) return;
	//����fac[0]�����ǣ���if���˵� 
	if(index-1>=0)
	{
		//ѡ��index�ķ�֧ 
		temp.push_back(index);
		DFS(index,nowk+1,sum+fac[index],facsum+index);
		//��ѡindex�ķ�֧ 
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
