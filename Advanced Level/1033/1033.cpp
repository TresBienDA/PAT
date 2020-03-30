#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;

//����վ�ṹ�� 
typedef struct {
	float price;//���͵ĵ��� 
	float loc;//����վ�������ľ��� 
}station;

//�����������յ����ľ������� 
bool cmp(station a,station b)
{
	if(a.loc!=b.loc){
		return a.loc<b.loc;
	}
}

int main()
{
	station s[501];
	float C,D,pergas;
	int num;
	cin>>C>>D>>pergas>>num;
	for(int i=0;i<num;i++)
	{
		cin>>s[i].price>>s[i].loc;
	}
	//�յ���Ϊ����Ϊ��ļ���վ 
	s[num].loc=D;
	s[num].price=0;
	sort(s,s+num,cmp);
	//�����һ������վ������㣬�����޷�����ͣ����Բ��ܶ� 
	if(s[0].loc!=0){
		cout<<"The maximum travel distance = 0.00";
		exit(0);
	}
	int now=0;
	float tank=0,money=0;//����һ��ʼû���ͣ�����һ��ʼΪ0 
	float MAX=C*pergas;//����������ʻ�ľ��� 
	while(now!=num)
	{
		int min=-1;
		float minprice=10000;
		//̰��˼�룬ÿ������վ��ȡ�ֲ����Ž� 
		//�ҵ�������������ͼ�����˵ļ���վ 
		for(int i=now+1;i<=num&&s[i].loc-s[now].loc<=MAX;i++)//ע��ѭ�������������ܵ��� 
		{
			if(s[i].price<minprice){
				min=i;
				minprice=s[i].price;
				if(minprice<s[now].price){
					break;
				}
			}
		}
		if(min==-1) break; 
		float need=(s[min].loc-s[now].loc)/pergas;//�ߵ�����ͼۼ���վ�������ͺ� 
		if(minprice<s[now].price){//��ͼ۱ȵ�ǰ�� 
			if(tank<need){//�������Ͳ��������ӵ������ͺ� 
				money=money+(need-tank)*s[now].price;
				tank=0; //����֮�������� 
			} else {
				tank=tank-need;//����͹���ǰ����վ���� 
			}
		} else {
			money=money+(C-tank)*s[now].price;//�����ǰ����վ�ͼ�Ϊ�ֲ��������� 
			tank=C-need;//����֮���ͼ���ͼ���վ���ȥ�����ͺ� 
		}
		now=min;//���µ�ǰ����վ 
	}
	if(now==num){
		printf("%.2f",money);
	} else {
		printf("The maximum travel distance = %.2f",s[now].loc+MAX);
	}
}
