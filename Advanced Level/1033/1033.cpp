#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;

//加油站结构体 
typedef struct {
	float price;//汽油的单价 
	float loc;//加油站距离起点的距离 
}station;

//排序函数，按照到起点的距离排序 
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
	//终点设为单价为零的加油站 
	s[num].loc=D;
	s[num].price=0;
	sort(s,s+num,cmp);
	//如果第一个加油站不在起点，汽车无法获得油，所以不能动 
	if(s[0].loc!=0){
		cout<<"The maximum travel distance = 0.00";
		exit(0);
	}
	int now=0;
	float tank=0,money=0;//油箱一开始没有油；花销一开始为0 
	float MAX=C*pergas;//满箱油能行驶的距离 
	while(now!=num)
	{
		int min=-1;
		float minprice=10000;
		//贪心思想，每个加油站都取局部最优解 
		//找到满箱油里程内油价最便宜的加油站 
		for(int i=now+1;i<=num&&s[i].loc-s[now].loc<=MAX;i++)//注意循环条件满箱油能到达 
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
		float need=(s[min].loc-s[now].loc)/pergas;//走到最低油价加油站的需求油耗 
		if(minprice<s[now].price){//最低价比当前低 
			if(tank<need){//且油箱油不够到达，则加到需求油耗 
				money=money+(need-tank)*s[now].price;
				tank=0; //到达之后油用完 
			} else {
				tank=tank-need;//如果油够则当前加油站不加 
			}
		} else {
			money=money+(C-tank)*s[now].price;//如果当前加油站油价为局部最低则加满 
			tank=C-need;//到达之后油价最低加油站后减去需求油耗 
		}
		now=min;//更新当前加油站 
	}
	if(now==num){
		printf("%.2f",money);
	} else {
		printf("The maximum travel distance = %.2f",s[now].loc+MAX);
	}
}
