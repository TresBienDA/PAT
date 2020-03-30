#include<stdio.h>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

#define Maxsize 1000

typedef struct {
	string sno;
	int d;
	int c;
	int tag;//tag=0 不录取；tag=1 优先录取；tag=2 德胜才； tag=3 德才兼亡但德胜才; tag=4 德才兼亡 
}stu;

bool comp1(const stu &a,const stu &b)
{
	return a.sno<b.sno;
}


bool comp2(const stu &a,const stu &b)
{
	return a.d>b.d;
}

bool comp3(const stu &a,const stu &b)
{
	return a.d+a.c>b.d+b.c;
}

int main()
{
	stu student[Maxsize];
	vector<stu> stu1;
	vector<stu> stu2;
	vector<stu> stu3;
	vector<stu> stu4;
	int N,L,H;
	scanf("%d%d%d",&N,&L,&H);
	for(int i=0;i<N;i++)
	{
		cin>>student[i].sno>>student[i].d>>student[i].c;
		if(student[i].d>=H&&student[i].c>=H){
			student[i].tag=1;
		}
		if(student[i].d>=H&&student[i].c>=L&&student[i].c<H){
			student[i].tag=2;
		}
		if(student[i].d>=L&&student[i].d<H&&student[i].c>=L&&student[i].c<H&&student[i].d>student[i].c){
			student[i].tag=3;
		}
		if(student[i].d>=L&&student[i].d<H&&student[i].c>=L&&student[i].d<=student[i].c){
			student[i].tag=4;
		}
		if(student[i].d<L||student[i].c<L){
			student[i].tag=0;
		}
	}
	cout<<endl;
	//for(int i=0;i<N;i++)
	//{
	//	cout<<student[i].sno<<" "<<student[i].d<<" "<<student[i].c<<" "<<student[i].tag<<endl;
	//}
	for(int i=0;i<N;i++)
	{
		if(student[i].tag==1)
		{
			stu1.push_back(student[i]);
		}
		if(student[i].tag==2)
		{
			stu2.push_back(student[i]);
		}
		if(student[i].tag==3)
		{
			stu3.push_back(student[i]);
		}
		if(student[i].tag==4)
		{
			stu4.push_back(student[i]);
		}
	}
    sort(stu1.begin(),stu1.end(),comp1);
    sort(stu1.begin(),stu1.end(),comp2);
    sort(stu1.begin(),stu1.end(),comp3);
    
    sort(stu2.begin(),stu2.end(),comp1);
    sort(stu2.begin(),stu2.end(),comp2);
    sort(stu2.begin(),stu2.end(),comp3);
    
    sort(stu3.begin(),stu3.end(),comp1);
    sort(stu3.begin(),stu3.end(),comp2);
    sort(stu3.begin(),stu3.end(),comp3);
    
    sort(stu4.begin(),stu4.end(),comp1);
    sort(stu4.begin(),stu4.end(),comp2);
    sort(stu4.begin(),stu4.end(),comp3);
    
    printf("%d\n",stu1.size()+stu2.size()+stu3.size()+stu4.size());
    vector<stu>::iterator it;
    for(it = stu1.begin(); it!=stu1.end();it++)
    {
    	cout<<(*it).sno<<" "<<(*it).d<<" "<<(*it).c<<endl;
    }
    for(it = stu2.begin(); it!=stu2.end();it++)
    {
    	cout<<(*it).sno<<" "<<(*it).d<<" "<<(*it).c<<endl;
    }
    for(it = stu3.begin(); it!=stu3.end();it++)
    {
    	cout<<(*it).sno<<" "<<(*it).d<<" "<<(*it).c<<endl;
    }
    for(it = stu4.begin(); it!=stu4.end()-1;it++)
    {
    	cout<<(*it).sno<<" "<<(*it).d<<" "<<(*it).c<<endl;
    }
    stu p=stu4.back();
    cout<<p.sno<<" "<<p.d<<" "<<p.c;
      
} 
